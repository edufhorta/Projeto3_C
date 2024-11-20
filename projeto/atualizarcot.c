#include "biblioteca.h"

void Atualiza_cotacao(float *bit, float *eth, float *rip){
      srand(time(NULL));
  for (int i = 0; i < 3; i++) {
          int num = rand() % 100;

    switch (i) {
              case 0:
                  if (num % 2 == 0) {
                      *bit = *bit + ((5 / 100.0) * *bit);
                  } else {
                      *bit = *bit - ((5 / 100.0) * *bit);
                  }
                  break;

              case 1:
                  if (num % 2 == 0) {
                      *eth = *eth + ((5 / 100.0) * *eth);
                  } else {
                      *eth = *eth - ((5 / 100.0) * *eth);
                  }
                  break;

              case 2:
                  if (num % 2 == 0) {
                      *rip = *rip + ((5 / 100.0) * *rip);
                  } else {
                      *rip = *rip - ((5 / 100.0) * *rip);
                  }
                  break;

              default:
                  break;
          }
  }
  printf("Bitcoin: %.2f\n", *bit);
  printf("Ethereum: %.2f\n", *eth);
  printf("Ripple: %.2f\n", *rip);
  printf("\n");
  printf("Cotação atualizada\n");
  printf("\n<--- volte com 'ENTER'\n");
  getchar();

};