#include "f_arvore.h"
#include "compactar.h"
#define TAMANHO_SHORT 16

/* FUNÇÃO UTILIZADA PARA SETAR UM DETERMINADO BIT EM UM CHAR */
unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}

/* FUNÇÃO QUE RETORNA 0(FALSO) OU 1(VERDADEIRO) CASO O BIT SELECIONADO ESTEJA SETADO */
int is_bit_set(unsigned short c, int i)
{
    unsigned short mask = 1 << i;
    return mask & c;
}

/* FAZ O DESLOCAMENTO DOS 3 BITS DE LIXO PARA OS TRÊS PRIMEIROS BITS DO SHORT */
unsigned short converter_lixo(unsigned short lixo)
{
    return lixo << 13;
}

/* ESCREVE O CABEÇALHO(LIXO E TAMANHO DA ÁRVORE) */
void escrever_cabecalho_inicio(unsigned short cabecalho_inicial, FILE* arquivo)
{
    int i;
    unsigned char c = 0;

    for(i = 0; i < TAMANHO_SHORT; i++)
    {
        if(is_bit_set(cabecalho_inicial, (i + 15 - 2 * i)))
        {
            c = set_bit(c, ((i % TAMANHO_BYTE) + 7 - 2 * (i % TAMANHO_BYTE)));
        }

        if(i % 8 == 7)
        {
            fputc(c, arquivo);
            c = 0;
        }
    }
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
            c = set_bit(c, ((i % TAMANHO_BYTE) + 7 - 2 * (i % TAMANHO_BYTE)));
        }

        if(i % TAMANHO_BYTE == 7)
        {
            fputc(c, arquivo);
            c = 0;
        }
    }

    if(i % TAMANHO_BYTE != 7)
        fputc(c, arquivo);
}
