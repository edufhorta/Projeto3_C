#include "biblioteca.h"

int carrega_cotacao(const char *crip, cotacao **cotacoes){
    FILE *arquivo = fopen(crip, "r"); // Abre o arquivo texto em modo leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    cotacao *endereco = NULL; // Ponteiro auxiliar para armazenar o novo endereço de memória
    int num_cot = 0;

    while (1) {
        cotacao c; // Variável para armazenar temporariamente a cotação
        char linha[128]; // Linha temporária para leitura do arquivo

        // Lê uma linha do arquivo texto
        if (fgets(linha, sizeof(linha), arquivo) == NULL) {
            break; // Sai do loop ao alcançar o final do arquivo
        }

        // Converte a linha lida para nome e valor
        if (sscanf(linha, "%29s %f", c.nome, &c.valor) != 2) {
            printf("Erro ao interpretar a linha: %s\n", linha);
            continue; // Ignora linhas inválidas
        }

        // Realoca espaço para armazenar mais uma cotação
        endereco = realloc(*cotacoes, (num_cot + 1) * sizeof(cotacao));
        if (endereco == NULL) {
            perror("Erro ao alocar memória");
            free(*cotacoes);
            fclose(arquivo);
            return -1; // Se ocorrer um erro, libera a memória e retorna
        }

        *cotacoes = endereco; // Atualiza o ponteiro original para o novo bloco de memória
        (*cotacoes)[num_cot] = c; // Armazena a nova cotação no vetor
        num_cot++; // Incrementa o número de cotações
    }

    fclose(arquivo); // Fecha o arquivo após a leitura
    return num_cot; // Retorna o número de cotações carregadas
}
