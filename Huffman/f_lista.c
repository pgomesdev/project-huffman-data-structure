#include "f_lista.h"

Node *criar_Node_NULL()
{
    return NULL;
}

int esta_Vazia(Node *cabeca_lista)
{
    return (cabeca_lista==NULL);
}

Node *add_Node_meio_ordenado(Node *cabeca_lista, unsigned char letra, unsigned long long int num, Node *progresso)
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

    if(esta_Vazia(cabeca_lista) == 1)
    {
        return newnode;
    }
    else
    {
        atual = cabeca_lista;
        anterior = atual;
        while(atual != NULL)
        {
            if(progresso->num > 100 && progresso->num/10 <101)
                printf("ordenando_lista PROGRESSO: %lld%%\n", progresso->num/10);
            progresso->num++;
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

Node *criar_lista_Frequencia(Node *cabeca_lista, FILE *arquivo_texto)
{
    ///comandos para progresso:
    Node *progresso = (Node*)malloc(sizeof(Node));
    progresso->letra = 0;
    progresso->num = 0;
    progresso->profundidade = 0;
    progresso->proximo_node = NULL;
    progresso->filho_esquerda = NULL;
    progresso->filho_direita = NULL;

    unsigned long long int i, j;
    unsigned long long int num, aux;
    unsigned char letra;
    Node *atual = cabeca_lista;

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

        if(cabeca_lista == NULL)
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
    }
    return atual;
}

void print_lista_Frequencia(Node *cabeca_lista)
{
    if(cabeca_lista != NULL)
    {
        if(cabeca_lista->letra == '\n')
        {
            printf("[\\n]\n");
        }
        else
        {
            printf("[%c]\n", cabeca_lista->letra);
        }
        print_lista_Frequencia(cabeca_lista->proximo_node);
    }
}

int calcular_tam_lista(Node *cabeca_lista)
{
    int tam = 0;
    Node *atual = cabeca_lista;
    while(atual != NULL)
    {
        tam++;
        atual = atual->proximo_node;
    }

    return tam;
}

