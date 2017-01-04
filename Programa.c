#include "Programa.h"

long getName(FILE *ArqLeitura,FILE *ArqEscrita,long sizeA)
{
    char linhaA[TamLinha];
    char linhaB[TamLinha];
    char linhaC[TamLinha];
    long sizeName = sizeA;

    fseek(ArqLeitura,sizeA,SEEK_SET);   // Movimenta a posição corrente de escrita ou leitura no arquivo para um local específico
    fgets(linhaA,TamLinha, ArqLeitura); // Carrego uma linha para garantir que no laço abaixo o "</head>" não seja carregado

    while(strstr(linhaA,"</head>") == NULL) // '</head>' marca o final de cada bloco, ou seja, de cada página salva no nosso 'arquivoBanco'
    {
      if (sizeName != sizeA)
      {
        fseek(ArqLeitura,sizeName,SEEK_SET);
      }
      	fflush(stdin);  //Limpa o buffer
        fgets(linhaA,TamLinha, ArqLeitura);      // lê e salva a linha na string "linhaA"
        sizeName = ftell(ArqLeitura);            //salva a posição para na próxima iteração começar de onde parou o conteudo da linhaB em um proximo loop. */
        fgets(linhaB,TamLinha, ArqLeitura);      // Cada vez que carrego uma linha com fgets estou carregando linhas diferentes
        fgets(linhaC,TamLinha, ArqLeitura);      /* Ex:
                                               fgets(linhaB,TamLinha, ArqLeitura); //Carrega a linha X
                                               fgets(linhaC,TamLinha, ArqLeitura);    //Carrega a linha X+1 */

        if(strstr(linhaB,"</li>") != NULL && ((strstr(linhaC,"</ol>")) != NULL))
        {
            fputs(linhaA,ArqEscrita); // Imprime a "linhaA" no arquivo "ArqEscrita"
        }
    }
    return ftell(ArqLeitura);
}

long getAtuation(FILE *ArqLeitura,FILE *ArqEscrita,long sizeA)
{
    char linhaA[TamLinha];

    fseek(ArqLeitura,sizeA,SEEK_SET);
    fgets(linhaA,TamLinha, ArqLeitura); // Carrega uma linha para garantir que no laço abaixo o "</head>" não seja carregado

    while(strstr(linhaA,"</head>") == NULL) // '</head>' marca o final de cada bloco, ou seja, de cada página salva no nosso 'arquivoBanco'
    {
        fgets(linhaA,TamLinha, ArqLeitura); /* le a uma linha e salva na string "linhaA" */
                                           /* Cada vez que carrego uma linha com fgets estou carregando linhas diferentes
                                           Ex:
                                               fgets(linhaB,TamLinha, ArqLeitura); //Carrega a linha X
                                               fgets(linhaC,TamLinha, ArqLeitura);    //Carrega a linha X+1 */

        if(strstr(linhaA,"<p itemprop=68summary68>") != NULL) //strstr retorna a posiçao onde posso encontrar a palava // Se na linhaA conter aquela string, entao ali eu tenho um area de atuacao
        {
            fputs(linhaA,ArqEscrita); // Imprime a "linhaA" no arquivo "ArqEscrita"
        }
    }
    return ftell(ArqLeitura);
}

long getPhone(FILE *ArqLeitura,FILE *ArqEscrita,long sizeA)
{
    char linhaA[TamLinha];

    fseek(ArqLeitura,sizeA,SEEK_SET);
    fgets(linhaA,TamLinha, ArqLeitura); // Carrega uma linha para garantir que no laço abaixo o "</head>" não seja carregado

    while(strstr(linhaA,"</head>") == NULL) // '</head>' marca o final de cada bloco, ou seja, de cada página salva no nosso 'arquivoBanco'
    {
        fgets(linhaA,TamLinha, ArqLeitura); /* le a uma linha e salva na string "linhaA" */
                                           /* Cada vez que carrego uma linha com fgets estou carregando linhas diferentes
                                           Ex:
                                               fgets(linhaB,TamLinha, ArqLeitura); //Carrega a linha X
                                               fgets(linhaC,TamLinha, ArqLeitura);    //Carrega a linha X+1 */

        if(strstr(linhaA,"<li class=6868><b>celular</b>") != NULL || ((strstr(linhaA,"<li class=6868><b>comercial</b>")) != NULL))
        {
            fputs(linhaA,ArqEscrita); // Imprime a "linhaA" no arquivo "ArqEscrita"
        }
    }
    return ftell(ArqLeitura);
}


long getCity(FILE *ArqLeitura,FILE *ArqEscrita,long sizeA)
{
    char linhaA[TamLinha];

    fseek(ArqLeitura,sizeA,SEEK_SET);
    fgets(linhaA,TamLinha, ArqLeitura); // Carrega uma linha para garantir que no laço abaixo o "</head>" não seja carregado

    while(strstr(linhaA,"</head>") == NULL) // '</head>' marca o final de cada bloco, ou seja, de cada página salva no nosso 'arquivoBanco'
    {
        fgets(linhaA,TamLinha, ArqLeitura); // lê uma linha diferente a cada iteração e salva na string "linhaA"

        // O 'if' abaixo vê se uma das três string faz parte da linha, se sim eu irei salvar essa linha
        if(strstr(linhaA,"<input class=68green local68 id=68local68 name=") != NULL && ((strstr(linhaA,"<input class=68green local68 id=68local68 name=68local68 type=68text68 maxlength=686068 value=6868 data-id=6835619268 tabindex=68568 />")) == NULL) && ((strstr(linhaA,"<input class=68green local68 id=68local68 name=68local68 type=68text68 maxlength=686068 value=6868 data-id=6868 tabindex=68568 />")) == NULL))
        {
            fputs(linhaA,ArqEscrita); // Imprime a "linhaA" no arquivo "ArqEscrita"
        }
    }
    return ftell(ArqLeitura);
}
