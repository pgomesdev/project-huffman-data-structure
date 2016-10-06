/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once

#include "f_arvore.h"// Arquivo que possui as definicões iniciais da Árvore de Huffman

#define MAX_TABLE 256// Numero maximo de caracteres do ASCII e a quantidade de chaves

#include <stdio.h>// Biblioteca para abrir arquivos
#include <stdlib.h>// Biblioteca padrão de Entrada e Saida do C

/// NESSA BIBLIOTECA ESTÃO A DEFINIÇÃO DA HASHTABLE E AS FUNÇÕES PARA A TABELA DE DISPERSÃO

typedef struct element Element;// Para se referir a estrutura nó usar:Element
typedef struct hashtable Hashtable;// Para se referir a estrutura nó usar:Hashtable

/// NÓS DA LISTA DE UMA CHAVE
struct element
{
    unsigned short value;// Bit para codificar o caracter
    Element *next_element;// Proximo elemento da lista
};

/// ARRAY DE CHAVES DA HASHTABLE
struct hashtable
{
    Element *table[MAX_TABLE];//Array de ponteiros para listas encadeadas com uma posição para cada caracter do ASCII
};

//Função que não recebe variáveis
//e devolve um ponteiro para Hashtables, contendo uma hashtable alocada e em cada posicão do array, uma lista vazia.
Hashtable *create_hashtable();

//Função que não recebe variáveis
//e devolve um ponteiro para Elements, inicializado com NULL.
Element *criar_node_hash_null();

//Funcao que recebe: a Hashtable, como um ponteiro para tabelas de dispersão, apontada por ht
//e devolve um ponteiro para tabelas de dispersão, apontando para NULL, apos ter liberado a memoria alocada para a Hash.
//FUNÇÃO RECURSIVA
Hashtable *remove_hashtable(Hashtable *ht);

void construir_ht(Node *cabeca_arvore, Element *lista, Hashtable *ht);

void print_ht(Hashtable *ht);
