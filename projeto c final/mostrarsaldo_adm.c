#include "biblioteca.h"


void mostrarSaldo(float *carteira, float *carteiraBit, float *carteiraEth,float *carteiraXrp, int *indice) {
    printf("-----------Saldo----------\n");
    printf("| REAIS: %.2f\n", carteira[*indice]);
    printf("| BITCOIN: %.5f\n", carteiraBit[*indice]);
    printf("| ETHEREUM: %.5f\n", carteiraEth[*indice]);
    printf("| RIPPLE: %.5f\n", carteiraXrp[*indice]);
    printf("--------------------------\n");

    printf("\n<--- volte com 'ENTER'\n"); 
    getchar();
    return;	
};
