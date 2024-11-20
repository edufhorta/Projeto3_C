#include "biblioteca.h"

int carrega_cotacao(const char *cripto, cotacao **cotacoes){
    FILE *arquivo = fopen("cripto", "r"); // Abre o arquivo texto em modo leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'\n", cripto);
        return -1; // Retorna -1 em caso de erro
    }

    cotacao *endereco = NULL; // Ponteiro auxiliar para alocação dinâmica
    int num_cot = 0;

    while (1) {
        cotacao c; // Variável para armazenar temporariamente a cotação
        char linha[128]; // Buffer para leitura de cada linha do arquivo

        // Lê uma linha do arquivo texto
        if (fgets(linha, sizeof(linha), arquivo) == NULL) {
            break; // Sai do loop ao alcançar o final do arquivo
        }

        // Faz a leitura do nome, valor, taxa de venda e taxa de compra
        if (sscanf(linha, "%49s %f %f %f", c.nome, &c.valor, &c.cotven, &c.cotcomp) != 4) {
            printf("Erro ao interpretar a linha: %s\n", linha);
            continue; // Ignora linhas inválidas
        }

        // Realoca espaço para armazenar mais uma cotação
        endereco = realloc(*cotacoes, (num_cot + 1) * sizeof(cotacao));
        if (endereco == NULL) {
            perror("Erro ao alocar memória");
            free(*cotacoes);
            fclose(arquivo);
            return -1; // Retorna -1 em caso de erro de memória
        }

        *cotacoes = endereco; // Atualiza o ponteiro original para o novo bloco de memória
        (*cotacoes)[num_cot] = c; // Armazena a nova cotação no vetor
        num_cot++; // Incrementa o número de cotações carregadas
    }

    fclose(arquivo); // Fecha o arquivo após a leitura
    return num_cot; // Retorna o número de cotações carregadas
}
