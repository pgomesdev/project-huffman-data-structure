#pragma once
#include "f_md5.h"

unsigned char obter_tam_ext_descomp(FILE *arquivo);

void obter_nome_ext_arq_descomp(FILE *arquivo, unsigned char *nome_extencao,unsigned char tam_ext);

void verificar_senha_md5_descomp(FILE *arquivo, char *senha);

unsigned char obter_tam_nome_arquivo_descomp(FILE *arquivo);

void obter_nome_arquivo_descomp(FILE *arquivo, unsigned char *nome_arquivo, unsigned char tam_nome_arquivo);
