#pragma once
#include <stdlib.h>
#include <stdio.h>

void print_freq_c(char *freq, int tam);

void print_freq_i(int *freq, int tam);

void print_txt(char *txt, int tam);

int contar_tam_texto_char(FILE *arq);

FILE *abrir_Arquivo(char *url);

void limpar_array_i(int *arq, int tam);
void limpar_array_c(char *arq, int tam);
