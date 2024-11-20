#include "biblioteca.h"

//CARREGAMENTO DOS ARQUIVOS.
void iniciacao_arquivos(float *carteira) {
     FILE *carteirafile;
     

     carteirafile = fopen("saldo.bin","rb");
     size_t lendo = fread(carteira, sizeof(float),10,carteirafile);
     fclose(carteirafile);
};
