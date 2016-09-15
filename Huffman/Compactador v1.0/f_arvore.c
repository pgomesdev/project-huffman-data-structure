#include "f_arvore.h"


Node *Criar_Node_NULL()
{
    return NULL;
}

int esta_Vazia(Node *cabeca)
{
    return (cabeca==NULL);
}

Node *add_Node_pai_ordenado(Node *cabeca)
{
    Node *atual = cabeca;
    int aux = 0;

    if(atual->proximo_node == NULL)
    {
        puts("Erro ao criar PAI pois a função tem apenas 1 no!\n");
        return atual;
    }
    else
    {
        Node *newnode = (Node*)malloc(sizeof(Node));

        if(newnode == NULL)
        {
            puts("Erro ao Alocar Memoria para addPAI!\n");
            exit(0);
        }
        else
        {
             newnode->num = (atual->num + atual->proximo_node->num);
             newnode->letra = '*';
             newnode->filho_esquerda = atual;
             newnode->filho_direita = atual->proximo_node;

             newnode->proximo_node = newnode->filho_direita->proximo_node;
             atual = newnode->proximo_node;

             while(atual != NULL)
             {
                 if(newnode->num > atual->num)
                 {
                     newnode->proximo_node = atual->proximo_node;
                     atual->proximo_node = newnode;

                     atual = newnode->proximo_node;
                     aux++;
                 }
                 else if(aux == 0)
                 {
                     return newnode;
                 }
             }
             return newnode->filho_direita->proximo_node;

        }
    }
}

Node *add_Node_meio_ordenado(Node *cabeca, char letra, int num)
{
    Node *atual, *anterior;
    Node *newnode = (Node*)malloc(sizeof(Node));

    if(esta_Vazia(newnode) == 1)
    {
        puts("Erro ao alocar memoria!\n");
        exit(0);
    }

    newnode->letra = letra;
    newnode->num = num;
    newnode->proximo_node = NULL;
    newnode->filho_esquerda = NULL;
    newnode->filho_direita = NULL;

    if(esta_Vazia(cabeca) == 1)
    {
        return newnode;
    }
    else
    {
        atual = cabeca;
        anterior = atual;
        while(atual != NULL)
        {
            if(newnode->num <= atual->num)
            {
                newnode->proximo_node = atual;

                if(atual == cabeca)
                {
                    return newnode;
                }
                else
                {
                    anterior->proximo_node = newnode;
                    return cabeca;
                }
            }
            anterior = atual;
            atual = atual->proximo_node;
            if(atual == NULL)
            {
                anterior->proximo_node = newnode;
                return cabeca;
            }
        }
    }
}
