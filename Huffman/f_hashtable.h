/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once
#include "f_arvore.h"// Arquivo que possui as definicões iniciais da Árvore de Huffman
#include <stdio.h>// Biblioteca para abrir arquivos
#include <stdlib.h>// Biblioteca padrão de Entrada e Saida do C

/// NESSA BIBLIOTECA ESTÃO A DEFINIÇÃO DA HASHTABLE E AS FUNÇÕES PARA A TABELA DE DISPERSÃO

typedef struct elemento Elemento;// Para se referir a estrutura nó usar:Element

/// NÓS DA LISTA DE UMA CHAVE
struct elemento
{
    unsigned short valor;// Bit para codificar o caracter
    Elemento *proximo_elemetno;// Proximo elemento da lista
};

//Função que não recebe variáveis
//e devolve um ponteiro para Elements, inicializado com NULL.
Element *criar_hash_nula();

//Funcao que recebe: a Árvore de Huffman, como um ponteiro para o nó raiz, apontada por cabeca_arvore;
//um ponteiro para Elements, apontado por lista, que DEVE SER INICIALIZADO COM NULL, para ser utilizado na função;
//um ponteiro para Hashtable, apontado por ht, que DEVE JÁ ESTAR DECLARADO, para ser utilizado na função;
//e não possui devoluções. FUNÇÃO RECURSIVA.
//Sua ação é criar em ht, a lista de conversão para cada caracter, e retonar a lista para NULL
void construir_hash(Node *cabeca_arvore, Elemento *hash);
