#include <locale.h>// BIBLIOTECA DE REGIONALIZAÇÃO DO C (UTILIZADA NO ARQUIVO MAIN)
#include "f_arquivo.h"// Funções para manipular o arquivo .txt ou seu conteúdo
#include "f_arvore.h"// TAD da Árvore de Huffman como Arvore
#include "compactar.h"// Funções diversas para a compactação
#include "descompactar.h"// Funções diversas para a compactação
#include "f_lista.h"// Funções para utilizar a Árvore de Huffman na estrutura de Lista
#include "f_hashtable.h"// TAD de Tabela de Dispersão
#include "f_md5.h"
#include "f_md5_descompactar.h"

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
        char url[1000];
        puts("Digite a url do arquivo a ser compactado!:");
        scanf("%s",url);

        unsigned char nome_ex[6];
        unsigned char nome_arquivo[256];
        obter_nome_ext_arq(url, nome_ex, nome_arquivo);
        unsigned char tam_arquivo = calcular_tam_nome_arq(nome_arquivo);
        unsigned char tam_extencao = calcular_tam_ext(nome_ex);

        /// A FUNÇÃO "abrir_Arquivo()" RETORNA UM PONTEIRO DO TIPO "FILE", QUE APONTA PARA ARQUIVO.
        FILE *arq = abrir_Arquivo(url);


        /// -x- A PARTIR DESSE PONTO, JÁ TEMOS ACESSO AO ARQUIVO .txt -x-



        ///  SE "abrir_Arquivo()" RETORNAR DIFERENTE DE ZERO, ARQUIVO ABERTO COM SUCESSO.
        if(arq != 0)
        {
            Hash_Freq *hf = criar_array_freq();

            Hash_Freq *novo_hf = criar_array_freq();

            contar_freq_char(arq, hf);

            short tam_novo_hf = tam__novo_hf(hf);

            criar_novo_hf(hf, novo_hf, tam_novo_hf);

            Quick_Sort(novo_hf,0, tam_novo_hf-1);

            Node *cabeca_lista = criar_lista_huffman(novo_hf, tam_novo_hf);

            // O ponteiro para Nós cabeca_lista é declarado e inicializado com NULL


            /// RECEBEMOS UMA LISTA DE ELEMENTOS QUE CONTEM OS CARACTERES DISTINTOS E A FREQUÊNCIA DELES NO TEXTO




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
            unsigned long long int freq_x_profundidade = calcular_array_b(cabeca_arvore, lixo);


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
            if(lista == NULL)// Se list a == NULL , então a funcao construir_ht foi executada com sucesso.
            {
                puts("construir_ht OK!!");
            }
            else
            {
                puts("construir_ht nao concluido\n");
            }
            unsigned char array_binario[freq_x_profundidade];//Declara o array que receberá os bits compactados.

            /// ESCREVE NO array_binario O TEXTO CODIFICADO DE ACORDO COM A ARVORE PASSADA
            criar_array_binarios(ht, arq, array_binario, freq_x_profundidade);

            ///COMPACTAÇÃO

            char url[1000];
            puts("Digite o nome do NOVO arquivo COMPACTADO!:");
            scanf("%s",url);
            puts("Digite a Senha: ");
            int n = 256;
            char senha[n];
            scanf("%s", senha);
            char *senha_md5 = gerar_md5(senha, strlen(senha));

            /// CRIA UM NOVO ARQUIVO PARA RECEBER A COMPACTAÇÃO
            FILE *novo_arquivo = fopen(url, "w");

            /// CRIA OS DOIS PRIMEIROS BYTES, DE ACORDO COM A ESPECIFICAÇÃO DO CABEÇALHO
            unsigned short cabecalho_inicial = {(converter_lixo(lixo) + tamanho_arvore)};

            /// ESCREVE OS 2 PRIMEIROS BYTES, A ARVORE E O TEXTO CODIFICADO
            escrever_cabecalho_inicio(cabecalho_inicial, novo_arquivo);
            escrever_arvore(cabeca_arvore, novo_arquivo);
            escrever_tam_ext(tam_extencao,novo_arquivo);
            escrever_extencao(nome_ex, novo_arquivo);
            escrever_senha_md5(senha_md5, novo_arquivo);
            escrever_tam_nome_arquivo(tam_arquivo, novo_arquivo);
            escrever_nome_arquivo(nome_arquivo, novo_arquivo);
            escrever_texto(array_binario, freq_x_profundidade, novo_arquivo);
            fclose(arq);
            fclose(novo_arquivo);//Fecha o arquivo
            ht = remove_hashtable(ht);// Desaloca o espaço utilizado para Tabela de Dispersão.
            cabeca_arvore = remove_arvore(cabeca_arvore);// Desaloca o espaço utilizado para Arvore de Huffman.
            free(hf);
            free(novo_hf);

            puts("\n\nArquivo compactado com sucesso!\n");//Mensagem de Finalização
        }
        main();  // Retorna para o inicio da função, como uma função recursiva!
    }
    //Se o usuário digitar 2, escolhendo a descompressão:
    else if(compactador == 2)
    {
        /// ABRE O ARQUIVO .huff NA MESMA PASTA
        char url[1000];
        puts("Digite a nome do arquivo a ser DESCOMPACTADO!:");
        scanf("%s",url);

        FILE *arq_compac = abrir_Arquivo(url);

        /// SALVA EM lixo QUANTOS BITS DO ULTIMO BYTE NÃO SÃO SIGNIFICATIVOS
        unsigned char lixo = obter_lixo(arq_compac);

        /// SALVA EM tam_array_arvore QUANTOS ELEMENTOS ESTÃO NA ARVORE DE HUFFMAN
        unsigned short tam_array_arvore = obter_tamanho_arvore(arq_compac);

        unsigned char array_arvore[tam_array_arvore];//Declara um array para receber os caracteres da arvore

        /// ESCREVE NO array_arvore OS CARACTERES DA ARVORE DE HUFFMAN
        obter_arvore(array_arvore,arq_compac);

        unsigned char tam_extencao = obter_tam_ext_descomp(arq_compac);

        unsigned char nome_ext[tam_extencao];
        obter_nome_ext_arq_descomp(arq_compac,nome_ext, tam_extencao);

        char senha_descompactar[256];
        puts("Digite a senha para descompactar: ");
        scanf("%s",senha_descompactar);
        verificar_senha_md5_descomp(arq_compac, senha_descompactar);

        unsigned char tam_nome_arquivo = obter_tam_nome_arquivo_descomp(arq_compac);
        unsigned char nome_arquivo[tam_nome_arquivo];
        obter_nome_arquivo_descomp(arq_compac, nome_arquivo, tam_nome_arquivo);
        unsigned short tam_cabecalho = (2 + tam_array_arvore + 1 + tam_extencao + 32 + 1 + tam_nome_arquivo);
        Node *cabeca_arvore = criar_Node_NULL();// Cria um ponteiro inicializado com NULL

        /// cabeca_arvore APONTA PARA RAIZ DA ARVORE DE HUFFMAN NOVA
        cabeca_arvore = criar_arvore_descompactacao(cabeca_arvore, array_arvore, tam_array_arvore);

        /// CALCULA A QUANTIDADE DE BITS DO ARQUIVO TIRANDO O CABEÇALHO
        unsigned long long int tam_array_binarios_descompactar = contar_tamanho_array_binarios_descompactar(arq_compac, tam_cabecalho);


        unsigned char array_binarios_descompactar[tam_array_binarios_descompactar];//Declara o array de bits compactados

        rewind(arq_compac);//Retorna ao começo do arquivo_huff

        /// O array_binarios_descompactar RECEBE EM CADA POSIÇÃO, UM BIT DO TEXTO COMPACTADO
        escrever_array_compactado(arq_compac, array_binarios_descompactar, tam_array_binarios_descompactar, tam_cabecalho);

        /// NÃO PRECISO MAIS DO ARQUIVO
        fclose(arq_compac);

        /// CRIA UM ARQUIVO .txt

        char url2[1000];
        puts("Digite o nome do NOVO arquivo DESCOMPACTADO!:");
        scanf("%s",url2);
        FILE *arquivo_txt = fopen(url2, "w");

        /// ESCREVE O TEXTO CORRESPONDENTE AO ARQUIVO COMPACTADO
        descompactar_texto(cabeca_arvore, array_binarios_descompactar, arquivo_txt, tam_array_binarios_descompactar-lixo);

        /// O ARQUIVO ESTÁ COMPLETO.
        fclose(arquivo_txt);

        cabeca_arvore = remove_arvore(cabeca_arvore);// Desaloca a memória utilizada para Arvore

        puts("\n\nArquivo descompactado com sucesso!");// Mensagem de Finalização*/

        main();// Retorna para o inicio da função, como uma função recursiva!
    }
    //Se o usuário digitar 0, escolhendo sair do programa:
    else if(compactador == 0)
    {
        return 0;
    }

    return 0;
}

