#include "f_lista.h"

Node *criar_Node_NULL()
{
    return NULL;
}

int esta_Vazia(Node *cabeca)
{
    return (cabeca==NULL);
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
    newnode->profundidade = 0;
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

Node *criar_lista_Frequencia(Node *cabeca, char *txt, int tam)
{
    int i, j, num, aux;
    char letra;
    Node *atual = cabeca;
    for(i=0 ; i<tam ; i++)
    {
        ///VARIAVEL "LETRA" RECEBE O PROXIMO CARACTERE DO TEXTO PARA ANALIZAR.  OBS.: "txt[]" e´ UM BUFFER CONTENDO O TEXTO.
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

void print_lista_Frequencia(Node *cabeca)
{
    if(cabeca != NULL)
    {
        if(cabeca->letra == '\n')
        {
            printf("[\\n][%d] %d\n", cabeca->num, cabeca->profundidade);
        }
        else
        {
            printf("[%c][%d] %d\n", cabeca->letra, cabeca->num, cabeca->profundidade);
        }
        print_lista_Frequencia(cabeca->proximo_node);
    }
}

int calcular_tam_lista(Node *cabeca)
{
    int tam = 0;
    Node *atual = cabeca;
    while(atual != NULL)
    {
        tam++;
        atual = atual->proximo_node;
    }

    return tam;
}
