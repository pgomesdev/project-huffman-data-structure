#include "f_hashtable.h"

Element *criar_hash_nula()
{
    return NULL;
}

Element *adicionar_node_hash(Element *lista, unsigned short value)
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

Element *clonar_lista(Element *lista)
{
    if(lista == NULL)
    {
        return NULL;
    }
    else
    {
        Element *lista_clonada = criar_node_hash_nulo();
        lista_clonada = adicionar_node_hash(lista_clonada,lista->value);

        Element *current = lista;

        while(current->next_element != NULL)
        {
            current = current->next_element;
            lista_clonada = adicionar_node_hash(lista_clonada,current->value);
        }

        return lista_clonada;
    }
}
void construir_hash(Node *cabeca_arvore, Elemento *hash)
{
    if(cabeca_arvore != NULL && ht != NULL)
    {
        if(cabeca_arvore->letra == '*')
        {
            hash = adicionar_node_hash(hash, 0);
            construir_hash(cabeca_arvore->filho_esquerda, hash);
            hash = remove_ultimo_node(hash);
            hash = adicionar_node_hash(hash, 1);
            construir_hash(cabeca_arvore->filho_direita, hash);
            hash = remove_ultimo_node(hash);
        }
        else
        {
            Elemento *lista_clonada = clonar_lista(hash);
            hash[letra] = lista_clonada;
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
