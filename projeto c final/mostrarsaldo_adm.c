#include "biblioteca.h"

void mostrarSaldo_adm(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, char cpf_lista[NUM_OF_USERS][12]) {

    int i;
    char cpf_inv[12];
    char compiler[2000];
    FILE *arquivoini;

    arquivoini = fopen("login.txt", "r");
    if (arquivoini == NULL) {
        printf("Erro ao abrir o arquivo de login.\n");
        return;
    }
    for (i = 0; i < NUM_OF_USERS && fgets(compiler, sizeof(compiler), arquivoini); i++) {
        compiler[strcspn(compiler, "\n")] = 0; 
        strcpy(cpf_lista[i], compiler);
    }
    fclose(arquivoini);

    while (1) {
        printf("Digite o CPF do investidor: ");
        scanf("%11s", cpf_inv);

        int cpf_encontrado = 0;

        for (i = 0; i < NUM_OF_USERS; i++) {
            if (strcmp(cpf_lista[i], cpf_inv) == 0) {
                cpf_encontrado = 1;

                printf("\nCPF INVESTIDOR: %s\n", cpf_inv);
                printf("-----------Saldo----------\n");
                printf("| REAIS: %.2f\n", carteira[i]);
                printf("| BITCOIN: %.5f\n", carteiraBit[i]);
                printf("| ETHEREUM: %.5f\n", carteiraEth[i]);
                printf("| RIPPLE: %.5f\n", carteiraXrp[i]);
                printf("--------------------------\n");

                break;
            }
        }
        if (!cpf_encontrado) {
            printf("CPF não encontrado!\n");
        }
        printf("\n<--- Pressione 'ENTER' para continuar\n");
        getchar();
        break;
    }
}
