#include "biblioteca.h"

void mostrar_cotacoes(const char *cripto) {
    FILE *arquivo = fopen(cripto, "r"); // Abre o arquivo texto em modo leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'\n", crip);
        return;
    }

    char nome[50];
    float valor, cotven, cotcomp;

    printf("Cotações:\n");
    printf("Nome\t\tValor\n");
    printf("-------------------------\n");

    // Lê cada linha do arquivo
    while (fscanf(arquivo, "%49s %f %f %f", nome, &valor, &cotven, &cotcomp) == 4) {
        // Mostra apenas o nome e o valor
        printf("%-10s\t%.2f\n", nome, valor);
    }

    fclose(arquivo); // Fecha o arquivo após a leitura
}
