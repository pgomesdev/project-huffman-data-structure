#pragma once
#include "f_arvore.h"
#ifndef TAMANHO_BYTE
#define TAMANHO_BYTE 8
#endif // TAMANHO_BYTE

unsigned char obter_lixo(FILE *arquivo);

unsigned short obter_tamanho_arvore(FILE *arquivo);

void obter_arvore(unsigned char *array_arvore, FILE *arquivo);

unsigned int contar_tamanho_array_binarios_descompactar(FILE *arquivo, unsigned short tam_cabecalho);

Node *criar_arvore_descompactacao(Node *arvore_huffman, unsigned char *array_arvore, unsigned short tam_array_arvore);

void escrever_array_compactado(FILE *arquivo, unsigned short *array_binarios_descompactar, unsigned int tam_array_b_descompactar, unsigned short tam_cabecalho);

void descompactar_texto(Node *cabeca, unsigned short *texto_compactado, FILE *novo_arquivo, int tamanho_texto);

