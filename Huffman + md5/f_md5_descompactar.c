#include "f_md5_descompactar.h"

unsigned char obter_tam_ext_descomp(FILE *arquivo)
{
    unsigned char c;
    c = fgetc(arquivo);

    return c >> 5;
}

void obter_nome_ext_arq_descomp(FILE *arquivo, unsigned char *nome_extencao,unsigned char tam_ext)
{
    int i;
    for(i = 0 ; i < tam_ext ; i++)
    {
        nome_extencao[i] = fgetc(arquivo);
    }
    nome_extencao[tam_ext] = '\0';
}

void verificar_senha_md5_descomp(FILE *arquivo, char *senha)
{
    int i;
    char senha_md5_arq[32];
    char *senha_md5 = gerar_md5(senha, strlen(senha));
    for(i = 0 ; i < 32 ; i++)
    {
        senha_md5_arq[i] = fgetc(arquivo);
    }
    senha_md5_arq[32] = '\0';
    if(strcmp(senha_md5,senha_md5_arq) != 0)
    {
        puts("\n---Senha nao confere!---\n");
        exit(0);
    }
    else
        return;
}

unsigned char obter_tam_nome_arquivo_descomp(FILE *arquivo)
{
    unsigned char c = fgetc(arquivo);
    return c;
}

void obter_nome_arquivo_descomp(FILE *arquivo, unsigned char *nome_arquivo, unsigned char tam_nome_arquivo)
{
    int i;
    for(i = 0 ; i < tam_nome_arquivo ; i++)
    {
        nome_arquivo[i] = fgetc(arquivo);
    }

    nome_arquivo[tam_nome_arquivo] = '\0';
}






























