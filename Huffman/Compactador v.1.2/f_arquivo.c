#include "f_arquivo.h"

void print_freq_i(long int *freq, long int tam)
{
    int i;
    for(i = 0; freq[i]!= -1 ; i++)
    {
        printf("[%li] ", freq[i]);
    }
}

void print_freq_c(char *freq, long int tam)
{
    long int i;

    /// PRINT GERAL DOS RESULTADOS DAS FREQUENCIAS DAS LETRAS!
    for(i = 0; freq[i] != -1; i++)
    {
        ///Condição para imprimir o '\n' caso especial.
        if(freq[i] == '\n')
        {
            printf("[\\n] ");
        }
        else
        {
            printf("[%c] ", freq[i]);
        }
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

void limpar_array_i(long int *arq, long int tam)
{
    long int i;
    for(i=0 ; i<tam ; i++)
    {
        arq[i] = -1;
    }
}
void limpar_array_c(char *arq, long int tam)
{
    long int i;
    for(i=0 ; i<tam ; i++)
    {
        arq[i] = -1;
    }
}
