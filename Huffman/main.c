#include "f_arquivo.h"
#include "f_arvore.h"
#include "compactar.h"
#include "descompactar.h"
#include "f_lista.h"

int main()
{
    setlocale(LC_ALL,"");

    /// ENCURTA ENDEREÇO DO ARQUIVO PARA VARIAVEL "url"
    char url[]="arquivos_txt_para_testes\\exemplo.txt";

    /// A FUNÇÃO "abrir_Arquivo()" RETORNA UM PONTEIRO DO TIPO "FILE", E AGORA "arq" APONTA PARA ARQUIVO.
    FILE *arq = abrir_Arquivo(url);

    ///  SE "abrir_Arquivo()" RETORNAR DIFERENTE DE ZERO, ARQUIVO ABERTO COM SUCESSO.
    if(arq != 0)
    {
        int tam = contar_tam_texto_char(arq);
        unsigned char txt[tam];
        char letra;
        int i = 0;

        /// OBS.: FOI NECESSARIO ULTILIZAR A FUNÇÃO "rewind()" == "FUNÇÃO QUE REAPONTA "fgetc()" PARA O INICIO DO ARQUIVO."
        /// POIS NA CHAMADA DE "contar_tam_texto_char(arq)" , A FUNÇÃO "fgetc()" ESTAVA APONTANDO PARA O FINAL DO ARQUIVO.
        rewind(arq);
        /// FAZENDO COPIA DO CONTEUDO DE "arq" PARA BUFFER "txt[]".
        while((letra = fgetc(arq)) != EOF)
        {
            txt[i] = letra;
            i++;
        }
        /// NAO PRECISO MAIS DO ARQUIVO!
        fclose(arq);
        print_txt(txt,tam);

        Node *cabeca_lista = criar_Node_NULL();
        cabeca_lista = criar_lista_Frequencia(cabeca_lista,txt,tam);
        print_lista_Frequencia(cabeca_lista);

        puts("\n");

        unsigned short lixo = 0;
        unsigned short tamanho_arvore = 0;

        Node *cabeca_arvore = cabeca_lista;
        cabeca_arvore = criar_arvore_huffman(cabeca_arvore);
        calcular_profundidade_nodes(cabeca_arvore,cabeca_arvore->profundidade);
        print_pre_ordem_arvore(cabeca_arvore);

        lixo = calcular_lixo(cabeca_arvore, lixo);
        lixo = lixo != 0 ? (8 - lixo): 0 ;
        tamanho_arvore = calcular_tam_arvore(cabeca_arvore, tamanho_arvore);

        print_lista_Frequencia(cabeca_lista);
        puts("\n");
        //lista_de_folhas(cabeca_lista);

        //print_lista_Frequencia(cabeca_lista);

        /*FILE *novo_arquivo = fopen("arquivo.huff", "w+x");

        unsigned short cabecalho_inicial = {(converter_lixo(lixo) + tamanho_arvore)};

        escrever_cabecalho_inicio(cabecalho_inicial, novo_arquivo);
        escrever_arvore(cabeca_arvore, novo_arquivo);
        escrever_texto(texto, tamanho_texto, novo_arquivo);
        fclose(novo_arquivo);*/
    }

    return 0;
}

