/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once

#include "f_arvore.h"// Arquivo que possui as definicões iniciais da Árvore de Huffman

Node *criar_Node_NULL();

int esta_Vazia(Node *cabeca_lista);

Node *add_Node_meio_ordenado(Node *cabeca_lista, unsigned char letra, int num);

void print_lista_Frequencia(Node *cabeca_lista);

Node *criar_lista_Frequencia(Node *cabeca_lista, unsigned char *txt, int tam);

int calcular_tam_lista(Node *cabeca_lista);

void lista_de_folhas(Node *cabeca_lista);

