void extrato_adm () {
  char cpf_lista[10][12]={"75764675332","75764675332","82347782002","51382457324","69186635859","37532705471","69477299553","20567586600","99462980233","14445337200"};

  int i;
    char cpf[12];
    while(1){
    printf("Digite o CPF do investidor: ");
    scanf("%11s",&cpf);
    printf("%s",cpf);
  for (i = 0;i<10;i++){
    if(strcmp(cpf_lista[i], cpf) == 0){
    printf("======================EXTRATO======================\n");
    FILE *extratobanco;

    char linha[1000];

    extratobanco = fopen("extrato.txt", "r");


    while (fgets(linha, sizeof(linha), extratobanco) != NULL) {
        char *espaco = strchr(linha, ' ');
        if (espaco != NULL) {
            *espaco = '\0';

            if (strcmp(linha, cpf) == 0) {
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
