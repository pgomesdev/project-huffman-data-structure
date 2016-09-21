#include "f_arvore.h"

unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}

/* DESLOCA O LIXO 13 VEZES PARA A ESQUERDA */
unsigned short converter_lixo(unsigned short lixo)
{
    return lixo << 13;
}

/* ESCREVE A ÁRVORE NO ARQUIVO */
void escrever_árvore(Node *cabeca, FILE *arquivo)
{
    if(cabeca != NULL)
    {
        fputc(cabeca->letra, arquivo);
        print_pre_ordem_arvore(cabeca->filho_esquerda);
        print_pre_ordem_arvore(cabeca->filho_direita);
    }
}

void escrever_texto(char *array_texto, int tamanho, File *arquivo)
{
    int i;
    unsigned char c = 0;

    for(i = 0; i < size; i++)
    {
        if(array_texto[i] == 1)
        {
            c = set_bit(c, (i % 8 + 1));
        }

        if(i % 8 == 1)
        {
            fputs(c, arquivo);
            c = 0;
        }
    }
}
