#pragma once
#include "f_arvore.h"

typedef struct fila Fila;

struct fila
{
    char letra;
    int prioridade;
    Fila* proximo_noh;
};

typedef struct filaprioridade FilaPrioridade;

struct filaprioridade
{
    Fila* primeiro;
};

FilaPrioridade criar_fila_prioridade(FilaPrioridade *nova_fila);

void enqueue(FilaPrioridade *pq, char letra, int prioridade);

Node* dequeue(FilaPrioridade *pq);

int maximum(FilaPrioridade *pq);

int fila_esta_vazia(FilaPrioridade *pq);

Node *criar_lista_frequencia(FILE *arquivo_texto);
