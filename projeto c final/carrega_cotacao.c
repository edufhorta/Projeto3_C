#include "biblioteca.h"

int carrega_cotacao(const char *crip, cotacao **cotacoes){
    FILE *arquivo;
    arquivo = fopen(crip, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    cotacao *endereco = NULL;  // Ponteiro auxiliar para armazenar o novo endereço de memória
    int num_cot = 0;

    while (1) {
        cotacao c;  // A variável 'c' é declarada aqui, dentro do loop
        size_t tamLido = fread(&c, sizeof(cotacao), 1, arquivo);
        if (tamLido == 0) {
            break;  // Sai do loop quando o fim do arquivo for alcançado
        }

        // Realoca o espaço de memória para armazenar mais uma cotação
        endereco = realloc(*cotacoes, (num_cot + 1) * sizeof(cotacao));
        if (endereco == NULL) {
            perror("Erro ao alocar memória");
            free(*cotacoes);
            fclose(arquivo);
            return -1;  // Se ocorrer um erro, libera a memória e retorna
        }

        *cotacoes = endereco;  // Atualiza o ponteiro original para o novo bloco de memória
        (*cotacoes)[num_cot] = c;  // Armazena a nova cotação no vetor
        num_cot++;  // Incrementa o número de cotações
    }

    fclose(arquivo);  // Fecha o arquivo após a leitura
    return num_cot;  // Retorna o número de cotações carregadas
}
