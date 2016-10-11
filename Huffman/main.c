#include "f_arvore.h"// TAD da Árvore de Huffman como Arvore
<<<<<<< HEAD
#include "compactar.h"// Funções diversas para a compactação
#include "descompactar.h"// Funções diversas para a compactação
#include "f_lista.h"// Funções para utilizar a Árvore de Huffman na estrutura de Lista
#include "f_hashtable.h"// TAD de Tabela de Dispersão
=======
#include "compactar.h"
#include "descompactar.h"
#include "fila_prioridade.h"// Funções para utilizar a Árvore de Huffman na estrutura de Lista
#include "f_hashtable.h"
>>>>>>> optimize

//Não recebe parametros, devolve 0 se chegar ao fim do programa e aqui começa a execução do (Des)Compactador
int main()
{
<<<<<<< HEAD
    /// FUNÇÃO QUE DETERMINA A REGIONALIZAÇÃO DO CÓDIGO PARA PADRÃO. ESSENCIAL PARA IMPRIMIR NA TELA CARACTERES ESPECIAIS
    //setlocale(LC_ALL,"");

    /// ESPERA UMA AÇÃO DO USUÁRIO.

    int compactador;

=======
>>>>>>> optimize
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

<<<<<<< HEAD
    //Se o usuário digitar 1, escolhendo a compressão:
=======
>>>>>>> optimize
    if(compactador == 1)
    {
        // String url salva a URL do arquivo texto que será lido
        char url[]="arquivos_txt_para_testes//eulaENU.txt";

<<<<<<< HEAD
        /// A FUNÇÃO "abrir_Arquivo()" RETORNA UM PONTEIRO DO TIPO "FILE", QUE APONTA PARA ARQUIVO.
        FILE *arquivo_texto = fopen(url, "r");

        if(arquivo_texto == NULL)
=======
        FILE *arquivo_compactar = fopen(url, "r");

        if(arquivo_compactar == NULL)
>>>>>>> optimize
        {
            printf("Erro, nao foi possivel abrir o arquivo\n");
            return 0;
        }

        /// -x- A PARTIR DESSE PONTO, JÁ TEMOS ACESSO AO ARQUIVO .txt -x-

        ///  SE "abrir_Arquivo()" RETORNAR DIFERENTE DE ZERO, ARQUIVO ABERTO COM SUCESSO.
        if(arquivo_compactar != 0)
        {
            // O ponteiro para Nós cabeca_lista é declarado e inicializado com NULL
            Node *cabeca_lista = criar_no_nulo();

            /// RECEBEMOS UMA LISTA DE ELEMENTOS QUE CONTEM OS CARACTERES DISTINTOS E A FREQUÊNCIA DELES NO TEXTO
<<<<<<< HEAD
            cabeca_lista = criar_lista_frequencia(cabeca_lista, arquivo_texto);
=======
            cabeca_lista = criar_lista_frequencia(arquivo_compactar);
>>>>>>> optimize

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
<<<<<<< HEAD
=======

            ///freq_x_profundidade e' a multiplicacao da frequencia*profundidade == numero de bits do arquivo compactado.
            unsigned long long int freq_x_profundidade = calcular_tamanho_texto(cabeca_arvore, lixo);
>>>>>>> optimize

            /// freq_x_profundidade E' O NUMERO DE BITS DO ARQUIVO COMPACTADO.
            unsigned long long int freq_x_profundidade = calcular_tamanho_texto(cabeca_arvore, lixo);

            /// LIXO RECEBE A QUANTIDADE DE BITS SIGNIFICATIVOS DO ULTIMO BYTE.
            lixo = freq_x_profundidade % 8;

            /// FAZEMOS A OPERAÇÃO TERNARIA, DE MODO A SALVAR 0, SE NÃO POSSUI LIXO NO ULTIMO BYTE; (8-lixo) SE HOUVER LIXO
            lixo = lixo != 0 ? (8 - lixo): 0 ;

            /// A VÁRIAVEL tamanho_arvore RECEBE A QUANTIDADE DE NÓS NA ARVORE DE HUFFMAN
            tamanho_arvore = calcular_tam_arvore(cabeca_arvore, tamanho_arvore);

            /// -x- A PARTIR DESSE PONTO, JÁ TEMOS A ARVORE DE HUFFMAN E AS INFORMAÇÕES DO CABEÇALHO. -x-

            Elemento *hash[256] = {NULL};//Cria um ponteiro para Element, inicializando com NULL.

            /// ESCREVE NA TABELA DE DISPERSÃO, NA CHAVE DO CARACTERE, A SEQUÊNCIA DE BITS CORRESPONDENTE A COMPRESSÃO
            construir_hash(cabeca_arvore, hash);

            unsigned short array_binario[freq_x_profundidade];//Declara o array que receberá os bits compactados.

            /// ESCREVE NO array_binario O TEXTO CODIFICADO DE ACORDO COM A ARVORE PASSADA
            criar_array_binarios(arquivo_texto, hash, array_binario, freq_x_profundidade);

<<<<<<< HEAD
            ///-x- A PARTIR DESSE PONTO, JÁ TEMOS TODAS AS INFORMAÇÕES DO ARQUIVO .huff . -x-
=======
            criar_array_binarios(ht, array_binario, freq_x_profundidade);
>>>>>>> optimize

            /// CRIA UM NOVO ARQUIVO PARA RECEBER A COMPACTAÇÃO
            FILE *novo_arquivo = fopen("arquivos_txt_para_testes//arquivo_compactado.huff", "w");

            /// CRIA OS DOIS PRIMEIROS BYTES, DE ACORDO COM A ESPECIFICAÇÃO DO CABEÇALHO
            unsigned short cabecalho_inicial = {(converter_lixo(lixo) + tamanho_arvore)};

            /// ESCREVE OS 2 PRIMEIROS BYTES, A ARVORE E O TEXTO CODIFICADO
            escrever_cabecalho_inicio(cabecalho_inicial, novo_arquivo);
            escrever_arvore(cabeca_arvore, novo_arquivo);
            escrever_texto(novo_arquivo, array_binario, freq_x_profundidade);

            fclose(novo_arquivo);//Fecha o arquivo

            ht = remove_hashtable(ht);// Desaloca o espaço utilizado para Tabela de Dispersão.
            cabeca_arvore = remove_arvore(cabeca_arvore);// Desaloca o espaço utilizado para Arvore de Huffman.

            fclose(arquivo_texto);

            puts("\n\nArquivo compactado com sucesso!\n");//Mensagem de Finalização

        }
        main();// Retorna para o inicio da função, como uma função recursiva!
    }
    //Se o usuário digitar 2, escolhendo a descompressão:
    else if(compactador == 2)
    {
        /// ABRE O ARQUIVO .huff NA MESMA PASTA
        FILE *arquivo_huff = fopen("arquivos_txt_para_testes//arquivo_compactado.huff","r");

        /// SALVA EM lixo QUANTOS BITS DO ULTIMO BYTE NÃO SÃO SIGNIFICATIVOS
        unsigned char lixo = obter_lixo(arquivo_huff);

<<<<<<< HEAD
        /// SALVA EM tam_array_arvore QUANTOS ELEMENTOS ESTÃO NA ARVORE DE HUFFMAN
=======
        rewind(arquivo_huff);

>>>>>>> optimize
        unsigned short tam_array_arvore = obter_tamanho_arvore(arquivo_huff);

        unsigned char array_arvore[tam_array_arvore];//Declara um array para receber os caracteres da arvore

        /// ESCREVE NO array_arvore OS CARACTERES DA ARVORE DE HUFFMAN
        obter_arvore(array_arvore,arquivo_huff);

<<<<<<< HEAD
        Node *cabeca_arvore = criar_Node_NULL();// Cria um ponteiro inicializado com NULL
=======
        Node *cabeca_arvore = criar_no_nulo();
>>>>>>> optimize

        /// cabeca_arvore APONTA PARA RAIZ DA ARVORE DE HUFFMAN NOVA
        cabeca_arvore = criar_arvore_descompactacao(cabeca_arvore, array_arvore, tam_array_arvore);

<<<<<<< HEAD
        /// CALCULA A QUANTIDADE DE BITS DO ARQUIVO TIRANDO O CABEÇALHO
        unsigned long long int tam_array_binarios_descompactar = contar_tamanho_array_binarios_descompactar(arquivo_huff, (2+tam_array_arvore));
=======
        unsigned long long int tam_array_binarios_descompactar = contar_tamanho_array_binarios_descompactar(arquivo_huff);
>>>>>>> optimize

        unsigned short array_binarios_descompactar[tam_array_binarios_descompactar];//Declara o array de bits compactados

        rewind(arquivo_huff);//Retorna ao começo do arquivo_huff

<<<<<<< HEAD
        /// O array_binarios_descompactar RECEBE EM CADA POSIÇÃO, UM BIT DO TEXTO COMPACTADO
        escrever_array_compactado(arquivo_huff, array_binarios_descompactar, tam_array_binarios_descompactar, (2+tam_array_arvore));
=======
        rewind(arquivo_huff);

        int i;

        for(i = 0; i < tam_array_arvore + 2; i++)
            fgetc(arquivo_huff);

        escrever_array_compactado(arquivo_huff, array_binarios_descompactar, tam_array_binarios_descompactar);
>>>>>>> optimize

        /// NÃO PRECISO MAIS DO ARQUIVO
        fclose(arquivo_huff);

        /// CRIA UM ARQUIVO .txt
        FILE *arquivo_txt = fopen("arquivos_txt_para_testes//arquivo_descompactado.txt", "w+");

<<<<<<< HEAD
        /// ESCREVE O TEXTO CORRESPONDENTE AO ARQUIVO COMPACTADO
        descompactar_texto(cabeca_arvore, array_binarios_descompactar, arquivo_txt, tam_array_binarios_descompactar-lixo);
=======
        descompactar_texto(arquivo_txt, cabeca_arvore, array_binarios_descompactar, tam_array_binarios_descompactar-lixo);
>>>>>>> optimize

        /// O ARQUIVO ESTÁ COMPLETO.
        fclose(arquivo_txt);

        cabeca_arvore = remove_arvore(cabeca_arvore);// Desaloca a memória utilizada para Arvore

        puts("\n\nArquivo descompactado com sucesso!");// Mensagem de Finalização

        main();// Retorna para o inicio da função, como uma função recursiva!
    }
    //Se o usuário digitar 0, escolhendo sair do programa:
    else if(compactador == 0)
    {
        return 0;
    }

    return 0;
}

