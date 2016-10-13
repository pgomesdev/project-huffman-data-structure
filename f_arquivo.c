#include "f_arquivo.h"

void print_txt(unsigned char *txt, int tam)
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
