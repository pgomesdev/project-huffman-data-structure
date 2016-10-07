#include <locale.h>// BIBLIOTECA DE REGIONALIZAÇÃO DO C (UTILIZADA NO ARQUIVO MAIN)
#include "f_arquivo.h"// Funções para manipular o arquivo .txt ou seu conteúdo
#include "f_arvore.h"// TAD da Árvore de Huffman como Arvore
#include "compactar.h"// Funções diversas para a compactação
#include "descompactar.h"// Funções diversas para a compactação
#include "f_lista.h"// Funções para utilizar a Árvore de Huffman na estrutura de Lista
#include "f_hashtable.h"// TAD de Tabela de Dispersão

//Não recebe parametros, devolve 0 se chegar ao fim do programa e aqui começa a execução do (Des)Compactador
int main()
{
    /// FUNÇÃO QUE DETERMINA A REGIONALIZAÇÃO DO CÓDIGO PARA PADRÃO. ESSENCIAL PARA IMPRIMIR NA TELA CARACTERES ESPECIAIS
    //setlocale(LC_ALL,"");
    
    /// ESPERA UMA AÇÃO DO USUÁRIO.
    
    int compactador;
    
    puts("\n\n\n");
    puts("---BEM VINDO AO COMPACTADOR DE TEXTOS---");
    puts("\n\n\n");
    puts("Digite:\n");
    puts("1 (para compactar)\n\n");
    puts("2 (para descompactar)\n\n");
    puts("0 (para SAIR)\n\n");
    

    scanf("%d", &compactador);

    while(compactador > 2 || compactador < 0)//Enquanto o valor digitado não for válido, leia novamente
    {
        puts("\n\nTecla Errada, porfavor repita o processo!\n");
        puts("Digite:\n");
        puts("1 (para compactar)\n\n");
        puts("2 (para descompactar)\n\n");
        puts("0 (para SAIR)\n\n");
        scanf("%d", &compactador);
    }

    //Se o usuário digitar 1, escolhendo a compressão:
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
            unsigned long long int tam = contar_tam_texto_char(arq);//Calculando o tamanho do texto

            /// LEMBRAR QUE UNSIGNED SERVE PARA UTILIZAR TODOS OS BITS DO CHAR E NÃO PERDER O BIT DE SINAL
            unsigned char txt[tam];//Declarando o array que possui o mesmo tamanho do texto.

            char letra;//Variável condicional da repetição
            unsigned long long int i = 0;//Variável de indice do array txt

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
            
            
            
            /// -x- A PARTIR DESSE PONTO, JÁ TEMOS O TEXTO DO ARQUIVO .txt SALVO NO BUFFER -x-



            // O ponteiro para Nós cabeca_lista é declarado e inicializado com NULL
            Node *cabeca_lista = criar_Node_NULL();

            /// RECEBEMOS UMA LISTA DE ELEMENTOS QUE CONTEM OS CARACTERES DISTINTOS E A FREQUÊNCIA DELES NO TEXTO
            cabeca_lista = criar_lista_Frequencia(cabeca_lista, txt, tam);



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
            
            /// freq_x_profundidade E' O NUMERO DE BITS DO ARQUIVO COMPACTADO.
            unsigned long long int freq_x_profundidade = calcular_lixo(cabeca_arvore, lixo);

            /// LIXO RECEBE A QUANTIDADE DE BITS SIGNIFICATIVOS DO ULTIMO BYTE.
            lixo = freq_x_profundidade % 8;

            /// FAZEMOS A OPERAÇÃO TERNARIA, DE MODO A SALVAR 0, SE NÃO POSSUI LIXO NO ULTIMO BYTE; (8-lixo) SE HOUVER LIXO
            lixo = lixo != 0 ? (8 - lixo): 0 ;

            /// A VÁRIAVEL tamanho_arvore RECEBE A QUANTIDADE DE NÓS NA ARVORE DE HUFFMAN
            tamanho_arvore = calcular_tam_arvore(cabeca_arvore, tamanho_arvore);


            
            /// -x- A PARTIR DESSE PONTO, JÁ TEMOS A ARVORE DE HUFFMAN E AS INFORMAÇÕES DO CABEÇALHO. -x-

            

            Hashtable *ht = create_hashtable();//Cria a Tabela com a codificação, onde cada chave é inicializada com NULL
            Element *lista = criar_node_hash_null();//Cria um ponteiro para Element, inicializando com NULL.

            /// ESCREVE NA TABELA DE DISPERSÃO, NA CHAVE DO CARACTERE, A SEQUÊNCIA DE BITS CORRESPONDENTE A COMPRESSÃO
            construir_ht(cabeca_arvore,lista,ht);

            /// VERIFICAÇÃO DA FUNÇÃO ANTERIOR
            if(lista == NULL)// Se lista == NULL , então a funcao construir_ht foi executada com sucesso.
            {
                puts("construir_ht OK!!");
            }
            else
            {
                puts("construir_ht nao concluido\n");
            }
            
            unsigned short array_binario[freq_x_profundidade];//Declara o array que receberá os bits compactados.

            /// ESCREVE NO array_binario O TEXTO CODIFICADO DE ACORDO COM A ARVORE PASSADA
            criar_array_binarios(ht, txt, tam, array_binario, freq_x_profundidade);
            
            
            
            ///-x- A PARTIR DESSE PONTO, JÁ TEMOS TODAS AS INFORMAÇÕES DO ARQUIVO .huff . -x-

            
            
            /// CRIA UM NOVO ARQUIVO PARA RECEBER A COMPACTAÇÃO
            FILE *novo_arquivo = fopen("arquivos_txt_para_testes//arquivo_compactado.huff", "w");

            /// CRIA OS DOIS PRIMEIROS BYTES, DE ACORDO COM A ESPECIFICAÇÃO DO CABEÇALHO
            unsigned short cabecalho_inicial = {(converter_lixo(lixo) + tamanho_arvore)};

            /// ESCREVE OS 2 PRIMEIROS BYTES, A ARVORE E O TEXTO CODIFICADO
            escrever_cabecalho_inicio(cabecalho_inicial, novo_arquivo);
            escrever_arvore(cabeca_arvore, novo_arquivo);
            escrever_texto(array_binario, freq_x_profundidade, novo_arquivo);

            fclose(novo_arquivo);//Fecha o arquivo

            ht = remove_hashtable(ht);// Desaloca o espaço utilizado para Tabela de Dispersão.
            cabeca_arvore = remove_arvore(cabeca_arvore);// Desaloca o espaço utilizado para Arvore de Huffman.

            puts("\n\nArquivo compactado com sucesso!\n");//Mensagem de Finalização

        }
        main();// Retorna para o inicio da função, como uma função recursiva!
    }
    //Se o usuário digitar 2, escolhendo a descompressão:
    else if(compactador == 2)
    {
        FILE *arquivo_huff = fopen("arquivos_txt_para_testes//arquivo_compactado.huff","r");

        unsigned char lixo = obter_lixo(arquivo_huff);

        unsigned short tam_array_arvore = obter_tamanho_arvore(arquivo_huff);

        unsigned char array_arvore[tam_array_arvore];

        obter_arvore(array_arvore,arquivo_huff);

        Node *cabeca_arvore = criar_Node_NULL();

        cabeca_arvore = criar_arvore_descompactacao(cabeca_arvore, array_arvore, tam_array_arvore);

        unsigned long long int tam_array_binarios_descompactar = contar_tamanho_array_binarios_descompactar(arquivo_huff, (2+tam_array_arvore));

        unsigned short array_binarios_descompactar[tam_array_binarios_descompactar];

        rewind(arquivo_huff);
        escrever_array_compactado(arquivo_huff, array_binarios_descompactar, tam_array_binarios_descompactar, (2+tam_array_arvore));

        fclose(arquivo_huff);

        FILE *arquivo_txt = fopen("arquivos_txt_para_testes//arquivo_descompactado.txt", "w+");

        descompactar_texto(cabeca_arvore, array_binarios_descompactar, arquivo_txt, tam_array_binarios_descompactar-lixo);

        fclose(arquivo_txt);

        cabeca_arvore = remove_arvore(cabeca_arvore);

        puts("\n\nArquivo descompactado com sucesso!");

        main();
    }
    //Se o usuário digitar 0, escolhendo sair do programa:
    else if(compactador == 0)
    {
        return 0;
    }

    return 0;
}

