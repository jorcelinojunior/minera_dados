/* Importa bibliotecas do windows */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>

/* Define variaveis */
#define TamLinha 600
#define ArqAtual "page.csv"  // +-44 GB cada arquivo

/* declara funções */
long getName(FILE *ArqLeitura,FILE *ArqEscrita,long sizeA);
long getAtuation(FILE *ArqLeitura,FILE *ArqEscrita,long sizeA);
long getPhone(FILE *ArqLeitura,FILE *ArqEscrita,long sizeA);
long getCity(FILE *ArqLeitura,FILE *ArqEscrita,long sizeA);
