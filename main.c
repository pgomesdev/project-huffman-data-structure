#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>


char *str2md5(const char *str, int length)
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

int main()
{
    int n = 10;
    char senha[n];
    char senha2[n];
    puts("Digite a senha: ");
    scanf("%s",senha);
    puts("Digite uma segunta senha para comparar: ");
    scanf("%s",senha2);
    char *output2 = str2md5(senha2, strlen(senha2));
    char *output = str2md5(senha, strlen(senha));

    if(strcmp(output,output2) == 0)
        puts("\n---Igual---\n");
    else
        puts("\n---Diferente---\n");
    puts("Primeira Senha md5: ");
    printf("%s\n", output);
    puts("Segunda Senha md5: ");
    printf("%s\n", output2);
    free(output);
    free(output2);
    return 0;
}
