#include "biblioteca.h"

void atualizacao_das_carteiras(float *carteira,float *carteiraBit,float *carteiraEth,float *carteiraXrp){
     FILE *carteirafile;
     FILE *carteirabitfile;
     FILE *carteiraethfile;
     FILE *carteiraxrpfile;

     carteirafile = fopen("saldo.bin","wb");
     size_t escrevendo = fwrite(carteira, sizeof(float),10,carteirafile);
     fclose(carteirafile);

    carteirabitfile = fopen("saldobit.bin","wb");
     size_t escrevendobit = fwrite(carteiraBit, sizeof(float),10,carteirabitfile);
     fclose(carteirabitfile);
    carteiraethfile = fopen("saldoeth.bin","wb");
     size_t escrevendoeth = fwrite(carteiraEth, sizeof(float),10,carteiraethfile);
     fclose(carteiraethfile);
    carteiraxrpfile = fopen("saldoxrp.bin","wb");
     size_t escrevendoxrp = fwrite(carteiraXrp, sizeof(float),10,carteiraxrpfile);
     fclose(carteiraxrpfile);

};