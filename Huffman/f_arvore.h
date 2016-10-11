/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once
#include <stdlib.h>// Biblioteca para abrir arquivos
#include <stdio.h>// Biblioteca padrão de Entrada e Saida do C

/// NESSA BIBLIOTECA ESTÁ A DEFINIÇÃO DE NÓ DA ARVORE DE HUFFMAN E AS FUNÇÕES PARA A ARVORE

typedef struct Node Node;// Para se referir a estrutura nó usar:Node

/// DEFINIÇÃO DE NÓ DE ACORDO COM OS NÓS DEFINIDOS POR HUFFMAN NA ARVORE DE HUFFMAN
struct Node
{
<<<<<<< HEAD

    unsigned long long int frequencia; /// FREQUÊNCIA DA variavél LETRA NO TEXTO

=======
    unsigned long long int num; /// FREQUÊNCIA DA variavél LETRA NO TEXTO
>>>>>>> optimize
    unsigned char letra; /// CARACTERE CONTIDO NO TEXTO
    int profundidade; /// variavél QUE CONTÉM A PROFUNDIDADE DESSE NÓ NA ARVORE DE HUFFMAN
    Node *proximo_node; /// PONTEIRO PARA O PROXIMO NÓ NA LISTA DE HUFFMAN
    Node *filho_esquerda; /// PONTEIRO PARA O NÓ À ESQUERDA NA LISTA DE HUFFMAN
    Node *filho_direita; /// PONTEIRO PARA O NÓ À DIREITA NA LISTA DE HUFFMAN
};

//Função que recebe a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca
//e devolve um ponteiro para a raiz da Arvore de Huffman, correspondente à lista passada.
//FUNÇÃO RECURSIVA
Node *criar_arvore_huffman(Node *cabeca_arvore);

//Função que recebe: a Árvore de Huffman, como um ponteiro para nós, apontada por cabeca;
//um inteiro profundidade, que DEVE SER INICIALIZADO COM 0, para ser utilizado na função;
//e que não possui nenhuma devolução. FUNÇÃO RECURSIVA.
//Sua ação é escrever o item profundidade dos nós da Árvore de Huffman.
void calcular_profundidade_nodes(Node *cabeca_arvore, int profundidade);

//Função que recebe: a Árvore de Huffman, como um ponteiro para nós, apontada por cabeca_arvore;
//um long long int lixo, que DEVE SER INICIALIZADO COM 0, para ser utilizado na função;
//e devolve um long long int com o número de bits a serem escritos no arquivo compactado,
//de acordo com a Compactação utilizando a Árvore de Huffman. FUNÇÃO RECURSIVA.
<<<<<<< HEAD
unsigned long long calcular_tamanho_texto(Node *cabeca_arvore, unsigned long long int tamanho_texto);
=======
unsigned long long int calcular_tamanho_texto(Node *cabeca_arvore, unsigned long long int lixo);
>>>>>>> optimize

//Funcao que recebe: a Árvore de Huffman, como um ponteiro para o nó raiz, apontada por cabeca_arvore;
//um short tam, que DEVE SER INICIALIZADO COM 0, para ser utilizado na função;
//e devolve um short com o tamanho da Árvore de Huffman, ou seja, a quantidade de nós que a árvore possui.
//FUNÇÃO RECURSIVA
unsigned short calcular_tam_arvore(Node *cabeca_arvore, unsigned short tam);

//Funcao que recebe: a Arvore de Huffman, como um ponteiro para o no' raiz, apontada por cabeca_arvore
//e devolve um ponteiro para No's, apontando para NULL, apos ter liberado a memoria alocada para a arvore.
//FUNÇÃO RECURSIVA
Node *remove_arvore(Node *cabeca_arvore);
