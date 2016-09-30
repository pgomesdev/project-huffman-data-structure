/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once

#include <stdlib.h>// Biblioteca para abrir arquivos
#include <stdio.h>// Biblioteca padrão de Entrada e Saida do C

/// BIBLIOTECA DE REGIONALIZAÇÃO DO C (UTILIZADA NO ARQUIVO MAIN)
#include <locale.h>

/// NESSA BIBLIOTECA ESTÁ A DEFINIÇÃO DE NÓ DA ARVORE DE HUFFMAN E AS FUNÇÕES PARA A ARVORE

typedef struct Node Node;// Para se referir a estrutura nó usar:Node

/// DEFINIÇÃO DE NÓ DE ACORDO COM OS NÓS DEFINIDOS POR HUFFMAN NA ARVORE DE HUFFMAN
struct Node
{
    /// FREQUÊNCIA DA variavél LETRA NO TEXTO
    int num;
    
    /// CARACTERE CONTIDO NO TEXTO
    unsigned char letra;
    
    /// variavél QUE CONTÉM A PROFUNDIDADE DESSE NÓ NA ARVORE DE HUFFMAN
    int profundidade;
    
    /// PONTEIRO PARA O PROXIMO NÓ NA LISTA DE HUFFMAN
    Node *proximo_node;
    
    /// PONTEIRO PARA O NÓ À ESQUERDA NA LISTA DE HUFFMAN
    Node *filho_esquerda;
    
    /// PONTEIRO PARA O NÓ À DIREITA NA LISTA DE HUFFMAN
    Node *filho_direita;
};

//Função que recebe a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca
//e devolve um ponteiro para o primeiro nó da nova lista, onde os dois primeiros nós da lista anterior, se tornaram uma árvore
Node *add_Node_pai_ordenado(Node *cabeca);

//Função que recebe a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca
//e devolve um ponteiro para a raiz da Arvore de Huffman, correspondente à lista passada.
//FUNÇÃO RECURSIVA
Node *criar_arvore_huffman(Node *cabeca);

void print_pre_ordem_arvore(Node *cabeca);

//Função que recebe: a Árvore de Huffman, como um ponteiro para nós, apontada por cabeca;
//um inteiro profundidade, que DEVE SER INICIALIZADO COM 0, para ser utilizado na função;
//e que não possui nenhuma devolução. FUNÇÃO RECURSIVA.
//Sua ação é escrever o item profundidade dos nós da Árvore de Huffman.
void calcular_profundidade_nodes(Node *cabeca, int profundidade);

unsigned short calcular_lixo(Node *cabeca, unsigned short lixo);

unsigned short calcular_tam_arvore(Node *cabeca, unsigned short tam);
