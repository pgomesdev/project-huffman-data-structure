#pragma once
#include "f_arvore.h"
#define MAX_TABLE 256
#include <stdio.h>
#include <stdlib.h>

typedef struct element Element;
typedef struct hashtable Hashtable;

struct element
{
    unsigned short value;
    Element *next_element;
};

struct hashtable
{
    Element *table[MAX_TABLE];
};

Hashtable *create_hashtable();

Element *criar_node_hash_null();

Hashtable *remove_hashtable(Hashtable *ht);

void construir_ht(Node *cabeca_arvore, Element *lista, Hashtable *ht);

void print_ht(Hashtable *ht);
