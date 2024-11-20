#include "biblioteca.h"

void Comprar_criptomoedas(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, const char *senha,const char *cpf, int *indice, float *bit, float *eth, float *rip) {
    int opcao;
    float valor, quantidade, taxa, total;
    FILE *file;
    char dataAtual[20], sen[7]; 
    char confirma;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Comprar Cripto:\n");
    printf("1 - Bitcoin\n");
    printf("2 - Ethereum\n");
    printf("3 - Ripple\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: // Bitcoin
            printf("Quanto de Bitcoin gostaria de comprar? (Taxa de compra = 2%%) R$ ");
            scanf("%f", &valor);
            while (valor > carteira[*indice]) {
                printf("ERRO: Você não pode comprar mais do que o disponível em sua carteira!! (carteira: %.2f)\n", carteira[*indice]);
                printf("Quanto de Bitcoin gostaria de comprar? (Taxa de compra = 2%%) R$ ");
                scanf("%f", &valor);
            }
            // Solicitar a senha
            while (1) {
                printf("Digite sua senha para a validação da compra: ");
                scanf("%s", sen);
                if (strcmp(senha, sen) == 0) {
                    break;
                } else {
                    printf("Senha incorreta, tente novamente.\n");
                }
            }
            taxa = (2.00 / 100.00) * valor;
            total = valor - taxa;
            quantidade = total / *bit;


            while (1) {
                printf("Compra de %.6f Bitcoin: %.2f - %.2f (Taxa de Compra) = %.2f\n", quantidade, valor, taxa, total);
                printf("Confirmação de transação -  (s/n): ");
                getchar(); 
                scanf("%c", &confirma);
                if (confirma == 's') {
                    carteira[*indice] -= total;
                    carteiraBit[*indice] += quantidade;
                    printf("Compra realizada com sucesso!\n");
                    snprintf(dataAtual, sizeof(dataAtual), "%02d-%02d-%04d %02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
                    file = fopen("extrato.bin", "a");
                    if (file == NULL) {
                        perror("Erro ao abrir extrato.bin");
                        exit(EXIT_FAILURE);
                    }
                    fprintf(file, "%s %s COMPRA - %.2f REAIS CT:%.2f   TX:0.02 REAL:%.2f BTC:%.6f ETH:%.5f XRP:%.3f\n",cpf, dataAtual, valor,*bit, carteira[*indice], carteiraBit[*indice], carteiraEth[*indice], carteiraXrp[*indice]);
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
            printf("Quanto de Ethereum gostaria de comprar? (Taxa de compra = 1%%) R$ ");
            scanf("%f", &valor);
            while (valor > carteira[*indice]) {
                printf("ERRO: Você não pode comprar mais do que o disponível em sua carteira!! (carteira: %.2f)\n", carteira[*indice]);
                printf("Quanto de Ethereum gostaria de comprar? (Taxa de compra = 1%%) R$ ");
                scanf("%f", &valor);
            }
            // Solicitar a senha
            while (1) {
                printf("Digite sua senha para a validação da compra: ");
                scanf("%s", sen);
                if (strcmp(senha, sen) == 0) {
                    break;
                } else {
                    printf("Senha incorreta, tente novamente.\n");
                }
            }
            taxa = (1.00 / 100.00) * valor;
            total = valor - taxa;
            quantidade = total / *eth;


            while (1) {
                printf("Compra de %.6f Ethereum: %.2f - %.2f (Taxa de Compra) = %.2f\n", quantidade, valor, taxa, total);
                printf("Confirmação de transação -  (s/n): ");
                getchar(); 
                scanf("%c", &confirma);
                if (confirma == 's') {
                    carteira[*indice] -= total;
                    carteiraEth[*indice] += quantidade;
                    printf("Compra realizada com sucesso!\n");
                    snprintf(dataAtual, sizeof(dataAtual), "%02d-%02d-%04d %02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
                    file = fopen("extrato.bin", "a");
                    if (file == NULL) {
                        perror("Erro ao abrir extrato.bin");
                        exit(EXIT_FAILURE);
                    }
                    fprintf(file, "%s %s COMPRA - %.2f REAIS CT:%.2f    TX:0.01 REAL:%.2f BTC:%.6f ETH:%.5f XRP:%.3f\n", cpf, dataAtual, valor,*eth, carteira[*indice], carteiraBit[*indice], carteiraEth[*indice], carteiraXrp[*indice]);
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
            printf("Quanto de Ripple gostaria de comprar? (Taxa de compra = 1%%) R$ ");
            scanf("%f", &valor);
            while (valor > carteira[*indice]) {
                printf("ERRO: Você não pode comprar mais do que o disponível em sua carteira!! (carteira: %.2f)\n", carteira[*indice]);
                printf("Quanto de Ripple gostaria de comprar? (Taxa de compra = 1%%) R$ ");
                scanf("%f", &valor);
            }
            // Solicitar a senha
            while (1) {
                printf("Digite sua senha para a validação da compra: ");
                scanf("%s", sen);
                if (strcmp(senha, sen) == 0) {
                    break;
                } else {
                    printf("Senha incorreta, tente novamente.\n");
                }
            }
            taxa = (1.00 / 100.00) * valor;
            total = valor - taxa;
            quantidade = total / *rip;


            while (1) {
                printf("Compra de %.6f Ripple: %.2f - %.2f (Taxa de Compra) = %.2f\n", quantidade, valor, taxa, total);
                printf("Confirmação de transação -  (s/n): ");
                getchar(); 
                scanf("%c", &confirma);
                if (confirma == 's') {
                    carteira[*indice] -= total;
                    carteiraXrp[*indice] += quantidade;
                    printf("Compra realizada com sucesso!\n");
                    snprintf(dataAtual, sizeof(dataAtual), "%02d-%02d-%04d %02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
                    file = fopen("extrato.bin", "a");
                    if (file == NULL) {
                        perror("Erro ao abrir extrato.bin");
                        exit(EXIT_FAILURE);
                    }
                    fprintf(file, "%s %s COMPRA - %.2f REAIS CT:%.2f   TX:0.01 REAL:%.2f BTC:%.6f ETH:%.5f XRP:%.3f\n",cpf, dataAtual, valor,*rip, carteira[*indice], carteiraBit[*indice], carteiraEth[*indice], carteiraXrp[*indice]);
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

}