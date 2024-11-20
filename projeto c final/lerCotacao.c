#include "biblioteca.h"
void lerCotacoes(cotacao* cotacoes, int* num_cotacoes) {
    FILE *arquivo_cotacoes;
    char linha[200];

    arquivo_cotacoes = fopen("cripto.txt", "r");


    *num_cotacoes = 0; // Inicializa o número de cotações

    while (fgets(linha, sizeof(linha), arquivo_cotacoes) && *num_cotacoes < MAX_MOEDAS) {
        sscanf(linha, "%s %f %f %f", 
               cotacoes[*num_cotacoes].nome, 
               &cotacoes[*num_cotacoes].valor, 
               &cotacoes[*num_cotacoes].cotven, 
               &cotacoes[*num_cotacoes].cotcomp);
        (*num_cotacoes)++;
    }

    fclose(arquivo_cotacoes);
}
