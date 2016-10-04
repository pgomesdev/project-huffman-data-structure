#include "f_arvore.h"

//Função que recebe a lista de nós de Huffman, como um ponteiro para nós, apontada por cabeca
//e devolve um ponteiro para o primeiro nó da nova lista, onde os dois primeiros nós da lista anterior, se tornaram uma árvore
Node *add_Node_pai_ordenado(Node *cabeca_arvore);

Node *add_Node_pai_ordenado(Node *cabeca_arvore)
{
    Node *atual = cabeca_arvore;
    Node *anterior;
    int aux = 0;

    if(cabeca_arvore == NULL)
    {
        puts("Erro ao criar PAI, argumento_1 == NULL!\n");
        return cabeca_arvore;
    }
    else if(atual->proximo_node == NULL)
    {
        ///"Erro ao criar PAI pois a lista tem apenas 1 no!
        return cabeca_arvore;
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
            newnode->profundidade = 0;
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

Node *criar_arvore_huffman(Node *cabeca_arvore)
{
    Node *atual = add_Node_pai_ordenado(cabeca_arvore);

    if(atual == cabeca_arvore)
    {
        return atual;
    }
    else
    {
        return criar_arvore_huffman(atual);
    }
}

void print_pre_ordem_arvore(Node *cabeca_arvore)
{
    if(cabeca_arvore != NULL)
    {
        printf("[%c]", cabeca_arvore->letra);
        print_pre_ordem_arvore(cabeca_arvore->filho_esquerda);
        print_pre_ordem_arvore(cabeca_arvore->filho_direita);
    }
}

void calcular_profundidade_nodes(Node *cabeca_arvore, int profundidade)
{
    if(cabeca_arvore != NULL)
    {
        if(cabeca_arvore->letra == '*')
        {
            cabeca_arvore->profundidade = profundidade;
            calcular_profundidade_nodes(cabeca_arvore->filho_esquerda, ++profundidade);
            calcular_profundidade_nodes(cabeca_arvore->filho_direita, profundidade);
        }
        else
        {
            cabeca_arvore->profundidade = profundidade;
        }
    }
}

unsigned long long calcular_lixo(Node *cabeca_arvore,unsigned long long int lixo)
{
    if(cabeca_arvore != NULL)
    {
        if(cabeca_arvore->letra != '*')
        {
            lixo = lixo + (cabeca_arvore->profundidade * cabeca_arvore->num);
        }
        else
        {
            lixo = calcular_lixo(cabeca_arvore->filho_esquerda, lixo);
            lixo = calcular_lixo(cabeca_arvore->filho_direita, lixo);
        }
    }
    return lixo;
}

unsigned short calcular_tam_arvore(Node *cabeca_arvore, unsigned short tam)
{
    if(cabeca_arvore != NULL)
    {
        tam++;
        tam = calcular_tam_arvore(cabeca_arvore->filho_esquerda, tam);
        tam = calcular_tam_arvore(cabeca_arvore->filho_direita, tam);
    }
    return tam;
}

Node *remove_arvore(Node *cabeca_arvore)
{
    if(cabeca_arvore == NULL)
    {

        return NULL;
    }
    else
    {
        cabeca_arvore->filho_esquerda = remove_arvore(cabeca_arvore->filho_esquerda);
        cabeca_arvore->filho_direita = remove_arvore(cabeca_arvore->filho_direita);
        free(cabeca_arvore);
        return NULL;
    }
}
