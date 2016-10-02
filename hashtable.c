#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_HASH 256

typedef struct elemento Elemento;

struct elemento
{
	int valor;
	Elemento *proximo_elemento;
};

Elemento* criar_elemento(Elemento *lista)
{
    return NULL;
}

Elemento* adicionar_elemento(Elemento *lista, int valor)
{
    Elemento *novo_elemento = (Elemento*) malloc(sizeof(Elemento));
    novo_elemento->valor = valor;
    novo_elemento->proximo_elemento = NULL;

    if(lista == NULL)
    {
        return novo_elemento;
    }

    else
    {
        Elemento *auxiliar = lista;

        while(auxiliar->proximo_elemento != NULL)
            auxiliar = auxiliar->proximo_elemento;

        auxiliar->proximo_elemento = novo_elemento;

        return lista;
    }
}

Elemento* remover_elemento(Elemento *lista)
{
    Elemento *anterior = NULL;
    Elemento *auxiliar = lista;

    while(auxiliar->proximo_elemento != NULL)
    {
        anterior = auxiliar;
        auxiliar = auxiliar->proximo_elemento;
    }

    anterior->proximo_elemento = NULL;
    free(auxiliar);

    return lista;
}

typedef struct hashtable Hashtable;

struct hashtable
{
	Elemento *table[TAMANHO_HASH];
};

Hashtable* criar_hashtable()
{
	Hashtable *ht = (Hashtable*) malloc(sizeof(Hashtable));
	int i;
	for(i = 0; i < TAMANHO_HASH; i++)
		ht->table[i] = NULL;

	return ht;
}

void inserir_elemento(Hashtable *ht, char chave, int valor)
{
	int h = chave;

	ht->table[h] = adicionar_elemento(ht->table[h], valor);
}

int obter_valor(Hashtable *ht, int chave)
{
    return ht->table[chave]->valor;
}

void escrever_array_texto(Hashtable *ht, int *array_texto, unsigned char *arquivo_texto)
{
	int h = chave;

	Elemento *auxiliar = ht->table[h];
    int i = 0;
	while(ht->table[h] != NULL)
	{
		if(ht->table[h]->key == key)
			return ht->table[h]->value;
		h = (h + 1) % HASH_SIZE;
	}
}
