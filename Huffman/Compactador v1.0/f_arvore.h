#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct Node Node;

struct Node
{
    int num;
    char letra;
    Node *proximo_node;
    Node *filho_esquerda;
    Node *filho_direita;
};

Node *Criar_Node_NULL();

int esta_Vazia(Node *cabeca);

Node *add_Node_pai_ordenado(Node *cabeca);

Node *add_Node_meio_ordenado(Node *cabeca, char letra, int num);

