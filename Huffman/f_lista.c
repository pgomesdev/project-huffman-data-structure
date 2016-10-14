#include "f_lista.h"

struct array_freq
{
    Node *freq[MAX_TABLE];
};

Node *add_node_lista(unsigned char letra);

Node *criar_Node_NULL()
{
    return NULL;
}

int esta_Vazia(Node *cabeca_lista)
{
    return (cabeca_lista==NULL);
}

Hash_Freq *criar_array_freq()
{
    Hash_Freq *novo_hf = (Hash_Freq*)malloc(sizeof(Hash_Freq));

    int i;
    for(i = 0 ; i <= MAX_TABLE ; i++)
    {
        novo_hf->freq[i] = criar_Node_NULL();
    }
    return novo_hf;
}

void contar_freq_char(FILE *arquivo, Hash_Freq *hf)
{
    char c;
    rewind(arquivo);
    while((c = fgetc(arquivo)) != EOF)
    {
        unsigned char letra = c;
        if(hf->freq[letra] == NULL)
            hf->freq[letra] = add_node_lista(letra);
        else
            hf->freq[letra]->num++;
    }
}

Node *add_node_lista(unsigned char letra)
{
    Node *novo = (Node*)malloc(sizeof(Node));

    if(letra == '*')
        novo->letra = '\*';
    else
        novo->letra = letra;

    novo->num = 1;
    novo->profundidade = 0;
    novo->proximo_node = NULL;
    novo->filho_esquerda = NULL;
    novo->filho_direita = NULL;

    if(novo == NULL)
    {
        puts("Erro ao alocar memoria para lista!\n");
        exit(0);
    }
    else
        return novo;
}

short tam__novo_hf(Hash_Freq *hf)
{
    short i, cont = 0;
    for(i = 0 ; i <= MAX_TABLE ; i++)
    {
        if(hf->freq[i] != NULL)
            cont++;

    }
    return cont;
}

void Quick_Sort(Hash_Freq *hf, int inicio, int fim)
{
    Node *pivo, *aux;
    int i, j, meio;

    i = inicio;
    j = fim;

    meio = (int) ((i + j) / 2);
    pivo = hf->freq[meio];


    do
    {
        while (hf->freq[i]->num < pivo->num)
            i++;
        while (hf->freq[j]->num > pivo->num)
            j--;

        if(i <= j)
        {
            aux = hf->freq[i];
            hf->freq[i] = hf->freq[j];
            hf->freq[j] = aux;
            i++;
            j--;
        }
    }
    while(j > i);

    if(inicio < j)
        Quick_Sort(hf, inicio, j);
    if(i < fim)
        Quick_Sort(hf, i, fim);
}

void criar_novo_hf(Hash_Freq *hf, Hash_Freq *novo_hf, short tam__novo_hf)
{
    int i, j = 0;
    for(i = 0 ; i < MAX_TABLE ; i++)
    {
        if(hf->freq[i] != NULL)
        {
            novo_hf->freq[j] = hf->freq[i];
            j++;
        }
    }
}

Node *criar_lista_huffman(Hash_Freq *hf, short tam_hf)
{
    int i;
    for(i = 1 ; i < tam_hf ; i++)
    {
        hf->freq[i-1]->proximo_node = hf->freq[i];
    }

    return hf->freq[0];
}

Hash_Freq *remove_hash_Freq(Hash_Freq *hf)
{
    int i;

    if(hf == NULL)
    {
        return NULL;
    }
    else
    {
        for(i = 0; i<MAX_TABLE; i++)
        {
            if(hf->freq[i] != NULL)
            {
                free(hf->freq[i]);
                hf->freq[i] = NULL;
            }
        }
        free(hf);
        return NULL;
    }
}
