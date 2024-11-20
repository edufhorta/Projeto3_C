#include "biblioteca.h"

//CARREGAMENTO DOS ARQUIVOS.
void iniciacao_arquivos(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp,char *cpf_lista, char *senha_lista) {
     FILE *carteirafile;
     FILE *carteirabitfile;
     FILE *carteiraethfile;
     FILE *carteiraxrpfile;

       

     
     carteirafile = fopen("saldo.bin","rb");
     size_t lendo = fread(carteira, sizeof(float),10,carteirafile);
     fclose(carteirafile);

    carteirabitfile = fopen("saldobit.bin","rb");
     size_t lendobit = fread(carteiraBit, sizeof(float),10,carteirabitfile);
     fclose(carteirabitfile);
    carteiraethfile = fopen("saldoeth.bin","rb");
     size_t lendoeth = fread(carteiraEth, sizeof(float),10,carteiraethfile);
     fclose(carteiraethfile);
    carteiraxrpfile = fopen("saldoxrp.bin","rb");
     size_t lendoxrp = fread(carteiraXrp, sizeof(float),10,carteiraxrpfile);
     fclose(carteiraxrpfile);

};
