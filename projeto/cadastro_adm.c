#include "biblioteca.h"

void cadastrar_inv(char cpf_lista[NUM_OF_USERS][12]) {
  
  char login[12], senha[7];
    char nome[1000];
  
  FILE *arquivo, *arquivo2;

  while (1) {
    
      int cpf_duplicado = 0;

      printf("Vamos cadastrar o investidor!\n");
      printf("Digite o nome do investidor: ");
      scanf("%s", nome);
      printf("Digite o CPF do investidor: ");
      scanf("%11s", login);

      for (int i = 0; i < NUM_OF_USERS; i++) {
          if (strcmp(cpf_lista[i], login) == 0) {
              printf("CPF JÁ CADASTRADO, tente novamente.\n");
              cpf_duplicado = 1;
              break;
          }
      }
      if (!cpf_duplicado) {
          break; 
      }
  }

  printf("Crie uma senha para o investidor: ");
  scanf("%6s", senha);

  printf("\nÓtimo, o(a) %s foi cadastrado(a)!\n", nome);

  
  arquivo = fopen("login.txt", "a");
  fprintf(arquivo, "%s\n", login);
  fclose(arquivo);
  
  arquivo2 = fopen("senhas.txt", "a");
  fprintf(arquivo2, "%s\n", senha);
  fclose(arquivo2);

  printf("\n<--- Pressione 'ENTER' para continuar\n");
  getchar();
  
}
