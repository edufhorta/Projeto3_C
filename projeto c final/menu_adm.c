#include "biblioteca.h"


void menu(){

int cont;

    printf("\n");
    printf("Bem vindo ao menu!\n");
    printf("O que você deseja acessar?\n");
    printf("--------------------------\n");
    printf("1-Cadastrar novo investidor\n");
    printf("2-Excluir investidor\n");
    printf("3-Cadastrar nova criptomoeda\n");
    printf("4-Excluir criptomoeda\n");
    printf("5-Consultar saldo de um investidor\n");
    printf("6-Consultar extrado de um investidor\n");
    printf("7-Atualizar cotação\n");
    printf("8-Sair\n");
    scanf("%d", &cont);
    printf("\n");
    return cont;

}

 // switch (cont){
 //      case 1:
 //        printf("...\n");
 //        break;
 //      case 2:
 //        printf("...\n");
 //        break;
 //      case 3:
 //        printf("...\n");
 //        break;
 //      case 4:
 //        printf("...\n");
 //        break;
 //      case 5:
 //        mostrarSaldo_adm(carteira,carteiraBit,carteiraEth,carteiraXrp);
 //        getchar();
 //        break;
 //      case 6:
 //        extrato_adm ();
 //        getchar();
 //        break;
 //      case 7:
 //        printf("...\n");
 //      case 8:
 //        printf("...\n");
 //    }
