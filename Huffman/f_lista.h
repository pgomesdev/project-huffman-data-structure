/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once
#include "f_arvore.h"// Arquivo que possui as definicões iniciais da Árvore de Huffman

/// NESSA BIBLIOTECA ESTÃO AS FUNÇÕES PARA A LISTA DE HUFFMAN

//Função que não recebe variáveis;
//e devolve um ponteiro para Nós, inicializado com NULL
Node *criar_Node_NULL();

//Função que recebe: a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca_lista
//e devolve 0, se a lista passada conter algum elemento,
//ou devolve um inteiro, se a lista estiver vazia.
int esta_vazia(Node *cabeca_lista);

//Função que recebe: a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca_lista;
//um caractere a ser inserido na lista, armazenado como unsigned char na variável letra;
//a frequência desse caractere no texto, armazenado no long long int num;
//e devolve um ponteiro para Nós como o primeiro nó da nova lista, contendo o novo elemento.
//o Nó progresso é apenas para print do loading, em progresso->num temos o progresso atual.
Node *adicionar_node(Node *cabeca_lista, unsigned char letra);

//Função que recebe: a lista de nós de Huffman (preferencialmente vazia), como um ponteiro, apontada por cabeca_lista;
//o texto a ser analizado, como uma String, que será apontada por txt;
//o tamanho do texto recebido, armazenado no long long int tam, onde tam >= 0;
//e devolve a lista de nós de Huffman, com elementos ordenados pela frequência do caractere, de acordo com o texto passado.
Node *criar_lista_frequencia(Node *cabeca_lista, FILE *arquivo_texto);

void quicksort(int *lista, int tamanho);
