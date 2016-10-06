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
int esta_Vazia(Node *cabeca_lista);

//Função que recebe: a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca_lista;
//um caractere a ser inserido na lista, armazenado como unsigned char na variável letra;
//a frequência desse caractere no texto, armazenado no long long int num;
//e devolve um ponteiro para Nós como o primeiro nó da nova lista, contendo o novo elemento.
Node *add_Node_meio_ordenado(Node *cabeca_lista, unsigned char letra, unsigned long long int num);

//Função que recebe a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca_lista
//e que não possui nenhuma devolução. FUNÇÃO RECURSIVA.
//Sua ação é utilizar o printf para imprimir na tela o conteudo da Lista de Huffman. Se estiver vazia, não excuta ação.
// Modelo:   [%c]
void print_lista_Frequencia(Node *cabeca_lista);

//Função que recebe: a lista de nós de Huffman (preferencialmente vazia), como um ponteiro, apontada por cabeca_lista;
//o texto a ser analizado, como uma String, que será apontada por txt;
//o tamanho do texto recebido, armazenado no long long int tam, onde tam >= 0;
//e devolve a lista de nós de Huffman, com elementos ordenados pela frequência do caractere, de acordo com o texto passado.
Node *criar_lista_Frequencia(Node *cabeca_lista, unsigned char *txt, unsigned long long int tam);

//Função que recebe a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca_lista
//e devolve a quantidade de elementos na lista no formato inteiro.
//FUNÇÃO NÃO UTILIZADA
int calcular_tam_lista(Node *cabeca_lista);

