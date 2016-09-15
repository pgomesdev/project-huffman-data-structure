#pragma once
#include <stdlib.h>
#include <stdio.h>

void print_freq(char *freq, long int tam);

void print_txt(char *txt, long int tam);

long int contar_tam_texto_char(FILE *arq);

FILE *abrir_Arquivo(char *url);

void limpar_array(char *arq, long int tam);
