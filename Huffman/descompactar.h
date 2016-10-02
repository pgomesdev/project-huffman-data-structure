#pragma once
#include "f_arvore.h"
#ifndef TAMANHO_BYTE
#define TAMANHO_BYTE 8
#endif // TAMANHO_BYTE

unsigned char obter_lixo(FILE *arquivo);

unsigned short obter_tamanho_arvore(FILE *arquivo);

void obter_arvore(unsigned char *arvore, FILE *arquivo);

int criar_tamanho_texto(FILE *arquivo);

//void descompactar_texto(unsigned short *texto_compactado, FILE *novo_arquivo);
