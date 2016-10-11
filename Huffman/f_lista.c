#include "f_lista.h"

Node *criar_Node_NULL()
{
    return NULL;
}

int esta_Vazia(Node *cabeca_lista)
{
    return (cabeca_lista==NULL);
}

Node *adicionar_node(Node *cabeca_lista, unsigned char letra)
{
    Node *atual, *anterior;
    Node *newnode = (Node*)malloc(sizeof(Node));

    newnode->letra = letra;
    newnode->frequencia = 1;
    newnode->profundidade = 0;
    newnode->proximo_node = NULL;
    newnode->filho_esquerda = NULL;
    newnode->filho_direita = NULL;

    return cabeca_lista;
}

Node *criar_lista_frequencia(Node *cabeca_lista, FILE *arquivo_texto)
{
    unsigned char letra;

    Node *frequencia[256] = {NULL};

    while((letra = fgetc(arquivo_texto)) != EOF)
    {
        if(feof(arquivo_texto))
            break;

        if(frequencia[letra] == NULL)
            frequencia[letra] = adicionar_node(frequencia[letra], letra);

        else
            frequencia[letra]->frequencia++;
    }

    int i, tamanho = 0, j = 0;

    for(i = 0; i < 256; i++)
    {
        if(frequencia[i] != NULL)
        {
            tamanho++;
        }
    }

    Node *array_ordenado[tamanho];

    for(i = 0; i < 256; i++)
    {
        if(frequencia[i] != NULL)
        {
            array_ordenado[j] = frequencia[i];
            j++;
        }
    }

    void quicksort(array_ordenado, tamanho);

    for(i = 0; i < tamanho - 1; i++)
    {
        array_ordenado[i]->proximo_node = array_ordenado[i + 1];
    }

    cabeca_lista = array_ordenado[0];

    /* IMPRESSÃO PARA TESTE, REMOVEREMOS DEPOIS */

    for(i = 0; i < tamanho; i++)
        printf("%lld\n", array_ordenado[i]->frequencia);

    return cabeca_lista;
}

void quicksort(Node *lista, int tamanho)
{
    if(tamanho == 1)
        return;

    else
    {
        Node* pivo = lista[tamanho / 2];
        int a = 0;
        int b = tamanho - 1;
        Node *aux;

        while(a < b)
        {
            while(lista[a]->frequencia < pivo->frequencia)
                a++;
            while(lista[b]->frequencia > pivo->frequencia)
                b--;
            if (a < b)
            {
                aux = lista[b];
                lista[b] = lista[a];
                lista[a] = aux;
            }
        }
        quicksort(lista, a - 1);
        quicksort(lista + a, tamanho - a);
    }
}


