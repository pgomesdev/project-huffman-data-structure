#include "descompactar.h"

/*unsigned *descompactar_cabecalho(FILE *arquivo)
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
}*/

/* FUNÇÃO QUE RETORNA 0(FALSO) OU 1(VERDADEIRO) CASO O BIT SELECIONADO ESTEJA SETADO */
unsigned short is_bit_set(unsigned short c, int i)
{
    unsigned short mask = 1 << i;
    return mask & c;
}

unsigned char obter_lixo(FILE *arquivo)
{
    rewind(arquivo);
    unsigned char lixo;

    lixo = fgetc(arquivo);
    lixo = lixo >> 5;
    return lixo;
}

unsigned short obter_tamanho_arvore(FILE *arquivo)
{
    rewind(arquivo);
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
    rewind(arquivo);
    int i = 0;
    int tamanho = obter_tamanho_arvore(arquivo);
    for(i = 0; i < tamanho; i++)
    {
        arvore[i] = fgetc(arquivo);
    }
}

/* CONTAGEM DA QUANTIDADE DE BITS NO TEXTO DO ARQUIVO COMPACTADO */
int contar_tamanho_texto(FILE *arquivo)
{
    int tam = 1;

    /* LÊ TODO ARQUIVO, INCLUSIVE O QUE HÁ DE LIXO */
    while(fgetc(arquivo) != EOF)
    {
        tam++;
    }

    /* RETORNA A QUANTIDADE DE BITS DO TEXTO */
    return tam * 8;
}

int escrever_texto_compactado(FILE *arquivo, unsigned short *texto_compactado)
{
    int i, tam = 1;

    /* LÊ TODO ARQUIVO, INCLUSIVE O QUE HÁ DE LIXO */
    while((c = fgetc(arquivo)) != EOF)
    {
        for(i = 0; i < TAMANHO_BYTE; i++)
        {
            if(is_bit_set(c, 7 - (i % 8)))
                texto_compactado[i] = 1;
            else
                texto_compactado[i] = 0;
        }
        tam++;
    }

    /* RETORNA A QUANTIDADE DE BITS DO TEXTO */
    return tam * 8;
}

void descompactar_texto(Node *cabeca, unsigned short *texto_compactado, FILE *novo_arquivo, int tamanho_texto);
{
    int i = 0;
    Node *auxiliar = cabeca;

    while(i < tamanho_texto)
    {
        while(auxiliar->letra == '*')
        {
            if(texto_compactado[i] == 0)
                auxiliar = auxiliar->filho_esquerda;
            else
                auxiliar = auxiliar->filho_direita;

            i++;
        }

        fputc(auxiliar->letra, arquivo);
        i++;
    }
}
