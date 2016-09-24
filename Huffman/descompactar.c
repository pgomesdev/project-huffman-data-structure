#include "f_arvore.h"

void descompactar_cabecalho(FILE *arquivo)
{
    unsigned short lixo_tamanho[2];
    unsigned char arvore[] = {};

    lixo_tamanho[0] = fgetc(arquivo);
    lixo_tamanho[1] = fgetc(arquivo);

    unsigned short lixo = lixo_tamanho[0];
    lixo = lixo >> 13;

    unsigned short tamanho_arvore = lixo_tamanho[0] + lixo_tamanho[1];
    tamanho_arvore = tamanho_arvore << 3;
    tamanho_arvore = tamanho_arvore >> 3;

    int i;

    for(i = 0; i < tamanho_arvore; i++)
    {
        arvore[i] = fgetc(arquivo);
    }
}

unsigned short obter_lixo(FILE *arquivo)
{
    unsigned short lixo;

    lixo = fgetc(arquivo);
    lixo = lixo >> 13;

    rewind(fgetc);

    return lixo;
}

unsigned short obter_tamanho_arvore(FILE *arquivo)
{
    unsigned short tamanho_arvore;
    unsigned short auxiliar[2];

    auxiliar[0] = fgetc(arquivo);
    auxiliar[1] = fgetc(arquivo);

    tamanho_arvore = auxiliar[0] + auxiliar[1];
    tamanho_arvore = tamanho_arvore << 3;
    tamanho_arvore = tamanho_arvore >> 3;

    return tamanho_arvore;
}

void obter_arvore(unsigned char *arvore, FILE *arquivo)
{
    int i = 0;
    int tamanho = obter_tamanho_arvore(arquivo);

    for(i = 0; i < tamanho; i++)
    {
        arvore[i] = fgetc(arquivo);
    }
}

void escrever_arquivo(Node *arvore, FILE *arquivo)
{

}
