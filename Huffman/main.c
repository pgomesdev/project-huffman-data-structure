#include <locale.h>// BIBLIOTECA DE REGIONALIZAÇÃO DO C (UTILIZADA NO ARQUIVO MAIN)
#include "f_arquivo.h"// Funções para manipular o arquivo .txt ou seu conteúdo
#include "f_arvore.h"// TAD da Árvore de Huffman como Arvore
#include "compactar.h"
#include "descompactar.h"
#include "f_lista.h"// Funções para utilizar a Árvore de Huffman na estrutura de Lista
#include "f_hashtable.h"

//Não recebe parametros, devolve 0 se chegar ao fim do programa e aqui começa a execução do (Des)Compactador
int main()
{
    /// FUNÇÃO QUE DETERMINA A REGIONALIZAÇÃO DO CÓDIGO PARA PADRÃO. ESSENCIAL PARA IMPRIMIR NA TELA CARACTERES ESPECIAIS
    //setlocale(LC_ALL,"");
    puts("\n\n\n");
    puts("---BEM VINDO AO COMPACTADOR DE TEXTOS---");
    puts("\n\n\n");
    puts("Digite:\n");
    puts("1 (para compactar)\n\n");
    puts("2 (para descompactar)\n\n");
    puts("0 (para SAIR)\n\n");
    int compactador = 3;
    while(compactador != 1 && compactador != 2 && compactador != 0)
    {
        scanf("%d", &compactador);
        puts("Tecla Errada, porfavor repita o processo!\n");
        puts("Digite:\n");
        puts("1 (para compactar)\n\n");
        puts("2 (para descompactar)\n\n");
        puts("0 (para SAIR)\n\n");
    }

    if(compactador == 1)
    {
        // String url salva a URL do arquivo texto que será lido
        char url[]="arquivos_txt_para_testes//eulaENU.txt";

        /// A FUNÇÃO "abrir_Arquivo()" RETORNA UM PONTEIRO DO TIPO "FILE", QUE APONTA PARA ARQUIVO.
        FILE *arq = abrir_Arquivo(url);



        /// -x- A PARTIR DESSE PONTO, JÁ TEMOS ACESSO AO ARQUIVO .txt -x-



        ///  SE "abrir_Arquivo()" RETORNAR DIFERENTE DE ZERO, ARQUIVO ABERTO COM SUCESSO.
        if(arq != 0)
        {
            int tam = contar_tam_texto_char(arq);//Calculando o tamanho do texto

            /// LEMBRAR QUE UNSIGNED SERVE PARA UTILIZAR TODOS OS BITS DO CHAR E NÃO PERDER O BIT DE SINAL
            unsigned char txt[tam];//Declarando o array que possui o mesmo tamanho do texto.
            char letra;//Variável condicional da repetição
            int i = 0;//Variável de indice do array txt

            /// OBS.: FOI NECESSARIO ULTILIZAR A FUNÇÃO "rewind()" == "FUNÇÃO QUE REAPONTA "fgetc()" PARA O INICIO DO ARQUIVO."
            /// POIS NA CHAMADA DE "contar_tam_texto_char(arq)" , A FUNÇÃO "fgetc()" ESTAVA APONTANDO PARA O FINAL DO ARQUIVO.
            rewind(arq);

            /// REPETIÇÃO FAZ COPIA DO CONTEUDO DE "arq" PARA BUFFER "txt[]".
            while((letra = fgetc(arq)) != EOF)
            {
                txt[i] = letra;
                i++;
            }
            /// NAO PRECISO MAIS DO ARQUIVO!
            fclose(arq);
            //print_txt(txt,tam);//Verificação do Buffer, deve imprimir o mesmo texto de "url".



            /// -x- A PARTIR DESSE PONTO, JÁ TEMOS O TEXTO DO ARQUIVO .txt SALVO NO BUFFER -x-



            // O ponteiro para Nós cabeca_lista é declarado e inicializado com NULL
            Node *cabeca_lista = criar_Node_NULL();

            /// RECEBEMOS UMA LISTA DE ELEMENTOS QUE CONTEM OS CARACTERES DISTINTOS E A FREQUÊNCIA DELES NO TEXTO
            cabeca_lista = criar_lista_Frequencia(cabeca_lista,txt,tam);
            //print_lista_Frequencia(cabeca_lista);//Verificação da Lista de Huffman, deve ter todos os caracteres distintos.

            puts("\n");



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
            print_pre_ordem_arvore(cabeca_arvore);// Verificação da Árvore de Huffman, deve estar todos os nós em Pré-Ordem
            puts("\n");
            ///freq_x_profundidade e' a multiplicacao da frequencia*profundidade == numero de bits do arquivo compactado.
            unsigned int freq_x_profundidade = calcular_lixo(cabeca_arvore, lixo);

            lixo = freq_x_profundidade % 8;

            /// FAZEMOS A OPERAÇÃO TERNARIA, DE MODO A SALVAR 0, SE NÃO POSSUI LIXO NO ULTIMO BYTE; (8-lixo) SE HOUVER LIXO
            lixo = lixo != 0 ? (8 - lixo): 0 ;

            /// A VÁRIAVEL tamanho_arvore RECEBE A QUANTIDADE DE NÓS NA ARVORE DE HUFFMAN
            tamanho_arvore = calcular_tam_arvore(cabeca_arvore, tamanho_arvore);

            //printf("LIXO: %d \n",lixo);
            //printf("TAM_ARVORE: %d \n",tamanho_arvore);

            /// -x- A PARTIR DESSE PONTO, JÁ TEMOS A ARVORE DE HUFFMAN E AS INFORMAÇÕES DO CABEÇALHO. -x-



            puts("\n");
            Hashtable *ht = create_hashtable();
            Element *lista = criar_node_hash_null();

            construir_ht(cabeca_arvore,lista,ht);

            //print_ht(ht);// imprime a hash criada baseada na arvore

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

            for(i = 0 ; i<freq_x_profundidade; i++)
            {
                printf("[%d]",array_binario[i]);
            }



            FILE *novo_arquivo = fopen("arquivo.huff", "w");

            unsigned short cabecalho_inicial = {(converter_lixo(lixo) + tamanho_arvore)};

            escrever_cabecalho_inicio(cabecalho_inicial, novo_arquivo);
            escrever_arvore(cabeca_arvore, novo_arquivo);
            escrever_texto(array_binario, freq_x_profundidade, novo_arquivo);

            fclose(novo_arquivo);

            ht = remove_hashtable(ht);//remove_hashtable da um free() em todas as listas da hash e na propia hash
            cabeca_arvore = remove_arvore(cabeca_arvore);//remove_arvore da um free() na arvore inteira.

        }
        main();
    }
    else if(compactador == 2)
    {
        FILE *arquivo_huff = fopen("arquivo.huff","r");

        unsigned char lixo = obter_lixo(arquivo_huff);

        unsigned short int tam_array_arvore = obter_tamanho_arvore(arquivo_huff);

        unsigned char array_arvore[tam_array_arvore];

        obter_arvore(array_arvore,arquivo_huff);

        printf("LIXO: %d \n",lixo);
        printf("TAM_ARVORE: %d \n",tam_array_arvore);

        Node *cabeca_arvore = criar_Node_NULL();

        cabeca_arvore = criar_arvore_descompactacao(cabeca_arvore, array_arvore, tam_array_arvore);

        print_pre_ordem_arvore(cabeca_arvore);

        unsigned int tam_array_binarios_descompactar = contar_tamanho_array_binarios_descompactar(arquivo_huff, (2+tam_array_arvore));

        unsigned short array_binarios_descompactar[tam_array_binarios_descompactar];

        printf("\ntam_array_binarios_descompactar:[%d]",tam_array_binarios_descompactar);
        int i;

        rewind(arquivo_huff);
        escrever_array_compactado(arquivo_huff, array_binarios_descompactar, tam_array_binarios_descompactar, (2+tam_array_arvore));
        printf("%d",tam_array_binarios_descompactar);

        for(i = 0; i<tam_array_binarios_descompactar ; i++)
        {
            printf("[%d]",array_binarios_descompactar[i]);
        }

        fclose(arquivo_huff);

        FILE *arquivo_txt = fopen("arquivo.txt", "w+");

        descompactar_texto(cabeca_arvore, array_binarios_descompactar, arquivo_txt, tam_array_binarios_descompactar-lixo);

        fclose(arquivo_txt);

        cabeca_arvore = remove_arvore(cabeca_arvore);

        main();
    }
    else if(compactador == 0)
    {
        exit(0);
    }

}

