#include "biblioteca.h"


void extrato_adm(char cpf_lista[NUM_OF_USERS][12], char senha_lista[NUM_OF_USERS][7]) {
    int i;
    char cpf_inv[12];
    char buffer[2000];
    FILE *arquivoini, *arquivoini2;

    
    arquivoini = fopen("login.txt", "r");
    if (arquivoini == NULL) {
        printf("Erro ao abrir o arquivo de login.\n");
        return;
    }
    for (i = 0; i < NUM_OF_USERS && fgets(buffer, sizeof(buffer), arquivoini); i++) {
        buffer[strcspn(buffer, "\n")] = 0;  
        strcpy(cpf_lista[i], buffer);
    }
    fclose(arquivoini);

    
    arquivoini2 = fopen("senhas.txt", "r");
    if (arquivoini2 == NULL) {
        printf("Erro ao abrir o arquivo de senhas.\n");
        return;
    }
    for (i = 0; i < NUM_OF_USERS && fgets(buffer, sizeof(buffer), arquivoini2); i++) {
        buffer[strcspn(buffer, "\n")] = 0;  
        strcpy(senha_lista[i], buffer);
    }
    fclose(arquivoini2);

    while (1) {
        printf("Digite o CPF do investidor: ");
        scanf("%11s", cpf_inv);

        int cpf_encontrado = 0;

        
        for (i = 0; i < NUM_OF_USERS; i++) {
            if (strcmp(cpf_lista[i], cpf_inv) == 0) {
                cpf_encontrado = 1;
                printf("======================EXTRATO======================\n");
                printf("CPF INVESTIDOR: %s\n", cpf_inv);

                FILE *extratobanco;
                extratobanco = fopen("extrato.bin", "rb");
                if (extratobanco == NULL) {
                    printf("Erro ao abrir o arquivo de extrato.\n");
                    return;
                }

                
                while (fgets(buffer, sizeof(buffer), extratobanco)) {
                    char *espaco = strchr(buffer, ' ');
                    if (espaco != NULL) {
                        *espaco = '\0';
                        if (strcmp(buffer, cpf_inv) == 0) {
                            printf("%s\n", espaco + 1);
                        }
                    }
                }

                fclose(extratobanco);
                printf("===================================================\n");
                printf("\n<--- volte com 'ENTER'\n");
                getchar();  
                return;
            }
        }

        if (!cpf_encontrado) {
            printf("CPF não existe!!\n");
        }
    }
}
