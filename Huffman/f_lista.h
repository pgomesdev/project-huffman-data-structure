/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once
#include "f_arvore.h"// Arquivo que possui as definicões iniciais da Árvore de Huffman
#include "f_hashtable.h"

/// NESSA BIBLIOTECA ESTÃO AS FUNÇÕES PARA A LISTA DE HUFFMAN

typedef struct array_freq Hash_Freq;

//Função que não recebe variáveis;
//e devolve um ponteiro para Nós, inicializado com NULL
Node *criar_Node_NULL();

Hash_Freq *criar_array_freq();

void contar_freq_char(FILE *arquivo, Hash_Freq *hf);

//Função que recebe: a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca_lista
//e devolve 0, se a lista passada conter algum elemento,
//ou devolve um inteiro, se a lista estiver vazia.
int esta_Vazia(Node *cabeca_lista);

void print_hash_freq(Hash_Freq *hf);

void Quick_Sort(Hash_Freq *hf, int inicio, int fim);

void criar_novo_hf(Hash_Freq *hf, Hash_Freq *novo_hf, short tam__novo_hf);

short tam__novo_hf(Hash_Freq *hf);

Node *criar_lista_huffman(Hash_Freq *hf, short tam_hf);

void print_lista(Node *lista);

Hash_Freq *remove_hash_Freq(Hash_Freq *hf);
