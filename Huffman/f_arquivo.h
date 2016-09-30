/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once

#include <stdlib.h>//Biblioteca para abrir arquivos
#include <stdio.h>//Biblioteca padrão de Entrada e Saida do C

/// NESSA BIBLIOTECA ESTÃO REUNIDAS AS FUNÇÕES ARQUIVOS txt OU SEU CONTEUDO

//Função que recebe: uma String, tendo o seu primeiro elemento em txt, onde txt != NULL;
//o tamanho da String recebida, armazenado no inteiro tam, onde tam >= 0;
//e que não possui nenhuma devolução.
//Sua ação é utilizar o printf para imprimir na tela o conteudo da String, e ao termino pula uma linha.
void print_txt(unsigned char *txt, int tam);

//Função que recebe: um ponteiro para um tipo FILE, representado o arquivo .txt, onde arq != NULL;
//e devolve um inteiro com o tamanho de caracteres de texto, sendo esse valor maior ou igual que zero.
int contar_tam_texto_char(FILE *arq);

//Função que recebe: uma String, representado o local do arquivo a ser aberto, onde url != "\0";
//e se ocorrer bem devolve um ponteiro para um tipo FILE, representado o arquivo .txt,
//se ocorrer algum erro, devolve 0.
FILE *abrir_Arquivo(char *url);

