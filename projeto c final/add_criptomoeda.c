#include "biblioteca.h"

void adicionar_criptomoeda(const char *crip) {
    FILE *arquivo = fopen(crip, "a"); // Abre o arquivo em modo de adição de texto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    cotacao novaCotacao;

    // Solicita os dados da nova criptomoeda
    printf("Digite o nome da criptomoeda: ");
    scanf("%29s", novaCotacao.nome); // Limita o tamanho do nome para evitar estouro de buffer

    printf("Digite o valor inicial da criptomoeda: ");
    scanf("%f", &novaCotacao.valor);

    // Grava a nova criptomoeda no arquivo como texto
    fprintf(arquivo, "%s %.2f\n", novaCotacao.nome, novaCotacao.valor);

    printf("Criptomoeda adicionada com sucesso: %s -> %.2f\n", novaCotacao.nome, novaCotacao.valor);

    fclose(arquivo); // Fecha o arquivo após a escrita
}
