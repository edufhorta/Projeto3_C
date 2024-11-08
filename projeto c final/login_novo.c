#include <biblioteca.h>
void login(int *indice){

  int x;
  while (1){
  printf("Olá, por acaso você já é cadastrado?\n");
  printf("1- Sim ou 2-Não\n");
  scanf("%d",&x);
  if (x== 1){
    printf("você é 1-adiministrador ou 2-investidor?\n");
    scanf("%d", &x);
    if (x==1){
    printf("BEM VINDO INVESTIDOR!!\n");
    printf("Digite seu CPF: ");
    scanf("%11s", cpf);
    printf("Digite sua senha: ");
    scanf("%6s", senha);

    for (int i = 0; i < max_usu; i++) {
      if (strcmp(cpf_lista[i], cpf)== 0) {
        if (strcmp(senha_lista[i],senha)==0){
          printf("\nLogin realizado com sucesso!\n");
          *indice = i;
          return;
        }



      }
    }
    printf("\nCPF ou senha incorretos!\n");


  }
  }
  else{
    printf("BEM VINDO ADMINISTRADOR!!\n");
    printf("Digite seu CPF: ");
    scanf("%11s", cpf);
    printf("Digite sua senha: ");
    scanf("%6s", senha);

    for (int i = 0; i < max_usu; i++) {
      if (strcmp("75764675332",cpf)== 0) {
        if (strcmp("123456",senha)==0){
          printf("\nLogin realizado com sucesso!\n");
          *indice = i;
          return;
        }



      }
    }
    printf("\nCPF ou senha não são administrador!\n");


  }
  }
  else if (x== 2){
    char login[12],pass[7];
    FILE *arquivo;
    FILE *arquivo2;
    while(1){
    printf("Vamos cadastrar você!\n");
    printf("Digite seu CPF: ");
    scanf("%11s", login);
    for (int i=0; i<10;i++){
        if (strcmp(cpf_lista[i],login)== 0) {
            printf("CPF JÁ CADASTRADO, tente denovo.")
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

    iniciacao_arquivos(carteira);
  }

  else{
    printf("Opção inválida!\n");
  }
}
