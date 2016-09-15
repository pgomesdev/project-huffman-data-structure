#include "f_arquivo.h"
#include "f_arvore.h"

int main()
{
    /// ENCURTA ENDEREÇO DO ARQUIVO PARA VARIAVEL "url"
    char url[]="F:\\Dropbox\\2016.1\\Huffman\\Novo Documento de Texto.txt";

    /// A FUNÇÃO "abrir_Arquivo()" RETORNA UM PONTEIRO DO TIPO "FILE", E AGORA "arq" APONTA PARA ARQUIVO.
    FILE *arq = abrir_Arquivo(url);

    ///  SE "abrir_Arquivo()" RETORNAR DIFERENTE DE ZERO, ARQUIVO ABERTO COM SUCESSO.
    if(arq != 0)
    {
        long int tam = contar_tam_texto_char(arq);

        char txt[tam];
        char letra;
        long int i = 0;

        /// OBS.: FOI NECESSARIO ULTILIZAR A FUNÇÃO "rewind()" == "FUNÇÃO QUE REAPONTA "fgetc()" PARA O INICIO DO ARQUIVO."
        /// POIS NA CHAMADA DE "contar_tam_texto_char(arq)" , A FUNÇÃO "fgetc()" ESTAVA APONTANDO PARA O FINAL DO ARQUIVO.
        rewind(arq);

        /// FAZENDO COPIA DO CONTEUDO DE "arq" PARA BUFFER "txt[]".
        while((letra = fgetc(arq)) != EOF)
        {
            txt[i] = letra;
            i++;
        }

        /// NAO PRECISO MAIS DO ARQUIVO!
        fclose(arq);

        print_txt(txt,tam);

        /// ARRAY QUE GUARDARA AS LETRAS E FREQUENCIA DELAS DESTA FORMA: [a][3][b][8][e][1]
        char freq[tam*2];

        /// TODAS AS POSIÇÕES DO ARRAY "freq[]" TERA CONTUDO INTEIRO -1.
        limpar_array(freq, tam*2);
        long int num, j;

        ///<FOR MASTER> PERCORRE CADA CARACTERE DO TEXTO A CADA CHAMADA!  OBS.: "tam" == TAMANHO DO TEXTO EM NUMERO DE CARACTERES!
        for(i=0 ; i<tam ; i++)
        {
            ///VARIAVEL "LETRA" RECEBE O PROXIMO CARACTERE DO TEXTO PARA ANALIZAR.  OBS.: "txt[]" É UM BUFFER CONTENDO O TEXTO.
            letra = txt[i];

            ///CONTAGEM "num" É ZERADA PARA NOVA LETRA ANALIZADA!    OBS.: "num" == NUMERO DE VEZES QUE A LETRA ANALIZADA REPETE NO TEXTO!
            num = 0;

            ///ESTE LOOP DECOBRE QUANTAS VEZES A LETRA ANALIZADA FOI REPETIDA NO TEXTO!
            for(j=0 ; j<tam ; j++)
            {
                if(letra == txt[j])
                {
                    num++;
                }
            }

            ///CONDIÇÕES PARA REGISTRAR LETRA E FREQUENCIA DELA, EM UM NOVO ARRAY CHAMADO "freq[]"
            ///OBS.: freq[] guardara as informações desta forma:
            ///[letra][frequencia_letra] => [a][3][b][8][e][1]
            for(j=0 ; j<tam*2 ; j++)
            {

                ///SE A LETRA JA ESTIVER NO ARRAY "freq[]" ELA NAO ENTRARA NOVAMENTE
                if(freq[j] == letra)
                {
                    break;
                }

                ///CONDIÇÃO QUE APROVA QUE NAQUELA POSIÇÃO O "freq[]" TEM APENAS "LIXO" -> CRIADO PELA FUNÇÃO "limpar_array()".
                else if(freq[j] == -1)
                {
                    freq[j] = letra;
                    j++;
                    freq[j] = num;
                    break;
                }
                ///COMO O CADASTRO É NA FORMA [letra][frequencia_letra] LOGO j = j+2;
                j++;
            }
        }
        print_freq(freq,tam);
    }
    return 0;
}

