#include "biblioteca.h"

void depositar(float*carteira, float*carteiraBit, float*carteiraEth, float*carteiraXrp, const char *cpf, int *indice) {
    FILE *extratofile;
    float valor;
    char dataAtual[20];
    time_t t = time(NULL);
    struct tm tm=*localtime(&t);

    printf("Quanto deseja depositar (ou 0 para não depositar): ");
    scanf("%f", &valor);


    carteira[*indice] += valor;
    snprintf(dataAtual, sizeof(dataAtual), "%02d-%02d-%04d %02d:%02d",
             tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);


    extratofile = fopen("extrato.bin", "ab");
    fprintf(extratofile,"%s %s + %.2f REAIS CT:0.00    TX:0.00 REAL:%.2f BTC:%.6f ETH:%.5f XRP:%.3f\n", cpf, dataAtual, valor, carteira[*indice], carteiraBit[*indice], carteiraEth[*indice], carteiraXrp[*indice]);

    fclose(extratofile);
}