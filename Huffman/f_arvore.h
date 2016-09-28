#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
typedef struct Node Node;

struct Node
{
    int num;
    unsigned char letra;
    int profundidade;
    Node *proximo_node;
    Node *filho_esquerda;
    Node *filho_direita;
};

Node *add_Node_pai_ordenado(Node *cabeca);

Node *criar_arvore_huffman(Node *cabeca);

void print_pre_ordem_arvore(Node *cabeca);

void calcular_profundidade_nodes(Node *cabeca, int profundidade);

unsigned short calcular_lixo(Node *cabeca, unsigned short lixo);

unsigned short calcular_tam_arvore(Node *cabeca, unsigned short tam);
