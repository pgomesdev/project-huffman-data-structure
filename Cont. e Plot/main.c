#include <time.h>
#include "f_lista.h"
#include "f_arvore_binaria.h"

int main()
{
    ArvB *arvore = criar_arv_binaria();
    Node *lista = criar_lista_encadeada();
    int i, aux, numeros[MAX];
    srand( (unsigned)time(NULL) );

    for(i = 0 ; i < MAX ; i++)
    {
        aux = rand()%MAX;
        lista = inserir_node(lista, aux);
        arvore = inserir_elemento(arvore, aux);
        numeros[i] = aux;
    }

    print_array(numeros);
    puts("\nLista: ");
    print_lista(lista);
    puts("\nArvore Pre-Ordem: ");
    print_pre_ordem_arvore(arvore);

    FILE *arquivo = fopen("contagem.cvs", "w+");
    escrever_contagem(arquivo, arvore, lista, numeros);
    fclose(arquivo);
    remover_ArvB_FULL(arvore);
    remove_lista(lista);

    return 1;
}

