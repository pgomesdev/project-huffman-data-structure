#pragma once
#include "f_arvore.h"
#ifndef TAMANHO_BYTE
#define TAMANHO_BYTE 8
#endif // TAMANHO_BYTE

unsigned char obter_lixo(FILE *arquivo);

unsigned short obter_tamanho_arvore(FILE *arquivo);

void obter_arvore(unsigned char *arvore, FILE *arquivo);

int obter_tamanho_texto(FILE *arquivo);

void escrever_texto_compactado(FILE *arquivo, int *texto_compactado);

void descompactar_texto(Node *cabeca, int *texto_compactado, FILE *novo_arquivo, int tamanho_texto)
