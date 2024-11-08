#include "biblioteca.h"


void mostrarSaldo_adm(float *carteira, float *carteiraBit, float *carteiraEth,float *carteiraXrp) {
    int indice_inv
  
    
    char cpf_inv[12];
    while(1){
    printf("Digite o CPF do investidor: ");
    scanf("%11s",&cpf_inv);
    printf("%s",cpf_inv);
     
    for (i = 0;i<10;i++){
    if(strcmp(cpf_lista[i], cpf_inv) == 0){
       
        
    printf("-----------Saldo----------\n");
    printf("| REAIS: %.2f\n", carteira[i]);
    printf("| BITCOIN: %.5f\n", carteiraBit[i]);
    printf("| ETHEREUM: %.5f\n", carteiraEth[i]);
    printf("| RIPPLE: %.5f\n", carteiraXrp[i]);
    printf("--------------------------\n");

    printf("\n<--- volte com 'ENTER'\n"); 
    break;
    }
    }
    getchar();
    return;	
};
