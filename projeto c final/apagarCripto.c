#include "biblioteca.h"
void apagarCripto(cotacao *cripto) {
    char nome_cripto[50];

    printf("Qual criptomoeda você gostaria de apagar: ");
    scanf("%50s", nome_cripto); 
  for (int i = 0; i < sizeof(cripto); i++) {
       
        if (strcmp(cripto[i].nome, nome_cripto) == 0) {
        cripto[i].valor = 0; 
          
        strcpy(cripto[i].nome, ""); 
          cripto[i].cotven = 0.0; 
          
        cripto[i].cotcomp =0.0;
    }
    }
}
