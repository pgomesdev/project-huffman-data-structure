#ifndef TAMANHO_BYTE
#define TAMANHO_BYTE 8
#endif // TAMANHO_BYTE

/* FUNÇÃO UTILIZADA PARA SETAR UM DETERMINADO BIT EM UM CHAR
   RETORNA UM CARACTER JÁ COM O BIT SETADO */
unsigned char set_bit(unsigned char c, int i);

/* FAZ O DESLOCAMENTO DOS 3 BITS DE LIXO PARA OS TRÊS PRIMEIROS BITS DO SHORT
   RETORNA OS 3 BITS DE LIXO POSICIONADO NOS TRÊS PRIMEIROS BITS */
unsigned short converter_lixo(unsigned short lixo);

/* ESCREVE O LIXO E O TAMANHO */
void escrever_cabecalho_inicio(unsigned short cabecalho_inicial, FILE* arquivo);

/* ESCREVE A ÁRVORE EM PRÉ-ORDEM NO ARQUIVO */
void escrever_arvore(Node *cabeca, FILE *arquivo);

/* ESCREVE O TEXTO JÁ COMPACTADO NO ARQUIVO */
void escrever_texto(unsigned char *array_texto, int tamanho, FILE *arquivo);
