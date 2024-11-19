#include "biblioteca.h"

void Atualiza_cotacao(const char *crip){
      FILE *arquivo = fopen(crip, "r"); // Abre o arquivo texto para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    // Cria um arquivo temporário para armazenar as cotações atualizadas
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário\n");
        fclose(arquivo);
        return;
    }

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    char nome[30];
    float valor;

    // Lê cada linha do arquivo texto, atualiza o valor e grava no arquivo temporário
    while (fscanf(arquivo, "%29s %f", nome, &valor) == 2) {
        int num = rand() % 100; // Gera um número aleatório entre 0 e 99

        // Atualiza o valor com aumento ou redução de 5%
        if (num % 2 == 0) {
            valor += ((5 / 100.0) * valor);
        } else {
            valor -= ((5 / 100.0) * valor);
        }

        // Escreve a cotação atualizada no arquivo temporário
        fprintf(temp, "%s %.2f\n", nome, valor);

        // Exibe a atualização no console
        printf("Atualizado: %s -> %.2f\n", nome, valor);
    }

    fclose(arquivo); // Fecha o arquivo original
    fclose(temp);    // Fecha o arquivo temporário

    // Substitui o arquivo original pelo arquivo temporário
    remove(crip);
    rename("temp.txt", crip);

    printf("\nCotações atualizadas com sucesso!\n");
  getchar();
  
};
