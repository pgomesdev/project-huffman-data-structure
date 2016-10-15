#include "f_md5.h"

char *gerar_md5(const char *str, int length)
{
    int n;
    MD5_CTX c;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    MD5_Init(&c);

    while (length > 0)
    {
        if (length > 512)
        {
            MD5_Update(&c, str, 512);
        }
        else
        {
            MD5_Update(&c, str, length);
        }
        length -= 512;
        str += 512;
    }

    MD5_Final(digest, &c);

    for (n = 0; n < 16; ++n)
    {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }

    return out;
}

void obter_nome_ext_arq(char *url, unsigned char *nome_ex, unsigned char *nome_arquivo)
{
    int barra = 0, ponto = 0, i, j=0, url_final=0;

    while(url[url_final] != '\0')
    {
        if(url[url_final] == '/')
            barra = url_final;
        if(url[url_final] == '.')
            ponto = url_final;
        url_final++;
    }

    ///Porque nao coloquei essa atribuição do 'for' dentro do while? R.: Caso o endereco url contenha ponto antes de chegar na extencao ex.:  pasta//arquivos.fullhd.1080p//filme.avi
    for(i = ponto ; i < url_final ; i++)
    {
        nome_ex[j] = url[i+1];      j++;
    }

    j = 0;
    if(barra == 0)
        barra--; ///caso em que o arquivo nao esta em pasta, logo ele nao tem barra, e o inteiro barra no array aponta para a primeira letra do arquivo.
    for(i = barra ; i < ponto ; i++)
    {
        nome_arquivo[j] = url[i+1];      j++;
    }

    nome_arquivo[j-1] = '\0'; /// na ultima posicao do nome_arquivo tem um ponto, estou colocando um '\0' para sinalizar o termino;
}

unsigned char calcular_tam_nome_arq(unsigned char *nome_arquivo)
{
    unsigned char i = 0;
    while(nome_arquivo[i] != '\0')
    {
        printf("[%c]", nome_arquivo[i]);
        i++;
    }
    return i;
}

unsigned char calcular_tam_ext(unsigned char *nome_ex)
{
    unsigned char i = 0;
    while(nome_ex[i] != '\0')
        i++;

    if(i > 6)
    {
        puts("\nTamanho de extencao Invalido, digite uma extencao ate 6 caracteres!\n");       exit(0);
    }
    else
         return i << 5;
}

void escrever_tam_ext(unsigned char tam_ext, FILE *arquivo)
{
    fputc(tam_ext, arquivo);
}

void escrever_extencao(unsigned char *nome_ext, FILE *arquivo)
{
    int i = 0;
    while(nome_ext[i] != '\0')
    {
        fputc(nome_ext[i], arquivo);
        i++;
    }
}

void escrever_senha_md5(char *senha_md5, FILE *arquivo)
{
    int i = 0;
    while(senha_md5[i] != '\0')
    {
        fputc(senha_md5[i], arquivo);
        i++;
    }
}

void escrever_tam_nome_arquivo(unsigned char tam_nome_arq, FILE *arquivo)
{
        fputc(tam_nome_arq, arquivo);
}

void escrever_nome_arquivo(unsigned char *nome_arq, FILE *arquivo)
{
    int i = 0;
    while(nome_arq[i] != '\0')
    {
        fputc(nome_arq[i], arquivo);
        i++;
    }
}


