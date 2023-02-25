#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/*Cores para o terminal.*/
#define CINZA 37
#define VERDEAGUA 36
#define ROXO 35
#define AZUL 34
#define AMARELO 33
#define VERDE 32
#define VERMELHO 31
#define BRANCO 30
/*Style do terminal.*/
#define NADA 0
#define BOLD 1
#define ENDERLINE 4
#define NEGATIVE 7
/*Cor do fundo do terminal*/
#define cinza 47
#define verdeagua 46
#define roxo 45
#define azul 44
#define amarelo 43
#define verde 42
#define vermelho 41
#define branco 40

/*Funcao que gera um numero aleatorio entre 0 e o numero escolhido.*/
int Numero_Aleatorio(int topo);
/*Funcao que confere se dois numeros sao igual.
  Retorna 1 se forem iguais e 0 caso contrario.*/
int Igual_Inteiro(int a, int b);
/*Funcao que confere se dois caracteres sao igual.
  Retorna 1 se forem iguais e 0 caso contrario.*/
int Igual_char(char a, char b);
/*Funcao que printa uma sequencia de asteriscos.*/
void Asterisco(int n, int cor);
/*Funcao que escreve uma string no arquivo escolhido.*/
void Insere_String_Arquivo(FILE* arquivo, char* string);
/*Funcao que deixa um vetor todo em maiusculo.
  Retornando a nova string maiuscula.*/
char* Toupper_Vetor(char* string, int tam);
/*Funcao que elimina o \n do final das strings e substitui por \0.*/
void Elinima_Final_Vetor(char*  vetor);
/*Funcao que printa cada linha de um arquivo.*/
void Imprime_Arquivo(FILE* arquivo, int tamanho);
/*Funcao que printa uma matriz de caracteres.*/
void Print_Matriz_Char(int linhas, int colunas, char matriz[linhas][colunas]);
/*Funcao que printa uma matriz de inteiros.*/
void Print_Matriz_Int(int linhas, int colunas, int matriz[linhas][colunas]);
/*Funcao que printa uma matriz de strings.*/
void Print_Matriz_String(int linhas, int colunas, char matriz[linhas][colunas]);
/*Funcao que printa o titulo desejado.*/
void Titulo(char* titulo, int cor);
/*Funcao que zera a string, para nao ocorrer erro na hora de sobrepor.*/
void Zera_Palavra(char* string, int n);
/*Funcao que confere se uma string e igual a outra.
  Retorna 1 caso seja igual e 0 caso contrario.*/
int String_Igual(char* string1, char* string2);
/*Funcao que abre determinado arquivo.
  Retorna 1 caso der certo e 0 caso de erro no arquivo.*/
int Inicializa_Arquivo(FILE* arquivo, char* texto);
/*Funcao que confere se uma determinada letra existe em uma string.
  Retorna a quantidade de vezes que a letra aparece na string.*/
int Existe_Letra(char* string, char letra);