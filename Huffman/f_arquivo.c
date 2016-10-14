#include "f_arquivo.h"

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
