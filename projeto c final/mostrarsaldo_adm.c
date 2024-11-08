#include "biblioteca.h"


void mostrarSaldo_adm(float *carteira, float *carteiraBit, float *carteiraEth,float *carteiraXrp, int *indice) {

    char cpf_lista[10][12]={"75764675332","75764675332","82347782002","51382457324","69186635859","37532705471","69477299553","20567586600","99462980233","14445337200"};
    int i;
    char cpf[12];
    while(1){
    printf("Digite o CPF do investidor: ");
    scanf("%11s",&cpf);
    printf("%s",cpf);
     
    for (i = 0;i<10;i++){
    if(strcmp(cpf_lista[i], cpf) == 0){
        
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
