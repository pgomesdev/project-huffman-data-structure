#include "f_hashtable.h"

struct element
{
    unsigned short value;
    Element *next_element;
};

struct hashtable
{
    Element *table[MAX_TABLE];
};

void remove_lista(Element *lista);

Element *remove_ultimo_node(Element *lista);

Element *add_node_hash(Element *lista, unsigned short value);

Element *clonar_lista(Element *lista);

Hashtable *create_hashtable()
{
    Hashtable *new_ht = (Hashtable*)malloc(sizeof(Hashtable));
    if(new_ht == NULL)
    {
        puts("Erro ao Alocar Memoria para create_hashtable!\n");
        exit(0);
    }
    int i;
    for(i=0 ; i <= MAX_TABLE ; i++)
    {
        new_ht->table[i] = criar_node_hash_null();
    }
    return new_ht;
}

Element *criar_node_hash_null()
{
    return NULL;
}

Element *add_node_hash(Element *lista, unsigned short value)
{
    Element *new_element = (Element*)malloc(sizeof(Element));
    if(new_element == NULL)
    {
        puts("Erro ao Alocar Memoria para primeiro node add_node_hash!\n");
        exit(0);
    }
    new_element->value = value;
    new_element->next_element = NULL;

    Element *current_element = lista;
    if(current_element != NULL)
    {
        while(current_element->next_element != NULL)
        {
            current_element = current_element->next_element;
        }
        current_element->next_element = new_element;
        return lista;
    }
    else
    {
        return new_element;
    }
}

void print_ht(Hashtable *ht)
{
    int i;
    int aux = 0;

    if(ht != NULL)
    {
        Element *atual = criar_node_hash_null();
        for(i = 0 ; i<MAX_TABLE ; i++)
        {
            if(ht->table[i] != NULL)
            {
                printf("[%d:",i);
                aux++;
            }
            atual = ht->table[i];
            while(atual != NULL)
            {
                printf(" %d", atual->value);
                atual = atual->next_element;
            }
            if(aux>0)
            {
                printf("]\n");
                aux--;
            }
        }
    }
}

Element *clonar_lista(Element *lista)
{
    if(lista == NULL)
    {
        return NULL;
    }
    else
    {
        Element *lista_clonada = criar_node_hash_null();
        lista_clonada = add_node_hash(lista_clonada,lista->value);

        Element *current = lista;

        while(current->next_element != NULL)
        {
            current = current->next_element;
            lista_clonada = add_node_hash(lista_clonada,current->value);
        }

        return lista_clonada;
    }
}
void construir_ht(Node *cabeca_arvore, Element *lista, Hashtable *ht)
{
    if(cabeca_arvore != NULL && ht != NULL)
    {
        if(cabeca_arvore->letra == '*')
        {
            lista = add_node_hash(lista, 0);
            construir_ht(cabeca_arvore->filho_esquerda, lista, ht);
            lista = remove_ultimo_node(lista);
            lista = add_node_hash(lista, 1);
            construir_ht(cabeca_arvore->filho_direita, lista, ht);
            lista = remove_ultimo_node(lista);
        }
        else
        {
            Element *lista_clonada = clonar_lista(lista);
            ht->table[cabeca_arvore->letra] = lista_clonada;
        }
    }
}

Element *remove_ultimo_node(Element *lista)
{
    Element *atual = lista;
    Element *anterior = atual;
    if(lista == NULL)
    {
        return lista;
    }
    else if(lista->next_element == NULL)
    {
        free(lista);
        return NULL;
    }
    else
    {
        while(atual != NULL)
        {
            if(atual->next_element == NULL)
            {
                anterior->next_element = NULL;
                free(atual);
                break;
            }
            else
            {
                anterior = atual;
            }
            atual = anterior->next_element;
        }

        return lista;
    }
}

void remove_lista(Element *lista)
{
    if(lista != NULL)
    {
        Element *current = lista->next_element;
        free(lista);
        remove_lista(current);
    }
}

Hashtable *remove_hashtable(Hashtable *ht)
{
    int i;

    if(ht == NULL)
    {
        return NULL;
    }
    else
    {
        for(i = 0; i<MAX_TABLE; i++)
        {
            if(ht->table[i] != NULL)
            {
                remove_lista(ht->table[i]);
                ht->table[i] = NULL;
            }
        }
        free(ht);
        return NULL;
    }
}
