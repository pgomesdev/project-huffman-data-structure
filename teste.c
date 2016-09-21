#include <stdio.h>
#include <stdlib.h>

unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}

unsigned short converter_lixo(unsigned short lixo)
{
    return lixo << 13;
}

void escrever_arvore(unsigned char *arvore, int tamanho, FILE *arquivo)
{
    int i;

    for(i = 0; i < tamanho; i++)
        fputc(arvore[i], arquivo);
}


void escrever_texto(unsigned char *array_texto, int tamanho, FILE *arquivo)
{
    int i;
    unsigned char c = 0;

    for(i = 0; i < tamanho; i++)
    {
        if(array_texto[i] == 1)
        {
            c = set_bit(c, (i % 8 + 1));
        }

        if(i % 8 == 1)
        {
            fputc(c, arquivo);
            c = 0;
        }
    }
}

int main()
{
    FILE *novo_arquivo = fopen("arquivo.huff", "w+x");

    unsigned short lixo = 3;
    unsigned short tamanho_arvore = 13;

    unsigned char arvore[] = {'o', 'i', 'c', 'a', 'r', 'a'};
    unsigned char texto[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0};

    unsigned short cabecalho_inicial[1] = {(converter_lixo(lixo) + tamanho_arvore)};

    /* ESCREVE OS DADOS NO ARQUIVO NA ORDEM: LIXO (3 BITS), TAMANHO DA ÁVORE(13 BITS),
       ÁRVORE E TEXTO COMPACTADO */
    fwrite(cabecalho_inicial, sizeof(short), sizeof(cabecalho_inicial), novo_arquivo);

    escrever_arvore(arvore, 6, novo_arquivo);

    escrever_texto(texto, 51, novo_arquivo);

    fclose(novo_arquivo);
}
