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

unsigned char verifica_extencao(char *url)
{
    int final = 0, ponto;
    unsigned char tam_ex;

    while(url[final] != '\0')
    {
        if(url[final] == '.')
            ponto = final;
        final++;
    }

    if(final-(ponto+1) > 6)
    {
        puts("\nExtencao maior que 6\n");
        return 0;
    }
    else
    {
        tam_ex = final-(ponto-1);
        return tam_ex << 5;
    }
}
