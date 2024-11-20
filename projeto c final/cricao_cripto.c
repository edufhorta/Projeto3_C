#include "biblioteca.h"


void criacao_cripto(const char *cripto) {
     FILE *arquivo = fopen(cripto, "a"); // Abre o arquivo texto em modo de adição
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'\n", crip);
        return;
    }

    char nome[50];
    float valor, cotven, cotcomp;

    // Solicita os dados da nova criptomoeda
    printf("Digite o nome da criptomoeda: ");
    scanf("%49s", nome);

    printf("Digite o valor inicial da criptomoeda: ");
    scanf("%f", &valor);

    printf("Digite a taxa de venda: ");
    scanf("%f", &cotven);

    printf("Digite a taxa de compra: ");
    scanf("%f", &cotcomp);

    // Escreve os dados no arquivo texto
    fprintf(arquivo, "%s %.2f %.2f %.2f\n", nome, valor, cotven, cotcomp);

    printf("Criptomoeda '%s' adicionada com sucesso: Valor: %.2f, Taxa de Venda: %.2f, Taxa de Compra: %.2f\n",
           nome, valor, cotven, cotcomp);

    fclose(arquivo); // Fecha o arquivo

}
