/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once

#include <stdlib.h>// Biblioteca para abrir arquivos
#include <stdio.h>// Biblioteca padrão de Entrada e Saida do C

/// BIBLIOTECA DE REGIONALIZAÇÃO DO C (UTILIZADA NO ARQUIVO MAIN)
#include <locale.h>

typedef struct Node Node;// Para se referir a estrutura nó usar:Node

/// DEFINIÇÃO DE NÓ DE ACORDO COM OS NÓS DEFINIDOS POR HUFFMAN NA ARVORE DE HUFFMAN
struct Node
{
    /// FREQUÊNCIA DA variavél LETRA NO TEXTO
    int num;
    
    /// CARACTERE CONTIDO NO TEXTO
    unsigned char letra;
    
    ///variavél QUE CONTÉM A PROFUNDIDADE DESSE NÓ NA ARVORE DE HUFFMAN
    int profundidade;
    
    Node *proximo_node;
    Node *filho_esquerda;
    Node *filho_direita;
};

Node *add_Node_pai_ordenado(Node *cabeca);

Node *criar_arvore_huffman(Node *cabeca);

void print_pre_ordem_arvore(Node *cabeca);

void calcular_profundidade_nodes(Node *cabeca, int profundidade);

unsigned short calcular_lixo(Node *cabeca, unsigned short lixo);

unsigned short calcular_tam_arvore(Node *cabeca, unsigned short tam);
