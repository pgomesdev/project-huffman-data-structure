#include "f_arquivo.h"

void print_freq(char *freq, long int tam)
{
    long int i=0;

    /// PRINT GERAL DOS RESULTADOS DAS FREQUENCIAS DAS LETRAS!
    while(i<tam)
    {

        /// O ARRAY "freq[]" TEM TAMANHO MAIOR QUE OS VALORES RESGISTRADOS E PARA NAO IMPRIMIR "LIXO" ESTA CONDIÇÃO FOI CRIADA.
        if(freq[i+1] != -1)
        {
            ///Condição para imprimir o '\n' caso especial.
            if(freq[i] == '\n')
                printf("[\\n][%d]",freq[i+1]);

            else
                printf("[%c][%d]", freq[i], freq[i+1]);
            puts("\n");
        }
        i = i+2;
    }
}

void print_txt(char *txt, long int tam)
{
    /// PRINT DO BUFFER COM O ARQUIVO CONTIDO.
    long int i=0;
    while(i<tam)
    {
        printf("%c", txt[i]);
        i++;
    }
    puts("\n");
}

long int contar_tam_texto_char(FILE *arq)
{
    long int tam = 0;
    char ch;
    rewind(arq);
    while((ch = fgetc(arq)) != EOF)
    {
        tam++;
    }
    return tam;
}

FILE *abrir_Arquivo(char *url)
{
    FILE *arq = fopen(url, "r");

    if(arq == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return 0;
    }
    else
    {
        return arq;
    }
}

void limpar_array(char *arq, long int tam)
{
    long int i;
    for(i=0 ; i<tam ; i++)
    {
        arq[i] = -1;
    }
}
