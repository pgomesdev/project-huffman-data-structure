#include "f_arvore.h"

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
            printf("Letra:[\\n] Freq:[%d] Prof:[%d]\n", cabeca->letra, cabeca->num,cabeca->profundidade);
        }
        else
        {
            printf("Letra:[%c] Freq:[%d] Prof:[%d]\n", cabeca->letra, cabeca->num, cabeca->profundidade);
        }
        print_pre_ordem_arvore(cabeca->filho_esquerda);
        print_pre_ordem_arvore(cabeca->filho_direita);
    }
}

void calcular_profundidade_nodes(Node *cabeca, int profundidade)
{
    if(cabeca != NULL)
    {
        if(cabeca->letra == '*')
        {
            cabeca->profundidade = profundidade;
            calcular_profundidade_nodes(cabeca->filho_esquerda, ++profundidade);
            calcular_profundidade_nodes(cabeca->filho_direita, profundidade);
        }
        else
        {
            cabeca->profundidade = profundidade;

        }
    }
}

unsigned short calcular_lixo(Node *cabeca, unsigned short lixo)
{
    if(cabeca != NULL)
    {
        if(cabeca->letra != '*')
        {
            lixo = lixo + (cabeca->profundidade * cabeca->num);
        }
        else
        {
            lixo = calcular_lixo(cabeca->filho_esquerda, lixo);
            lixo = calcular_lixo(cabeca->filho_direita, lixo);
        }
    }
    return lixo%8;
}

unsigned short calcular_tam_arvore(Node *cabeca, unsigned short tam)
{
    if(cabeca != NULL)
    {
        tam++;
        tam = calcular_tam_arvore(cabeca->filho_esquerda, tam);
        tam = calcular_tam_arvore(cabeca->filho_direita, tam);
    }
    return tam;
}
