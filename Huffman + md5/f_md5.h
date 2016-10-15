#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

char *gerar_md5(const char *str, int length);

void obter_nome_ext_arq(char *url, unsigned char *nome_ex, unsigned char *nome_arquivo);

unsigned char calcular_tam_nome_arq(unsigned char *nome_arquivo);

unsigned char calcular_tam_ext(unsigned char *nome_ex);

void escrever_tam_ext(unsigned char tam_ext, FILE *arquivo);

void escrever_extencao(unsigned char *nome_ext, FILE *arquivo);

void escrever_senha_md5(char *senha_md5, FILE *arquivo);

void escrever_tam_nome_arquivo(unsigned char tam_nome_arq, FILE *arquivo);

void escrever_nome_arquivo(unsigned char *nome_arq, FILE *arquivo);

