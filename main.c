#include "Programa.h"

int main()
{
    FILE *ArqLeitura;
    FILE *ArqEscrita;

    ArqLeitura = fopen(ArqAtual,"rb"); // Abre o arquivo local de leitura para minerar os dados
    ArqEscrita = fopen("SaidaContatos.csv","ab"); // Abre a saída para inserir os dados extraidos lá

    // Inicializa a variável 'sizeA' que vai servir para saber quais bytes do arquivo deve carregar em cada iteração
    long sizeA = 0;
    int i = 0;

    if(ArqLeitura == NULL)
    {
        printf("Erro na abertura do Arquivo para extrair dados.\n");
        exit(1);
    }
    if(ArqEscrita == NULL)
    {
        printf("Erro na abertura da Lista Resultante.\n");
        exit(1);
    }

    sizeA = ftell(ArqLeitura); //Retorna a posição corrente de leitura ou escrita no arquivo (em bytes)

    fputs("<meta charset=\"UTF-8\"/>",ArqEscrita);
    while(!feof(ArqLeitura))
    {
        // Vai no bloco em busca de nome
        getName(ArqLeitura,ArqEscrita,sizeA);

        // Vai no bloco em busca de área de atuação
        getAtuation(ArqLeitura,ArqEscrita,sizeA);

        // Vai no bloco em busca de telefone daquela pessoa ou estabelecimento
        getPhone(ArqLeitura,ArqEscrita,sizeA);

        // Salva o lugar de parada
        sizeA = getCity(ArqLeitura,ArqEscrita,sizeA);

        // Imprime no arquivo uma cerquilha para separar os profissinais/estabelecimento
        fputs("<p>#</p>",ArqEscrita);

        // "\r\n" faz com que o escritor execute a quebra de linha a cada enter digitado.
        fputs("\r\n",ArqEscrita);
        	printf("%d\n",i++);

        // Carrega o arquivo para a próxima iteração levando em conta onde ele parou na última vez
        fseek(ArqLeitura,sizeA,SEEK_SET);
    }


    //minha ultima função pode retornar um ftell(ArqLeitura). Isso pq já terei feito tudo e agora quero saber o endereço para continuar...


    if (ferror(ArqLeitura) || ferror(ArqEscrita))/* Checa a integridade do arquivo ao final de tudo */
    {
        perror("Erro:");
    }

    fclose(ArqLeitura); /* Fecha/salva com segurança o arquivo de leitura*/
    fclose(ArqEscrita); /* Fecha/salva com segurança o arquivo de saída*/

    printf("Tudo pronto! Cheque o arquivo de saída.\n");

    system("pause");
    return 0;
}
