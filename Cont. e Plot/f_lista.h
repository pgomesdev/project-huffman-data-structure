#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "f_arvore_binaria.h"
#define MAX 1000

typedef struct node
{
    int item;
    struct node *proximo_node;
} Node;

Node *criar_lista_encadeada();

int esta_vazio(Node *lista);

Node *inserir_node(Node *lista, int item);

void print_lista(Node *lista);

int pesquisar_Node(Node *lista, int item);

Node *removeNode(Node *lista, int item);

Node *remove_lista(Node *lista);

void print_array(int *numeros);

void escrever_contagem(FILE *arquivo, ArvB *cabeca, Node *lista, int *numeros);

void quicksort(int *numeros, int inicio, int fim);
