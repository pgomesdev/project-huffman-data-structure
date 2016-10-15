/// INSTRUÇÃO PARA O COMPILADOR SÓ IMPORTAR AS BIBLIOTECAS ABAIXO QUE NÃO EXISTIREM
#pragma once
#include <stdlib.h>//Biblioteca para abrir arquivos
#include <stdio.h>//Biblioteca padrão de Entrada e Saida do C

/// NESSA BIBLIOTECA ESTÃO REUNIDAS AS FUNÇÕES PARA ARQUIVOS txt OU SEU CONTEUDO

//Função que recebe: uma String, representado o local do arquivo a ser aberto, onde url != "\0";
//e se ocorrer bem devolve um ponteiro para um tipo FILE, representado o arquivo .txt,
//se ocorrer algum erro, devolve 0.
FILE *abrir_Arquivo(char *url);

