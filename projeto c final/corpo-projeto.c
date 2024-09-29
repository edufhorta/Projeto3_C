#include "biblioteca.h"


int main()
{
    float bit = 342089;
    float rip =  3.18;
    float eth = 12980;
    char cpf[12];
    char senha[7];
    char cpf_lista[NUM_OF_USERS][12]={"75764675332","56394345628","82347782002","51382457324","69186635859","37532705471","69477299553","20567586600","99462980233","14445337200"};
    char senha_lista[NUM_OF_USERS][7]={"123456","654321","135792","246813","102938","564738","987654","321654","456789","112233"};
    float carteira[NUM_OF_USERS]={};
    float carteiraBit[NUM_OF_USERS]={};
    float carteiraEth[NUM_OF_USERS]={};
    float carteiraXrp[NUM_OF_USERS]={};
    int indice;
    int i = 0;
  
  setlocale(LC_ALL, "portuguese");
  iniciacao_arquivos(carteira,carteiraBit,carteiraEth,carteiraXrp);
  login(&indice,cpf,senha,cpf_lista,senha_lista);
  Cotacao_inicial(&bit,&eth,&rip);
  while (1){  

      int cont =menu();
       switch (cont){
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
  system("pause");
  return 0;
}
