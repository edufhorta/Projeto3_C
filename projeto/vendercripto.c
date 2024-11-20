#include "biblioteca.h"

void Vender_criptomoedas(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, const char *cpf, int *indice, float *bit, float *eth, float *rip) {
    int opcao;
    float valor, quantidade, taxa, total;
    char confirma;
    FILE *file;
    char dataAtual[20];
    time_t t = time(NULL);
    struct tm tm;
    tm = *localtime(&t);

    printf("Vender Cripto:\n");
    printf("1 - Bitcoin\n");
    printf("2 - Ethereum\n");
    printf("3 - Ripple\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: // Bitcoin
            printf("Quanto Bitcoins você gostaria de vender?(Taxa de venda = 3%%): ");
            scanf("%f", &quantidade);
            if (quantidade > carteiraBit[*indice]) {
                printf("ERRO: Você não pode vender mais Bitcoin do que o disponível em sua carteira!! (carteira: %.2f)\n", carteiraBit[*indice]);
                return;
            }
            valor = quantidade * *bit;
            taxa = (3.00 / 100.00) * valor;
            total = valor - taxa;
            while (1) {
                printf("Venda de %f Bitcoin: %.2f - %.2f (Taxa de venda) = %.2f\n", quantidade, valor, taxa, total);
                printf("Confirmação de transação -  (s/n): ");
                scanf(" %c", &confirma);  
                if (confirma == 's') {
                    carteira[*indice] += total;
                    carteiraBit[*indice] -= quantidade;
                    printf("Venda realizada com sucesso!\n");

                    snprintf(dataAtual, sizeof(dataAtual), "%02d-%02d-%04d %02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

                    file = fopen("extrato.bin", "a");
                    if (file == NULL) {
                        perror("Erro ao abrir extrato.bin");
                        exit(EXIT_FAILURE);
                    }
                    fprintf(file, "%s %s VENDA + %.2f REAIS CT:%.2f TX:0.03 REAL:%.2f BTC:%.6f ETH:%.5f XRP:%.3f\n", cpf, dataAtual, total, *bit, carteira[*indice], carteiraBit[*indice], carteiraEth[*indice], carteiraXrp[*indice]);
                    fclose(file);
                    break;
                } else if (confirma == 'n') {
                    printf("Transação cancelada!\n");
                    break;
                } else {
                    printf("ERRO: Escolha uma opção disponível!\n");
                }
            }
            break;

        case 2: // Ethereum
            printf("Quanto Ethereum você gostaria de vender?(Taxa de venda = 2%%): ");
            scanf("%f", &quantidade);
            if (quantidade > carteiraEth[*indice]) {
                printf("ERRO: Você não pode vender mais Ethereum do que o disponível em sua carteira!! (carteira: %.2f)\n", carteiraEth[*indice]);
                return;
            }
            valor = quantidade * *eth;
            taxa = (2.00 / 100.00) * valor;
            total = valor - taxa;
            while (1) {
                printf("Venda de %f Ethereum: %.2f - %.2f (Taxa de venda) = %.2f\n", quantidade, valor, taxa, total);
                printf("Confirmação de transação -  (s/n): ");
                scanf(" %c", &confirma);  
                if (confirma == 's') {
                    carteira[*indice] += total;
                    carteiraEth[*indice] -= quantidade;
                    printf("Venda realizada com sucesso!\n");

                    snprintf(dataAtual, sizeof(dataAtual), "%02d-%02d-%04d %02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

                    file = fopen("extrato.bin", "a");
                    if (file == NULL) {
                        perror("Erro ao abrir extrato.bin");
                        exit(EXIT_FAILURE);
                    }
                    fprintf(file, "%s %s VENDA + %.2f REAIS CT:%.2f TX:0.02 REAL:%.2f BTC:%.6f ETH:%.5f XRP:%.3f\n", cpf, dataAtual, total, *eth, carteira[*indice], carteiraBit[*indice], carteiraEth[*indice], carteiraXrp[*indice]);
                    fclose(file);
                    break;
                } else if (confirma == 'n') {
                    printf("Transação cancelada!\n");
                    break;
                } else {
                    printf("ERRO: Escolha uma opção disponível!\n");
                }
            }
            break;

        case 3: // Ripple
            printf("Quanto Ripple você gostaria de vender?(Taxa de venda = 1%%): ");
            scanf("%f", &quantidade);
            if (quantidade > carteiraXrp[*indice]) {
                printf("ERRO: Você não pode vender mais Ripple do que o disponível em sua carteira!! (carteira: %.2f)\n", carteiraXrp[*indice]);
                return;
            }
            valor = quantidade * *rip;
            taxa = (1.00 / 100.00) * valor;
            total = valor - taxa;
            while (1) {
                printf("Venda de %f Ripple: %.2f - %.2f (Taxa de venda) = %.2f\n", quantidade, valor, taxa, total);
                printf("Confirmação de transação -  (s/n): ");
                scanf(" %c", &confirma);  
                if (confirma == 's') {
                    carteira[*indice] += total;
                    carteiraXrp[*indice] -= quantidade;
                    printf("Venda realizada com sucesso!\n");

                    snprintf(dataAtual, sizeof(dataAtual), "%02d-%02d-%04d %02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

                    file = fopen("extrato.bin", "a");
                    if (file == NULL) {
                        perror("Erro ao abrir extrato.bin");
                        exit(EXIT_FAILURE);
                    }
                    fprintf(file, "%s %s VENDA + %.2f REAIS CT:%.2f TX:0.01 REAL:%.2f BTC:%.6f ETH:%.5f XRP:%.3f\n", cpf, dataAtual, total, *rip,carteira[*indice], carteiraBit[*indice], carteiraEth[*indice], carteiraXrp[*indice]);
                    fclose(file);
                    break;
                } else if (confirma == 'n') {
                    printf("Transação cancelada!\n");
                    break;
                } else {
                    printf("ERRO: Escolha uma opção disponível!\n");
                }
            }
            break;

        default:
            printf("Opção inválida.\n");
            return;
    }

    printf("\n<--- volte com 'ENTER'\n");
    getchar();
}