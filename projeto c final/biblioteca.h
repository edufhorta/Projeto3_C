#ifndef Biblioteca_h
#define Biblioteca_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#define NUM_OF_USERS 10

//FUNÇÕES
void atualizacao_das_carteiras(float *carteira,float *carteiraBit,float *carteiraEth,float *carteiraXrp);
void mostrarSaldo(float *carteira, float *carteiraBit, float *carteiraEth,float *carteiraXrp, int *indice);
void login(int *indice, char *cpf, char *senha, char *cpf_lista[NUM_OF_USERS][12], char *senha_lista[NUM_OF_USERS][7]);
void extrato( char *cpf);
void atualizacao_das_carteiras(float *carteira,float *carteiraBit,float *carteiraEth,float *carteiraXrp);
void depositar(float*carteira, float*carteiraBit, float*carteiraEth, float*carteiraXrp, const char *cpf, int *indice);
void sacar(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, const char *senha, int *indice, char *cpf);
void Comprar_criptomoedas(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, const char *senha,const char *cpf, int *indice, float *bit, float *eth, float *rip);
void Vender_criptomoedas(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, const char *cpf, int *indice, float *bit, float *eth, float *rip);
void Atualiza_cotacao(float *bit, float *eth, float *rip);
void Cotacao_inicial(float *bit, float *eth, float *rip);
int menu();
#endif