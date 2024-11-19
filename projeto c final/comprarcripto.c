#include "biblioteca.h"

void Comprar_criptomoedas(cotacao *criptomoeda,float *carteira,, const char *senha,const char *cpf, int *indice) {
    int opcao;
    float valor, quantidade, taxa, total;
    FILE *file;
    char dataAtual[20], sen[7]; 
    char confirma;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Comprar Cripto:\n");
    for (int i=0;i<sizeof(criptomoeda);i++){
        if (criptomoeda[i].valor == 0){
            continue;
        }
    printf("%d- %s",criptomoeda[i].nome);
    }
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);


       
            printf("Quanto de %s gostaria de comprar? (Taxa de compra = %f%) R$ ",criptomoeda[i].nome,criptomoeda[i].cotcomp);
            scanf("%f", &valor);
            while (valor > carteira[*indice]) {
                printf("ERRO: Você não pode comprar mais do que o disponível em sua carteira!! (carteira: %.2f)\n", carteira[*indice]);
                printf("Quanto de %s gostaria de comprar? (Taxa de compra = %f%) R$ ",criptomoeda[i].nome,criptomoeda[i].cotcomp);
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
            taxa = (criptomoeda[i].cotcomp / 100.00) * valor;
            total = valor - taxa;
            quantidade = total / *criptomoeda[i].valor;


            while (1) {
                printf("Compra de %.6f %s: %.2f - %.2f (Taxa de Compra) = %.2f\n", quantidade,criptomoeda[i].nome, valor, taxa, total);
                printf("Confirmação de transação -  (s/n): ");
                getchar(); 
                scanf("%c", &confirma);
                if (confirma == 's') {
                    carteira[*indice] -= total;
                    carteiraBit[*indice] += quantidade;//mudar
                    printf("Compra realizada com sucesso!\n");
                    snprintf(dataAtual, sizeof(dataAtual), "%02d-%02d-%04d %02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
                    file = fopen("extrato.bin", "a");
                    if (file == NULL) {
                        perror("Erro ao abrir extrato.bin");
                        exit(EXIT_FAILURE);
                    }
                    fprintf(file, "%s %s COMPRA - %.2f REAIS CT:%.2f   TX:%.2f \n",cpf, dataAtual, valor,criptomoeda[i].valor,criptomoeda[i].cotcomp);
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



          
