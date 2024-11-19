#include "biblioteca.h"

void Atualiza_cotacao(const char *crip){
      FILE *arquivo = fopen(crip, "r"); // Abre o arquivo texto para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w"); // Cria um arquivo temporário

    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário\n");
        fclose(arquivo);
        return;
    }

    srand(time(NULL)); // Inicializa o gerador de números aleatórios


    char nome[50];
    float valor, cotven, cotcomp;

    // Lê cada linha do arquivo original
    while (fscanf(arquivo, "%49s %f %f %f", nome, &valor, &cotven, &cotcomp) == 4) {
        int num = rand() % 100; // Número aleatório entre 0 e 99


        // Atualiza o valor com aumento ou redução de 5%
        if (num % 2 == 0) {
            valor += ((5 / 100.0) * valor);
        } else {
            valor -= ((5 / 100.0) * valor);
        }

        // Escreve os valores atualizados no arquivo temporário, mantendo as taxas
        fprintf(temp, "%s %.2f %.2f %.2f\n", nome, valor, cotven, cotcomp);

        // Exibe a atualização no console
        printf("Atualizado: %s -> Valor: %.2f, Taxa de Venda: %.2f, Taxa de Compra: %.2f\n",
               nome, valor, cotven, cotcomp);

    }

    fclose(arquivo); // Fecha o arquivo original
    fclose(temp);    // Fecha o arquivo temporário

    // Substitui o arquivo original pelo arquivo temporário
    remove(crip);
    rename("temp.txt", crip);

    printf("\nCotações atualizadas com sucesso!\n");
      
  getchar();
  
};
