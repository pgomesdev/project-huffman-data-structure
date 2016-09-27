#pragma once
#include "f_arvore.h"

Node *criar_Node_NULL();

int esta_Vazia(Node *cabeca);

Node *add_Node_meio_ordenado(Node *cabeca, char letra, int num);

void print_lista_Frequencia(Node *cabeca);

Node *criar_lista_Frequencia(Node *cabeca, char *txt, int tam);

int calcular_tam_lista(Node *cabeca);
