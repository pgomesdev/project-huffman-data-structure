/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once

#include "f_arvore.h"//Biblioteca própria onde está a definição de Nó da Arvore de Huffman e funções deste nó

/// INSTRUÇÃO PARA O COMPILADOR SÓ DEFINIR TAMANHO_BYTE = 8 SE AINDA NÃO FOI DEFINIDO
#ifndef TAMANHO_BYTE
#define TAMANHO_BYTE 8
#endif // TAMANHO_BYTE

/// NESSA BIBLIOTECA ESTÃO DEFINIDAS AS FUNÇÕES DIVERSAS A SEREM UTILIZADAS NA DESCOMPRESSÃO

//Função que recebe: um ponteiro para um tipo FILE, representado o arquivo .huff, onde arquivo != NULL
//e devolve um caracter, onde os três ultimos bits são os três primeiros bits do arquivo.
unsigned char obter_lixo(FILE *arquivo);

//Função que recebe: um ponteiro para um tipo FILE, representado o arquivo .huff, onde arquivo != NULL
//e devolve um unsigned short, com os dois primeiros bytes do arquivo, mas os três primeiros bits sendo 0.
unsigned short obter_tamanho_arvore(FILE *arquivo);

//Função que recebe: um array de caracteres, apontado por array_arvore, que devem estar declarados;
//um ponteiro para um tipo FILE, representado o arquivo .huff, onde arquivo != NULL;
//e que não possui devoluções.
//Sua ação é escrever em array_arvore, os caracteres que são nós da Arvore de Huffman, que estão no arquivo.
void obter_arvore(unsigned char *array_arvore, FILE *arquivo);

//Função que recebe: um ponteiro para um tipo FILE, representado o arquivo .huff, onde arquivo != NULL;
//um inteiro, sendo tam_cabecalho, a quatidade de caracteres iniciais a serem desconsiderados;
//e que devolve um long long int, sendo o número de bits até o fim do arquivo.
unsigned long long int contar_tamanho_array_binarios_descompactar(FILE *arquivo, unsigned short tam_cabecalho);

//Função que recebe: um ponteiro para nós, apontada por arvore_huffman;
//uma String, apontada por array_arvore, tendo os conteudos de cada nó;
//a quantidade de nós a serem criados, armazenada por tam_array_arvore;
//e devolve um ponteiro para nós, apontando para a raiz da arvore criada. FUNÇÃO RECURSIVA.
Node *criar_arvore_descompactacao(Node *arvore_huffman, unsigned char *array_arvore, unsigned short tam_array_arvore);

//Função que recebe: um ponteiro para um tipo FILE, representado o arquivo .huff, onde arquivo != NULL;
void escrever_array_compactado(FILE *arquivo, unsigned short *array_binarios_descompactar, 
                               unsigned int tam_array_b_descompactar, unsigned short tam_cabecalho);

void descompactar_texto(Node *cabeca, unsigned short *texto_compactado, FILE *novo_arquivo, int tamanho_texto);

