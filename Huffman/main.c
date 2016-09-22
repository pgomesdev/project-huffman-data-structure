#include "f_arquivo.h"
#include "f_arvore.h"
#include "compactar.h"

int main()
{
    setlocale(LC_ALL,"");

    /// ENCURTA ENDEREÇO DO ARQUIVO PARA VARIAVEL "url"
    char url[]="C:\Users\Datsu\Documents\Huffman_P2\Huffman\arquivos_txt_para_testes";

    /// A FUNÇÃO "abrir_Arquivo()" RETORNA UM PONTEIRO DO TIPO "FILE", E AGORA "arq" APONTA PARA ARQUIVO.
    FILE *arq = abrir_Arquivo(url);

    ///  SE "abrir_Arquivo()" RETORNAR DIFERENTE DE ZERO, ARQUIVO ABERTO COM SUCESSO.
    if(arq != 0)
    {
        int tam = contar_tam_texto_char(arq);

        char txt[tam];
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

        Node *cabeca = criar_Node_NULL();
        cabeca = criar_lista_Frequencia(cabeca,txt,tam);
        print_lista(cabeca);

        cabeca = criar_arvore_huffman(cabeca);
    }

    FILE *novo_arquivo = fopen("arquivo.huff", "w+x");

    unsigned short cabecalho_inicial = {(converter_lixo(lixo) + tamanho_arvore)};

    escrever_cabecalho_inicio(cabecalho_inicial, novo_arquivo);
    escrever_arvore(arvore, tamanho_arvore, novo_arquivo);
    escrever_texto(texto, tamanho_texto, novo_arquivo);
    fclose(novo_arquivo);

    return 0;
}

