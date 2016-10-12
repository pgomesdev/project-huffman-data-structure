/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once

/// INSTRUÇÃO PARA O COMPILADOR SÓ DEFINIR TAMANHO_BYTE = 8 SE AINDA NÃO FOI DEFINIDO
#ifndef TAMANHO_BYTE
#define TAMANHO_BYTE 8
#endif // TAMANHO_BYTE

#include "f_hashtable.h"// Biblioteca propria com TAD de Tabela de Dispersão

/// NESSA BIBLIOTECA ESTÃO DEFINIDAS AS FUNÇÕES DIVERSAS A SEREM UTILIZADAS NA COMPRESSÃO

//Função que recebe: uma sequencia de 8 bits, salvos na variavel c, um unsigned char;
//um posição inteira, salvo na variavel i, onde 0<=i<=7;
//e devolve uma sequencia de 8 bits, identica a inicial; porém na posição indicada, o bit será 1.
//Se i > 7, retornará uma sequencia igual à inicial.
unsigned char set_bit(unsigned char c, int i);

//Função que recebe: uma sequencia de 16 bits, salvos na variavel c, um unsigned short;
//um posição inteira, salvo na variavel i, onde 0<=i<=15;
//e devolve uma sequencia de 16 bits diferente da inicial, pois nas posições diferentes de i, o bit será 0.
//Mas o bit da posição indicada, é mantido. A devolução ocorre no formato unsigned short.
//Se i > 15, retornará uma sequencia igual à 0.
unsigned short is_bit_set(unsigned short c, int i);

//Função que recebe: um inteiro lixo, salvo em unsigned short, onde 0<=lixo<=7
//e devolve um unsigned short, onde lixo será escrito nos três primeiros bits.
//Se lixo > 7, será escrito temp = lixo % 8, podendo comprometer a aplicação.
unsigned short converter_lixo(unsigned short lixo);

//Função que recebe: uma sequencia de 16 bits, salvos na variavel cabecalho_inicial, um unsigned short;
//um ponteiro para um tipo FILE, representado o arquivo .huff, onde arquivo != NULL;
//e que não possui nenhuma devolução.
//Sua ação é imprimir no arquivo, os 2 bytes do cabeçalho_inicial.
void escrever_cabecalho_inicio(unsigned short cabecalho_inicial, FILE* arquivo);

//Função que recebe: a Árvore de Huffman, como um ponteiro para o nó raiz, apontada por cabeca;
//um ponteiro para um tipo FILE, representado o arquivo .huff, onde arquivo != NULL;
//e que não possui nenhuma devolução. FUNÇÃO RECURSIVA.
//Sua ação é imprimir no arquivo, a árvore em pré-ordem.
void escrever_arvore(Node *cabeca, FILE *arquivo);

//Função que recebe: uma sequencia de bits, apontada por array_texto, onde cada bit ocupa uma posição;
//o tamanho que a sequencia tem, salvo em tamanho, no formato long long int;
//um ponteiro para um tipo FILE, representado o arquivo .huff, onde arquivo != NULL;
//e que não possui nenhuma devolução.
//Sua ação é imprimir no arquivo, o array_texto, onde cada elemento ocupará um bit.
void escrever_texto(unsigned char *array_texto, unsigned long long int tamanho, FILE *arquivo);

//Função que recebe: uma tabela de dispersão, apontada por ht, representando a codificação de cada caracter;
//uma String, apontada por txt, representando o texto a ser codificado;
//o tamanho da String a ser passada, salvo em tam_txt, no formato long long int;
//uma sequencia de bits, apontada por array_binario, onde seus elementos foram declarados;
//o tamanho que a sequencia deverá ter, salvo em freq_x_profundidade, no formato long long int;
//e que não possui nenhuma devolução.
//Sua ação é escrever em array_binario, a String passada, de acordo com a codificação da tabela de dispersão.
void criar_array_binarios(Hashtable *ht, FILE *arquivo, unsigned char *array_binario, unsigned long long int freq_x_profundidade);
