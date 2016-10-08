#include "f_arvore_binaria.h"

ArvB *criar_arv_binaria()
{
    return NULL;
}

ArvB *inserir_elemento(ArvB *cabeca, int valor)
{
    ArvB *novo = (ArvB*)malloc(sizeof(ArvB));

    if(novo == NULL)
    {
        printf("Erro ao alocar no de valor %d\n", valor);
        exit(0);
    }
    else
    {
        novo->valor = valor;
        novo->filho_direita = NULL;
        novo->filho_esquerda = NULL;
        if(cabeca == NULL)
        {
            cabeca = novo;
            return cabeca;
        }
        else
        {
            ArvB *atual = cabeca;
            atual = busca_elemento_add(cabeca, valor);
            if(valor > atual->valor)
                atual->filho_direita = novo;
            else
                atual->filho_esquerda = novo;
            return cabeca;
        }

    }
}

ArvB *busca_elemento_add(ArvB *cabeca, int valor)
{
    if(cabeca != NULL)
    {
        if(valor > cabeca->valor)
        {
            if(cabeca->filho_direita == NULL)
                return cabeca;
            else
                cabeca = busca_elemento_add(cabeca->filho_direita, valor);
        }
        else
        {
            if(cabeca->filho_esquerda == NULL)
                return cabeca;
            else
                cabeca = busca_elemento_add(cabeca->filho_esquerda, valor);
        }
    }
    return cabeca;
}

ArvB *remover_ArvB_FULL(ArvB *cabeca)
{
    if(cabeca == NULL)
    {

        return NULL;
    }
    else
    {
        cabeca->filho_esquerda = remover_ArvB_FULL(cabeca->filho_esquerda);
        cabeca->filho_direita = remover_ArvB_FULL(cabeca->filho_direita);
        free(cabeca);
        return NULL;
    }
}

void print_pre_ordem_arvore(ArvB *cabeca)
{
    if(cabeca != NULL)
    {
        printf("[%d]", cabeca->valor);
        print_pre_ordem_arvore(cabeca->filho_esquerda);
        print_pre_ordem_arvore(cabeca->filho_direita);
    }
}

int busca_elemento_cont(ArvB *cabeca, int valor, int cont)
{
    if(cabeca != NULL)
    {
        if(valor > cabeca->valor)
            cont = busca_elemento_cont(cabeca->filho_direita, valor, ++cont);
        else if(valor < cabeca->valor)
            cont = busca_elemento_cont(cabeca->filho_esquerda, valor, ++cont);
        else
            return cont;
    }
    return cont;
}
