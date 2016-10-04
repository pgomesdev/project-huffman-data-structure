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
unsigned char is_bit_set_char(unsigned char c, int i);

unsigned char is_bit_set_char(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
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

void obter_arvore(unsigned char *array_arvore, FILE *arquivo)
{
    rewind(arquivo);
    int i = 0;
    int tamanho = obter_tamanho_arvore(arquivo);
    for(i = 0; i < tamanho; i++)
    {
        array_arvore[i] = fgetc(arquivo);
    }
}

/* CONTAGEM DA QUANTIDADE DE BITS NO TEXTO DO ARQUIVO COMPACTADO */
unsigned int contar_tamanho_array_binarios_descompactar(FILE *arquivo, unsigned short tam_cabecalho)
{
    int i, tam = 0;

    rewind(arquivo);
    for(i = 0; i<tam_cabecalho ; i++)
    {
        fgetc(arquivo);
    }

    /* LÊ TODO ARQUIVO, INCLUSIVE O QUE HÁ DE LIXO */
    while(fgetc(arquivo) != EOF)
    {
        tam++;
    }

    /* RETORNA A QUANTIDADE DE BITS DO TEXTO */
    return tam * 8;
}

void escrever_array_compactado(FILE *arquivo, unsigned short *array_binarios_descompactar, unsigned int tam_array_b_descompactar, unsigned short tam_cabecalho)
{
    unsigned char c;
    unsigned int i, tam = 0;
    rewind(arquivo);
    for(i = 0; i<tam_cabecalho ; i++)
    {
        printf(" %c ",fgetc(arquivo));
    }

    /* LÊ TODO ARQUIVO, INCLUSIVE O QUE HÁ DE LIXO */
    while(tam < tam_array_b_descompactar)
    {

        c = fgetc(arquivo);
        for(i = 0; i < TAMANHO_BYTE; i++)
        {
            if(is_bit_set_char(c, 7 - (tam % TAMANHO_BYTE)))
            {
                array_binarios_descompactar[tam] = 1;
            }
            else
            {
                array_binarios_descompactar[tam] = 0;
            }
            tam++;
        }
    }
}

void descompactar_texto(Node *cabeca, unsigned short *texto_compactado, FILE *novo_arquivo, int tamanho_texto)
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
        fputc(auxiliar->letra, novo_arquivo);
        auxiliar = cabeca;
    }
}

Node *criar_arvore_descompactacao(Node *arvore_huffman, unsigned char *array_arvore, unsigned short tam_array_arvore)
{
    int aux = 0;
    while(array_arvore[aux] == 0)
    {
        aux++;
    }

    if(aux < tam_array_arvore)
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        if(newnode == NULL)
        {
            puts("Erro ao Alocar Memoria para criar_arvore_descompactacao!\n");
            exit(0);
        }
        newnode->letra = 0;
        newnode->num = 0;
        newnode->profundidade = 0;
        newnode->proximo_node = NULL;
        newnode->filho_esquerda = NULL;
        newnode->filho_direita = NULL;
        arvore_huffman = newnode;

        if(array_arvore[aux] == '*')
        {
            array_arvore[aux] = 0;
            arvore_huffman->letra = '*';
            arvore_huffman->filho_esquerda = criar_arvore_descompactacao(arvore_huffman->filho_esquerda, array_arvore, tam_array_arvore);
            arvore_huffman->filho_direita = criar_arvore_descompactacao(arvore_huffman->filho_direita, array_arvore, tam_array_arvore);
            return arvore_huffman;
        }
        else
        {
            arvore_huffman->letra = array_arvore[aux];
            array_arvore[aux] = 0;
            return arvore_huffman;
        }
    }
    return arvore_huffman;
}

