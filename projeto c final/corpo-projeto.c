#include "biblioteca.h"


int main(){
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
    carteira carteiras[NUM_OF_USERS];
    cotacao cotacoes[NUM_OF_USERS];
  
  iniciacao_arquivos(carteira);
  int tipo_usuario = login_novo(&indice, cpf, senha, cpf_lista, senha_lista);
  cotacao *loaded_cotacoes = NULL;  // Ponteiro para armazenar as cotações carregadas
    copiarCpfsParaCarteira(carteiras, cpf_lista, NUM_OF_USERS);
       
    int num_cotacoes = 0;


    lerCotacoes(cotacoes, &num_cotacoes);
    int num_cot = carrega_cotacao("crip.txt", &loaded_cotacoes);
    
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
              criacao_cripto("crip.txt");
                getchar();
              break;
            case 4:
              apagarCripto(cotacoes);
              break;
            case 5:
              mostrarSaldo_adm(carteira,carteiras, cpf_lista);
              getchar();
              break;
            case 6:
              extrato_adm(cpf_lista, senha_lista);
              getchar();
              break;
            case 7:
              Atualiza_cotacao("crip.txt");
            case 8:
              printf("DESCONECTANDO...\n");
              exit(0);
              break;
          }
    } else if (tipo_usuario == 0) {
      int cont_inv =menu();
       switch (cont_inv){
            case 1:
              mostrarSaldo(carteira,carteiras, &indice);
              getchar();
              break;
            case 2:
              extrato(cpf);
              getchar();
              break;
            case 3:
              depositar(carteira,cpf,&indice);
              break;
            case 4:
              sacar(carteira, senha, &indice,cpf);
              getchar();
              break;
            case 5:
              Comprar_criptomoedas(carteira,carteiras,cotacoes, senha, cpf,&indice);
              break;
            case 6:
              Vender_criptomoedas(carteira,carteiras, cotacoes,cpf,&indice);
              break;
            case 7:
              Atualiza_cotacao("crip.txt");
              break;
            case 8:
              atualizacao_das_carteiras(carteira,cotacoes);
              printf("DESCONECTANDO...\n");
              exit(0);
              break;
       }
    }
  }
  system("pause");
  return 0;
}
