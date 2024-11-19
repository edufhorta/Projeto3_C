#include "biblioteca.h"


void criacao_cripto() {
    FILE *arquivo;
    char nome_cripto[50]; // Buffer for the cryptocurrency name
    int valor_ini;
    float cot_ven, cot_comp;

    // Input cryptocurrency details
    printf("Escolha um nome para a sua criptomoeda: ");
    scanf("%49s", nome_cripto); // Limit input to prevent overflow
    printf("Escolha seu valor inicial: ");
    scanf("%d", &valor_ini);
    printf("Escolha sua cotação...\n");
    printf("De Venda: ");
    scanf("%f", &cot_ven); // Use %f for float
    printf("E de Compra: ");
    scanf("%f", &cot_comp); // Use %f for float

    // Create the filename
    int array[10];
    char filename[60]; // Buffer to hold the filename
    snprintf(filename, sizeof(filename), "saldo%s.bin", nome_cripto); // Create filename


    arquivo = fopen(filename, "wb");

    
    size_t escrevao = fwrite(array, sizeof(array), 10, arquivo);


    fclose(arquivo);

    printf("Dados salvos no arquivo '%s' com sucesso.\n", filename);

}
