#include "f_arquivo.h"

void print_freq_i(int *freq, int tam)
{
    int i;
    for(i = 0; freq[i]!= -1 ; i++)
    {
        printf("[%i] ", freq[i]);
    }
}

void print_freq_c(char *freq, int tam)
{
    int i;

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

void print_txt(char *txt, int tam)
{
    /// PRINT DO BUFFER COM O ARQUIVO CONTIDO.
    int i=0;
    while(i<tam)
    {
        printf("%c", txt[i]);
        i++;
    }
    puts("\n");
}

int contar_tam_texto_char(FILE *arq)
{
    int tam = 0;
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

void limpar_array_i(int *arq, int tam)
{
    int i;
    for(i=0 ; i<tam ; i++)
    {
        arq[i] = -1;
    }
}
void limpar_array_c(char *arq, int tam)
{
    int i;
    for(i=0 ; i<tam ; i++)
    {
        arq[i] = -1;
    }
}
