#include "f_arvore.h"// TAD da Árvore de Huffman como Arvore
#include "compactar.h"
#include "descompactar.h"
#include "f_lista.h"// Funções para utilizar a Árvore de Huffman na estrutura de Lista
#include "f_hashtable.h"

//Não recebe parametros, devolve 0 se chegar ao fim do programa e aqui começa a execução do (Des)Compactador
int main()
{
    puts("\n\n\n");
    puts("---BEM VINDO AO COMPACTADOR DE TEXTOS---");
    puts("\n\n\n");
    puts("Digite:\n");
    puts("1 (para compactar)\n\n");
    puts("2 (para descompactar)\n\n");
    puts("0 (para SAIR)\n\n");
    int compactador;

    scanf("%d", &compactador);

    while(compactador > 2 || compactador < 0)
    {
        puts("\n\nTecla Errada, porfavor repita o processo!\n");
        puts("Digite:\n");
        puts("1 (para compactar)\n\n");
        puts("2 (para descompactar)\n\n");
        puts("0 (para SAIR)\n\n");
        scanf("%d", &compactador);
    }


    if(compactador == 1)
    {
        // String url salva a URL do arquivo texto que será lido
        char url[]="arquivos_txt_para_testes//eulaENU.txt";

        /// A FUNÇÃO "abrir_Arquivo()" RETORNA UM PONTEIRO DO TIPO "FILE", QUE APONTA PARA ARQUIVO.
        FILE *arq = abrir_Arquivo(url);
        FILE *arq = fopen(url, "r");

        if(arq == NULL)
        {
            printf("Erro, nao foi possivel abrir o arquivo\n");
            return 0;
        }

        /// -x- A PARTIR DESSE PONTO, JÁ TEMOS ACESSO AO ARQUIVO .txt -x-



        ///  SE "abrir_Arquivo()" RETORNAR DIFERENTE DE ZERO, ARQUIVO ABERTO COM SUCESSO.
        if(arq != 0)
        {
            // O ponteiro para Nós cabeca_lista é declarado e inicializado com NULL
            Node *cabeca_lista = criar_Node_NULL();

            /// RECEBEMOS UMA LISTA DE ELEMENTOS QUE CONTEM OS CARACTERES DISTINTOS E A FREQUÊNCIA DELES NO TEXTO
            cabeca_lista = criar_lista_Frequencia(cabeca_lista, arq);

            /// -x- A PARTIR DESSE PONTO, JÁ TEMOS A LISTA DE HUFFMAN. -x-

            /// UTILIZAMOS UNSIGNED PARA NÃO PERDER O BIT DO SINAL.
            /// JÁ O SHORT, POIS ELE UTILIZA 2 BYTES PARA ARMAZENAR VALORES, EXATAMENTE OS 2 BYTES INICIAIS DO CABEÇALHO
            unsigned short lixo = 0;// Variável para armazenar quantos bits do último byte não serão significativos.
            unsigned short tamanho_arvore = 0;// Variável para armazenar quantos nós tem na arvore de Huffman.

            Node *cabeca_arvore = cabeca_lista;//Criamos uma váriavel que aponta para o inicio da Lista

            /// AGORA O PONTEIRO cabeca_arvore RECEBE A ARVORE DE HUFFMAN, GERADA A PARTIR DA LISTA ANTERIOR
            cabeca_arvore = criar_arvore_huffman(cabeca_arvore);

            /// CALCULA A PROFUNDIDADE DE CADA NÓ DA ARVORE E SALVA NA ESTRUTURA DO NÓ DE HUFFMAN
            calcular_profundidade_nodes(cabeca_arvore,cabeca_arvore->profundidade);

            ///freq_x_profundidade e' a multiplicacao da frequencia*profundidade == numero de bits do arquivo compactado.
            unsigned long long int freq_x_profundidade = calcular_lixo(cabeca_arvore, lixo);

            lixo = freq_x_profundidade % 8;

            /// FAZEMOS A OPERAÇÃO TERNARIA, DE MODO A SALVAR 0, SE NÃO POSSUI LIXO NO ULTIMO BYTE; (8-lixo) SE HOUVER LIXO
            lixo = lixo != 0 ? (8 - lixo): 0 ;

            /// A VÁRIAVEL tamanho_arvore RECEBE A QUANTIDADE DE NÓS NA ARVORE DE HUFFMAN
            tamanho_arvore = calcular_tam_arvore(cabeca_arvore, tamanho_arvore);


            /// -x- A PARTIR DESSE PONTO, JÁ TEMOS A ARVORE DE HUFFMAN E AS INFORMAÇÕES DO CABEÇALHO. -x-


            Hashtable *ht = create_hashtable();
            Element *lista = criar_node_hash_null();

            construir_ht(cabeca_arvore,lista,ht);

            ///Se lista == NULL , então a funcao construir_ht foi execultada com sucesso.
            if(lista == NULL)
            {
                puts("construir_ht OK!!");
            }
            else
            {
                puts("construir_ht nao concluido\n");
            }
            unsigned short array_binario[freq_x_profundidade];

            criar_array_binarios(ht, txt, tam, array_binario, freq_x_profundidade);

            FILE *novo_arquivo = fopen("arquivos_txt_para_testes//arquivo_compactado.huff", "w");

            unsigned short cabecalho_inicial = {(converter_lixo(lixo) + tamanho_arvore)};

            escrever_cabecalho_inicio(cabecalho_inicial, novo_arquivo);
            escrever_arvore(cabeca_arvore, novo_arquivo);
            escrever_texto(array_binario, freq_x_profundidade, novo_arquivo);

            fclose(novo_arquivo);

            ht = remove_hashtable(ht);//remove_hashtable da um free() em todas as listas da hash e na propia hash
            cabeca_arvore = remove_arvore(cabeca_arvore);//remove_arvore da um free() na arvore inteira.

            puts("\n\nArquivo compactado com sucesso!\n");

        }
        main();
    }
    else if(compactador == 2)
    {
        FILE *arquivo_huff = fopen("arquivos_txt_para_testes//arquivo_compactado.huff","r");

        unsigned char lixo = obter_lixo(arquivo_huff);

        rewind(arquivo_huff);

        unsigned short tam_array_arvore = obter_tamanho_arvore(arquivo_huff);

        unsigned char array_arvore[tam_array_arvore];

        obter_arvore(array_arvore,arquivo_huff);

        Node *cabeca_arvore = criar_Node_NULL();

        cabeca_arvore = criar_arvore_descompactacao(cabeca_arvore, array_arvore, tam_array_arvore);

        unsigned long long int tam_array_binarios_descompactar = contar_tamanho_array_binarios_descompactar(arquivo_huff);

        unsigned short array_binarios_descompactar[tam_array_binarios_descompactar];

        rewind(arquivo_huff);

        int i;

        for(i = 0; i < tam_array_arvore + 2; i++)
            fgetc(arquivo_huff);

        escrever_array_compactado(arquivo_huff, array_binarios_descompactar, tam_array_binarios_descompactar);

        fclose(arquivo_huff);

        FILE *arquivo_txt = fopen("arquivos_txt_para_testes//arquivo_descompactado.txt", "w+");

        descompactar_texto(cabeca_arvore, array_binarios_descompactar, arquivo_txt, tam_array_binarios_descompactar-lixo);

        fclose(arquivo_txt);

        cabeca_arvore = remove_arvore(cabeca_arvore);

        puts("\n\nArquivo descompactado com sucesso!");

        main();
    }
    else if(compactador == 0)
    {
        return 0;
    }

    return 0;
}

