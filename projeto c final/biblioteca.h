#ifndef Biblioteca_h
#define Biblioteca_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#define NUM_OF_USERS 1000
#define MAX_CPF_LENGTH 12
#define MAX_SENHA_LENGTH 7

//FUNÇÕES
void iniciacao_arquivos(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, char *cpf_lista, char *senha_lista);
void atualizacao_das_carteiras(float *carteira,float *carteiraBit,float *carteiraEth,float *carteiraXrp);
void mostrarSaldo(float *carteira, float *carteiraBit, float *carteiraEth,float *carteiraXrp, int *indice);
int login_novo(int *indice, char *cpf, char *senha, char *cpf_lista[NUM_OF_USERS][12], char *senha_lista[NUM_OF_USERS][7]);
void extrato( char *cpf);
void atualizacao_das_carteiras(float *carteira,float *carteiraBit,float *carteiraEth,float *carteiraXrp);
void depositar(float*carteira, float*carteiraBit, float*carteiraEth, float*carteiraXrp, const char *cpf, int *indice);
void sacar(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, const char *senha, int *indice, char *cpf);
void Comprar_criptomoedas(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, const char *senha,const char *cpf, int *indice, float *bit, float *eth, float *rip);
void Vender_criptomoedas(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, const char *cpf, int *indice, float *bit, float *eth, float *rip);
void Atualiza_cotacao(const char *crip);
void criacao_cripto(const char *crip);
int carrega_cotacao(const char *crip, cotacao **cotacoes);
void extrato_adm (char cpf_lista[NUM_OF_USERS][12], char senha_lista[NUM_OF_USERS][7]);
void mostrarSaldo_adm(float *carteira, float *carteiraBit, float *carteiraEth,float *carteiraXrp, char cpf_lista[NUM_OF_USERS][12]);
void cadastrar_inv(char cpf_lista[NUM_OF_USERS][12]);
int menu();
int menu_adm();
#endif
