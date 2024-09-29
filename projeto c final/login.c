#include "biblioteca.h"

void login(int *indice, char *cpf, char *senha, char *cpf_lista[NUM_OF_USERS][12], char *senha_lista[NUM_OF_USERS][7]){
  while (1){
    printf("BEM VINDO!!\n");
    printf("Digite seu CPF: ");
    scanf("%11s", cpf);
    printf("Digite sua senha: ");
    scanf("%6s", senha);

    for (int i = 0; i < NUM_OF_USERS; i++) {
      if (strcmp(cpf_lista[i], cpf)== 0) {
        if (strcmp(senha_lista[i],senha)==0){
          printf("Login realizado com sucesso!\n");
          *indice = i;
          return;
        }



      }
    }
    printf("CPF ou senha incorretos!\n");

  }
}