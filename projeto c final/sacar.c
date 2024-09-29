#include "biblioteca.h"

void sacar(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, const char *senha, int *indice, char *cpf) {
    FILE *extratofile;
    float valor;
    char dataAtual[20];
    time_t t = time(NULL);
    struct tm tm=*localtime(&t);
    char sen[6];
    while(1){

        printf("Quanto deseja sacar (ou 0 para não depositar): ");
        scanf("%f", &valor);


        if (valor > carteira[*indice]) {
            printf("ERRO: Você não pode sacar dinheiro a mais do que o disponível em sua carteira!! (carteira: %.2f)\n",
                  carteira[*indice]);
        }
        else{
            while (strcmp(senha,sen)!=0) {
                printf("Digite sua senha para a validação do saque:\n ");
                scanf("%s", sen);
                if (strcmp(senha,sen)!=0){
                    printf("Senha incorreta, tente novamente.\n");
                }
            }
            break;
        }
    }
    carteira[*indice] -= valor;
    snprintf(dataAtual, sizeof(dataAtual), "%02d-%02d-%04d %02d:%02d",
             tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);


    extratofile = fopen("extrato.bin", "ab");
    fprintf(extratofile,"%s %s - %.2f REAIS CT:0.00    TX:0.00 REAL:%.2f BTC:%.6f ETH:%.5f XRP:%.3f\n", cpf, dataAtual, valor, carteira[*indice], carteiraBit[*indice], carteiraEth[*indice], carteiraXrp[*indice]);

    fclose(extratofile);

    return;
}