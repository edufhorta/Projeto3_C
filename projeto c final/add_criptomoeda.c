#include "biblioteca.h"

void adiciona_criptomoeda(const char *crip, const char *nome, float valor) {
    FILE *arquivo = fopen(crip, "ab"); // Abre o arquivo em modo de adição binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    cotacao novaCotacao;
    strncpy(novaCotacao.nome, nome, sizeof(novaCotacao.nome) - 1);
    novaCotacao.nome[sizeof(novaCotacao.nome) - 1] = '\0'; // Garante o término da string
    novaCotacao.valor = valor;

    fwrite(&novaCotacao, sizeof(cotacao), 1, arquivo); // Adiciona a nova cotação ao arquivo
    printf("Criptomoeda adicionada: %s -> %.2f\n", novaCotacao.nome, novaCotacao.valor);

    fclose(arquivo);
