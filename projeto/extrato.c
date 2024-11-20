#include "biblioteca.h"

//CONSULTAR O EXTRATO.

void extrato( char *cpf) {
    printf("======================EXTRATO======================\n");
    FILE *extratobanco;

    char linha[1000]; 

    extratobanco = fopen("extrato.bin", "rb");

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
}
