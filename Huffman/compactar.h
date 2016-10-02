#pragma once
#ifndef TAMANHO_BYTE
#define TAMANHO_BYTE 8
#endif // TAMANHO_BYTE
#include "f_hashtable.h"

unsigned char set_bit(unsigned char c, int i);

/* FUNÇÃO UTILIZADA PARA SETAR UM DETERMINADO BIT EM UM CHAR
   RETORNA UM CARACTER JÁ COM O BIT DESEJADO SETADO */
unsigned short is_bit_set(unsigned short c, int i);

/* FAZ O DESLOCAMENTO DOS 3 BITS DE LIXO PARA OS TRÊS PRIMEIROS BITS DO SHORT
   RETORNA OS 3 BITS DE LIXO POSICIONADO NOS TRÊS PRIMEIROS BITS DE UM UNSIGNED SHORT*/
unsigned short converter_lixo(unsigned short lixo);

/* ESCREVE O LIXO E O TAMANHO*/
void escrever_cabecalho_inicio(unsigned short cabecalho_inicial, FILE* arquivo);

/* ESCREVE A ÁRVORE EM PRÉ-ORDEM NO ARQUIVO */
void escrever_arvore(Node *cabeca, FILE *arquivo);

/* ESCREVE O TEXTO JÁ COMPACTADO NO ARQUIVO */
void escrever_texto(unsigned short int *array_texto, int tamanho, FILE *arquivo);

void criar_array_binarios(Hashtable *ht, unsigned char *txt, int tam_txt, unsigned short *array_binario, unsigned int freq_x_profundidade);
