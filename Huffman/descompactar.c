#include "descompactar.h"

/* FUNÇÃO QUE RETORNA 0(FALSO) OU 1(VERDADEIRO) CASO O BIT SELECIONADO ESTEJA SETADO */
unsigned short is_bit_set(unsigned char c, int i)
{
    unsigned short mask = 1 << i;
    return mask & c;
}

unsigned short obter_lixo(FILE *arquivo)
{
    unsigned short lixo;

    lixo = fgetc(arquivo);
    lixo = lixo >> 5;

    return lixo;
}

unsigned short obter_tamanho_arvore(FILE *arquivo)
{
    unsigned short tamanho_arvore;
    unsigned short auxiliar[2];

    auxiliar[0] = fgetc(arquivo);
    auxiliar[1] = fgetc(arquivo);

    auxiliar[0] = auxiliar[0] << 11;
    auxiliar[0] = auxiliar[0] >> 3;

    tamanho_arvore = auxiliar[0] + auxiliar[1];

    return tamanho_arvore;
}

void obter_arvore(unsigned char *arvore, FILE *arquivo)
{
    int i;
    int tamanho = obter_tamanho_arvore(arquivo);

    for(i = 0; i < tamanho; i++)
    {
        arvore[i] = fgetc(arquivo);
    }
}

/* CONTAGEM DA QUANTIDADE DE BITS NO TEXTO DO ARQUIVO COMPACTADO */
int obter_tamanho_texto(FILE *arquivo)
{
    int tam = 0;

    /* LÊ TODO ARQUIVO, INCLUSIVE O QUE HÁ DE LIXO */
    while(fgetc(arquivo) != EOF)
    {
        tam++;
    }

    /* RETORNA A QUANTIDADE DE BITS DO TEXTO */
    return tam * 8;
}

void escrever_texto_compactado(FILE *arquivo, int *texto_compactado)
{
    unsigned char c;
    int i;

    /* LÊ TODO ARQUIVO, INCLUSIVE O QUE HÁ DE LIXO */
    while((c = fgetc(arquivo)) != EOF)
    {
        for(i = 0; i < TAMANHO_BYTE; i++)
        {
            if(is_bit_set(c, 7 - (i % TAMANHO_BYTE)))
                texto_compactado[i] = 1;
            else
                texto_compactado[i] = 0;
        }
    }
}

void descompactar_texto(Node *cabeca, int *texto_compactado, FILE *novo_arquivo, int tamanho_texto)
{
    int i = 0;
    Node *auxiliar;

    while(i < tamanho_texto)
    {
        auxiliar = cabeca;
        while(auxiliar->letra == '*')
        {
            if(texto_compactado[i] == 0)
                auxiliar = auxiliar->filho_esquerda;
            else
                auxiliar = auxiliar->filho_direita;

            i++;
        }

        fputc(auxiliar->letra, novo_arquivo);
    }
}
