#include "biblioteca.h"


int main(){
    float bit = 342089;
    float rip =  3.18;
    float eth = 12980;

    float carteira[NUM_OF_USERS]={};
    float carteiraBit[NUM_OF_USERS]={};
    float carteiraEth[NUM_OF_USERS]={};
    float carteiraXrp[NUM_OF_USERS]={};
    int i = 0;
    int indice;
    char cpf[12];
    char senha[7];
    char cpf_lista[NUM_OF_USERS][12]={};
    char senha_lista[NUM_OF_USERS][7]={};

  
  iniciacao_arquivos(carteira,carteiraBit,carteiraEth,carteiraXrp, cpf_lista,senha_lista);
  int tipo_usuario = login_novo(&indice, cpf, senha, cpf_lista, senha_lista);
  Cotacao_inicial(&bit,&eth,&rip);
  while (1){  

    if (tipo_usuario==1){
      int cont_adm = menu_adm();
       switch (cont_adm){
            case 1:
              cadastrar_inv(cpf_lista);
              getchar();
              break;
            case 2:
              printf("...\n");
              break;
            case 3:
              printf("...\n");
              break;
            case 4:
              printf("...\n");
              break;
            case 5:
              mostrarSaldo_adm(carteira, carteiraBit, carteiraEth, carteiraXrp, cpf_lista);
              getchar();
              break;
            case 6:
              extrato_adm(cpf_lista, senha_lista);
              getchar();
              break;
            case 7:
              printf("...\n");
            case 8:
              printf("DESCONECTANDO...\n");
              exit(0);
              break;
          }
    } else if (tipo_usuario == 0) {
      int cont_inv =menu();
       switch (cont_inv){
            case 1:
              mostrarSaldo(carteira,carteiraBit,carteiraEth,carteiraXrp, &indice);
              getchar();
              break;
            case 2:
              extrato(cpf);
              getchar();
              break;
            case 3:
              depositar(carteira, carteiraBit, carteiraEth, carteiraXrp,cpf,&indice);
              break;
            case 4:
              sacar(carteira, carteiraBit, carteiraEth, carteiraXrp, senha, &indice,cpf);
              getchar();
              break;
            case 5:
              Comprar_criptomoedas(carteira, carteiraBit, carteiraEth, carteiraXrp, senha, cpf,&indice,&bit,&eth,&rip);
              break;
            case 6:
              Vender_criptomoedas(carteira, carteiraBit, carteiraEth, carteiraXrp, cpf,&indice,&bit,&eth,&rip);
              break;
            case 7:
              Atualiza_cotacao(&bit,&eth,&rip);
              getchar();
              break;
            case 8:
              atualizacao_das_carteiras(carteira,carteiraBit,carteiraEth,carteiraXrp);
              printf("DESCONECTANDO...\n");
              exit(0);
              break;
       }
    }
  }
  system("pause");
  return 0;
}
