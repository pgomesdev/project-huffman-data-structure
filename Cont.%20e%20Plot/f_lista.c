#include "f_lista.h"

Node *criar_lista_encadeada()
{
    return NULL;
}

int esta_vazio( Node *lista)
{
    return (lista == NULL);
}

Node *inserir_node( Node *lista, int item )
{
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->item = item;
    novo->proximo_node = lista;
    return novo;
}

void print_lista( Node *lista )
{
    Node *p;
    for( p = lista; p != NULL; p = p->proximo_node )
    {
        printf( "[%d]", p->item );
    }
    puts("\n");
}

int pesquisar_Node( Node *lista, int item )
{
    Node *p;
    int i = 1;
    for( p = lista; p != NULL; p = p->proximo_node)
    {
        if( p->item == item )
        {
            return i;
        }
        i++;
    }
    return 0;
}

Node *removeNode( Node *lista, int item )
{
    Node *anterior = NULL;
    Node *atual = lista;
    while( atual != NULL && atual->item != item )
    {
        anterior = atual;
        atual = atual->proximo_node;
    }
    if( atual == NULL )
    {
        return lista;
    }
    if( anterior == NULL )
    {
        lista = atual->proximo_node;
    }
    else
    {
        anterior->proximo_node = atual->proximo_node;
    }
    free( atual );
    return lista;
}

Node *remove_lista(Node *lista)
{

    if(lista != NULL)
    {
        Node *atual = lista->proximo_node;
        free(lista);
        remove_lista(atual);
    }
    return NULL;
}

void print_array(int *numeros)
{
    int i;
    for(i = 0 ; i < MAX ; i++)
    {
        printf("\nNumero Sorteados: [%d]", numeros[i]);
    }
}

void escrever_contagem(FILE *arquivo, ArvB *cabeca, Node *lista, int *numeros)
{
    int i;
    for(i = 0 ; i<MAX ; i++)
    {
            fprintf(arquivo, "%d,%d,%d\n", numeros[i], busca_elemento_cont(cabeca, numeros[i], 1), pesquisar_Node(lista, numeros[i]));
    }
}

void Quick_Sort(int *numeros, int inicio, int fim)
{
    int pivo, aux;
    int i, j, meio;

    i = inicio;
    j = fim;

    meio = (int) ((i + j) / 2);
    pivo = numeros[meio];


    do
    {
        while (numeros[i] < pivo)
            i++;
        while (numeros[j] > pivo)
            j--;

        if(i <= j)
        {
            aux = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = aux;
            i++;
            j--;
        }
    }
    while(j > i);

    if(inicio < j)
        Quick_Sort(numeros, inicio, j);
    if(i < fim)
        Quick_Sort(numeros, i, fim);
}
