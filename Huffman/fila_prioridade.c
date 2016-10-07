#include "fila_prioridade.h"

FilaPrioridade criar_fila_prioridade(FilaPrioridade *nova_fila)
{
    nova_fila->primeiro = NULL;
    return nova_fila;
}

void enqueue(FilaPrioridade *pq, char letra, int prioridade);

Node* dequeue(FilaPrioridade *pq);

int maximum(FilaPrioridade *pq);

int fila_esta_vazia(FilaPrioridade *pq);

int esta_vazia(Node *cabeca_lista)
{
    return (cabeca_lista == NULL);
}

Node *adicionar_no_meio_ordenado(Node *cabeca_lista, unsigned char letra, unsigned long long int num)
{
    Node *atual, *anterior;
    Node *newnode = (Node*) malloc(sizeof(Node));

    if(esta_Vazia(newnode))
    {
        puts("Erro ao alocar memoria!\n");
        exit(0);
    }

    newnode->letra = letra;
    newnode->num = num;
    newnode->profundidade = 0;
    newnode->proximo_node = NULL;
    newnode->filho_esquerda = NULL;
    newnode->filho_direita = NULL;

    if(esta_Vazia(cabeca_lista))
    {
        return newnode;
    }
    else
    {
        atual = cabeca_lista;
        anterior = atual;
        while(atual != NULL)
        {
            if(newnode->num <= atual->num)
            {
                newnode->proximo_node = atual;

                if(atual == cabeca_lista)
                {
                    return newnode;
                }
                else
                {
                    anterior->proximo_node = newnode;
                    return cabeca_lista;
                }
            }

            anterior = atual;
            atual = atual->proximo_node;

            if(atual == NULL)
            {
                anterior->proximo_node = newnode;
                return cabeca_lista;
            }
        }
    }
    return cabeca_lista;
}

Node *criar_lista_frequencia(Node *cabeca_lista, FILE *arquivo_texto)
{
    unsigned char letra;
    Node *atual = cabeca_lista;

    unsigned long long int frequencia[256] = {0};

    while((letra = fgetc(arquivo_texto)) != EOF)
    {
        if(feof(arquivo_texto))
            break;

        frequencia[letra]++;
    }

    /*  if(cabeca_lista == NULL)
        {
            cabeca_lista = add_Node_meio_ordenado(cabeca_lista, letra, num, progresso);
            atual = cabeca_lista;
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
                cabeca_lista = add_Node_meio_ordenado(cabeca_lista, letra, num, progresso);
            }
            atual = cabeca_lista;
        }
        if(tam >= 100)
        {
            if(i%((((tam/2)/2)/5)/5) == 0)
                printf("Criando lista_huffman PROGRESSO: [%lld%%]\n",(i*100/tam));
        }
    } */
    return atual;
}
