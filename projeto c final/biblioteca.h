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

typedef struct {
    char nome[MAX_NOME_MOEDA];
    float valor;
    float cotven;
    float cotcomp;
} cotacao;

typedef struct {
    char cpf[MAX_CPF_LENGTH]; 
    cotacao moedas[MAX_MOEDAS];
    int num_moedas;            
} carteira;

//FUNÇÕES
void copiarCpfsParaCarteira(carteira* carteiras, char cpf_lista[NUM_OF_USERS][MAX_CPF_LENGTH], int num_usuarios)
void lerCotacoes(cotacao* cotacoes, int* num_cotacoes)
void iniciacao_arquivos(float *carteira, float *carteiraBit, float *carteiraEth, float *carteiraXrp, char *cpf_lista, char *senha_lista);
void atualizacao_das_carteiras(float *carteira,carteira*carteiras);
void apagarCripto(cotacao *cotacoes);
void mostrarSaldo(float *carteira,carteira* carteiras, int *indice);
int login_novo(int *indice, char *cpf, char *senha, char *cpf_lista[NUM_OF_USERS][12], char *senha_lista[NUM_OF_USERS][7]);
void extrato( char *cpf);
void atualizacao_das_carteiras(float *carteira,cotacao*cotacoes);
void depositar(float*carteira, const char *cpf, int *indice);
void sacar(float *carteira, const char *senha, int *indice, char *cpf);
void Comprar_criptomoedas(float *carteira,carteira* carteiras,cotacao* cotacoes, const char *senha,const char *cpf, int *indice);
void Vender_criptomoedas(float *carteira, carteira* carteiras,cotacao* cotacoes, const char *cpf, int *indice);
void Atualiza_cotacao(const char *cripto);
void mostrar_cotacoes(const char *cripto);
void criacao_cripto(const char *cripto);
int carrega_cotacao(const char *cripto, cotacao **cotacoes);
void extrato_adm (char cpf_lista[NUM_OF_USERS][12], char senha_lista[NUM_OF_USERS][7]);
void mostrarSaldo_adm(float *carteira,carteira* carteiras, char cpf_lista[NUM_OF_USERS][12]);
void cadastrar_inv(char cpf_lista[NUM_OF_USERS][12]);
int menu();
int menu_adm();
#endif
