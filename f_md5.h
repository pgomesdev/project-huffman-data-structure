#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

char *gerar_md5(const char *str, int length);

unsigned char verifica_extencao(char *url);
