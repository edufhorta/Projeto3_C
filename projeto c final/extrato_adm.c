void extrato_adm () {

  int i;
    char cpf_inv[12];
    while(1){
    printf("Digite o CPF do investidor: ");
    scanf("%11s",&cpf_inv);
  for (i = 0;i<10;i++){
    if(strcmp(cpf_lista[i], cpf_inv) == 0){
    printf("======================EXTRATO======================\n");
      printf("CPF INVESTIDOR: %s\n",cpf_inv);
    FILE *extratobanco;

    char linha[1000];

    extratobanco = fopen("extrato.txt", "r");


    while (fgets(linha, sizeof(linha), extratobanco) != NULL) {
        char *espaco = strchr(linha, ' ');
        if (espaco != NULL) {
            *espaco = '\0';

            if (strcmp(linha, cpf_inv) == 0) {
                printf("%s\n", espaco + 1);
            }
        }
    }

    fclose(extratobanco);
    printf("===================================================\n");
    printf("\n<--- volte com 'ENTER'\n");

    getchar();
    return;
      
  }else{
    printf("CPF não existe!!");
    }
  }
}
}
