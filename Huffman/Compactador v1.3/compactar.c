#include "f_arvore.h"
#include "compactar.h"

/* FUNÇÃO UTILIZADA PARA SETAR UM DETERMINADO BIT EM UM CHAR */
unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}

/* FAZ O DESLOCAMENTO DOS 3 BITS DE LIXO PARA OS TRÊS PRIMEIROS BITS DO SHORT */
unsigned short converter_lixo(unsigned short lixo)
{
    return lixo << 13;
}

/* ESCREVE A ÁRVORE EM PRÉ-ORDEM NO ARQUIVO */
void escrever_arvore(Node *cabeca, FILE *arquivo)
{
    if(cabeca != NULL)
    {
        fputc(cabeca->letra, arquivo);
        escrever_arvore(cabeca->filho_esquerda, arquivo);
        escrever_arvore(cabeca->filho_direita, arquivo);
    }
}

/* ESCREVE O TEXTO JÁ COMPACTADO NO ARQUIVO */
void escrever_texto(unsigned char *array_texto, int tamanho, FILE *arquivo)
{
    int i;
    unsigned char c = 0;

    for(i = 0; i < tamanho; i++)
    {
        if(array_texto[i] == 1)
        {
            c = set_bit(c, (i % TAMANHO_BYTE + 1));
        }

        if(i % TAMANHO_BYTE == 1)
        {
            fputc(c, arquivo);
            c = 0;
        }
    }
}
