#include <stdio.h>
#include "hashtable.h"

Node* construir_lista(Node *arvore, Node *lista, Hashtable *hash)
{
    if(arvore != NULL)
	{
		if(arvore->item == '*')
		{
			lista = add_node(lista, 0);
			lista = construir_lista(arvore->filho_esquerda, lista, hash);
			lista = remove_node(lista);
			lista = add_node(lista, 1);
			lista = construir_lista(arvore->filho_direita, lista, hash);
			lista = remove_node(lista);
			return lista;
		}
		else
		{
			hash->table[arvore->item % 256] = lista;
			return lista;
		}
	}
}
