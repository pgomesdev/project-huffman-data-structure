#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
typedef struct Node Node;

struct Node
{
    int num;
    char letra;
    Node *proximo_node;
    Node *filho_esquerda;
    Node *filho_direita;
};

Node *criar_Node_NULL();

int esta_Vazia(Node *cabeca);

Node *add_Node_pai_ordenado(Node *cabeca);

Node *add_Node_meio_ordenado(Node *cabeca, char letra, int num);

Node *criar_arvore_huffman(Node *cabeca);

void print_pre_ordem_arvore(Node *cabeca);

void print_lista(Node *cabeca);

Node *criar_lista_Frequencia(Node *cabeca, char *txt, int tam);
