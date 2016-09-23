#include <stdio.h>
#define TAMANHO_BYTE 8
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
            c = set_bit(c, ((i % 8) + 7 - 2 * (i % 8)));
        }

        if(i % 8 == 7)
        {
            fputc(c, arquivo);
            c = 0;
        }
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
            c = set_bit(c, (i + 7 - 2*i));
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

int main()
{
    FILE *novo_arquivo = fopen("arquivo.huff", "w+");

    unsigned short lixo = 7;
    unsigned short tamanho_arvore = 18;

    unsigned char arvore[] = {'o', 'i', 'c', 'a', 'r', 'a'};
    unsigned char texto[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0};

    unsigned short cabecalho_inicial = (converter_lixo(lixo) + tamanho_arvore);

    /* ESCREVE OS DADOS NO ARQUIVO NA ORDEM: LIXO (3 BITS), TAMANHO DA ÁVORE(13 BITS),
       ÁRVORE E TEXTO COMPACTADO */
    escrever_cabecalho_inicio(cabecalho_inicial, novo_arquivo);

    //escrever_arvore(arvore, 6, novo_arquivo);

    //escrever_texto(texto, 51, novo_arquivo);

    fclose(novo_arquivo);

    FILE *arquivo_antigo = fopen("arquivo.huff", "r");

    unsigned char text[2];

    text[0] = fgetc(arquivo_antigo);
    text[1] = fgetc(arquivo_antigo);

    int i;

    unsigned short novo_cabecalho[2];
    novo_cabecalho[0] = text[0];
    novo_cabecalho[1] = text[1];
    novo_cabecalho[0] = novo_cabecalho[0] << 8;
    unsigned short total = novo_cabecalho[0] + novo_cabecalho[1];

    printf("1: %d\n", novo_cabecalho[0]);
    printf("2: %d\n", novo_cabecalho[1]);
    printf("%d = %d\n", cabecalho_inicial, total);

    total = total >> 13;
    printf("lixo = %d\n", total);
    total = novo_cabecalho[0] + novo_cabecalho[1];
    total = total << 3;
    total = total >> 3;
    printf("tamanho = %d\n", total);

    fclose(arquivo_antigo);
}
