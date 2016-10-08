#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_binaria ArvB;

struct arvore_binaria
{
    int valor;
    ArvB *filho_esquerda;
    ArvB *filho_direita;
};

ArvB *criar_arv_binaria();

ArvB *inserir_elemento(ArvB *cabeca, int valor);

ArvB *busca_elemento_add(ArvB *cabeca, int valor);

ArvB *remover_ArvB_FULL(ArvB *cabeca);

void print_pre_ordem_arvore(ArvB *cabeca);

int busca_elemento_cont(ArvB *cabeca, int valor, int cont);
