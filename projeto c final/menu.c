#include "biblioteca.h"

int menu(){

  int cont;

  
    printf("\n");
    printf("Bem vindo ao menu!\n");
    printf("O que você deseja acessar?\n");
    printf("--------------------------\n");
    printf("1-Consultar saldo\n");
    printf("2-Consultar extrato\n");
    printf("3-Depositar reais\n");
    printf("4-Sacar reais\n");
    printf("5-Comprar criptomoedas:\n");
    printf("6-Vender criptomoedas\n");
    printf("7-Atualizar cotação\n");
    printf("8-Sair\n");
    scanf("%d", &cont);
    printf("\n");
    return cont;
  
 
     
};
  
