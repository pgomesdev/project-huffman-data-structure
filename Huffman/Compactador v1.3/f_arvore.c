#include "f_arvore.h"


Node *criar_Node_NULL()
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
    Node *anterior;
    int aux = 0;

    if(cabeca == NULL)
    {
        puts("Erro ao criar PAI, argumento_1 == NULL!\n");
        return cabeca;
    }
    else if(atual->proximo_node == NULL)
    {
        ///"Erro ao criar PAI pois a funзгo tem apenas 1 nу!
        return cabeca;
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
            anterior = atual;

            while(atual != NULL)
            {
                if(newnode->num > atual->num)
                {
                    if(aux > 0)
                    {
                        ///quando aux é maior que 0 é necessario ultilizar uma variavel anterior a atual,
                        ///para que a lista siga no seu apontamento normal sem falhas
                        anterior->proximo_node = atual;
                    }
                    newnode->proximo_node = atual->proximo_node;
                    atual->proximo_node = newnode;
                    anterior = atual;
                    atual = newnode->proximo_node;
                    aux++;
                }
                else
                {
                    break;
                }
            }
            if(aux == 0)
            {
                return newnode;
            }
            else
            {
                return newnode->filho_direita->proximo_node;
            }

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
    return cabeca;
}

Node *criar_arvore_huffman(Node *cabeca)
{
    Node *atual = add_Node_pai_ordenado(cabeca);

    if(atual == cabeca)
    {
        return atual;
    }
    else
    {
        return criar_arvore_huffman(atual);
    }
}

void print_pre_ordem_arvore(Node *cabeca)
{
    if(cabeca != NULL)
    {
        if(cabeca->letra == '\n')
        {
            printf("[\\n]");
        }
        else
        {
            printf("[%c]", cabeca->letra);
        }
        print_pre_ordem_arvore(cabeca->filho_esquerda);
        print_pre_ordem_arvore(cabeca->filho_direita);
    }
}

Node *criar_lista_Frequencia(Node *cabeca, char *txt, int tam)
{
    int i, j, num, aux;
    char letra;
    Node *atual = cabeca;
    for(i=0 ; i<tam ; i++)
    {
        ///VARIAVEL "LETRA" RECEBE O PROXIMO CARACTERE DO TEXTO PARA ANALIZAR.  OBS.: "txt[]" Й UM BUFFER CONTENDO O TEXTO.
        letra = txt[i];

        ///CONTAGEM "num" É ZERADA PARA NOVA LETRA ANALIZADA!    OBS.: "num" == NUMERO DE VEZES QUE A LETRA ANALIZADA REPETE NO TEXTO!
        num = 0;
        aux = 0;
        ///ESTE LOOP DECOBRE QUANTAS VEZES A LETRA ANALIZADA FOI REPETIDA NO TEXTO!
        for(j=0 ; j<tam ; j++)
        {
            if(letra == txt[j])
            {
                num++;
            }
        }

        if(cabeca == NULL)
        {
            cabeca = add_Node_meio_ordenado(cabeca, letra, num);
            atual = cabeca;
        }
        else
        {
            while(atual != NULL)
            {
                if(atual->letra != letra)
                {
                        atual = atual->proximo_node;
                }
                else
                {
                    atual = NULL;
                    aux++;
                }
            }
            if(aux == 0)
            {
                cabeca = add_Node_meio_ordenado(cabeca, letra, num);
            }
            atual = cabeca;
        }
    }
    return atual;
}

void print_lista(Node *cabeca)
{
    if(cabeca != NULL)
    {
        if(cabeca->letra == '\n')
        {
            printf("[\\n][%d]\n", cabeca->num);
        }
        else
        {
            printf("[%c][%d]\n", cabeca->letra, cabeca->num);
        }
        print_lista(cabeca->proximo_node);
    }
}
