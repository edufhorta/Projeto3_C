#include "biblioteca.h"



int login_novo(int *indice, char *cpf, char *senha, char *cpf_lista[NUM_OF_USERS][12], char *senha_lista[NUM_OF_USERS][7]){

  int x;
    FILE *arquivoini, *arquivoini2;
     char compiler [2000];
    // Abertura dos arquivos
    arquivoini = fopen("login.txt","r");
    for (int i=0;i<NUM_OF_USERS && fgets(compiler, sizeof(compiler), arquivoini);i++) {
        compiler[strcspn(compiler, "\n")] = 0; 

        strcpy(cpf_lista[i], compiler); 

    }
    fclose(arquivoini);

    arquivoini2 = fopen("senhas.txt","r");
    for (int i=0;i<NUM_OF_USERS && fgets(compiler, sizeof(compiler), arquivoini2);i++) {
      compiler[strcspn(compiler, "\n")] = 0; 

      strcpy(senha_lista[i], compiler); 

    }
    fclose(arquivoini2);
  while (1){
  printf("Olá, por acaso você já é cadastrado?\n");
  printf("1- Sim ou 2-Não\n");
  scanf("%d",&x);
    
  if (x== 1){
    printf("Você é 1-adiministrador ou 2-investidor?\n");
    scanf("%d", &x);
    
    if (x == 1) {
      printf("BEM VINDO ADMINISTRADOR!!\n");
      printf("Digite seu CPF: ");
      scanf("%11s", cpf);
      printf("Digite sua senha: ");
      scanf("%6s", senha);

    if (strcmp(cpf, "75764675332") == 0 && strcmp(senha, "123456") == 0) {
        printf("\nLogin realizado com sucesso!\n");
        *indice = 0;
        return 1;
    }
    else {
        printf("\nCPF ou senha não são de administrador!\n");
    }


  } else{
    printf("BEM VINDO INVESTIDOR!!\n");
    printf("Digite seu CPF: ");
    scanf("%11s", cpf);
    printf("Digite sua senha: ");
    scanf("%6s", senha);

    for (int i = 0; i < NUM_OF_USERS; i++) {
        if (strcmp(cpf_lista[i], cpf) == 0 && strcmp(senha_lista[i], senha) == 0) {
            printf("\nLogin realizado com sucesso!\n");
            *indice = i;
           return 0;
        }
    }
    printf("\nCPF ou senha incorretos!\n");
  } 
  } else if (x== 2){
    char login[MAX_CPF_LENGTH], pass[MAX_SENHA_LENGTH];
    FILE *arquivo, *arquivo2;
    while(1){
    printf("Vamos cadastrar você!\n");
    printf("Digite seu CPF: ");
    scanf("%11s", login);
    for (int i=0; i<10;i++){
        if (strcmp(cpf_lista[i],login)== 0) {
            printf("CPF JÁ CADASTRADO, tente denovo.");
            break;
        }
        
    }   
        break;
    }
    
    printf("Crie uma senha: ");
    scanf("%6s", pass);

    printf("\nÓtimo você foi cadastrado !!!\n");

    arquivo = fopen("login.txt","a");
    fprintf(arquivo,"%s\n",login);
    fclose(arquivo);
    arquivo2 = fopen("senhas.txt","a");
    fprintf(arquivo2,"%s\n",pass);
    fclose(arquivo2);

  }

  else{
    printf("Opção inválida!\n");
  }
}
}
