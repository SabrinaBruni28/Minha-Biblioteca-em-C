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
/*Funcao que printa uma sequencia de asteriscos.
  Na parte cor voce coloca um dos defines.
  Esta com BOLD como padrao, mas e possivel retirar escrevendo NADA.*/
void Asterisco(int n, int cor);
/*Funcao que escreve uma string no arquivo escolhido.*/
void Insere_String_Arquivo(FILE* arquivo, char* string);
/*Funcao que deixa um vetor todo em maiusculo.
  Retornando a nova string maiuscula.*/
char* Toupper_Vetor(char* string, int tam);
/*Funcao que deixa um vetor todo em minusculo.
  Retornando a nova string minuscula.*/
char* Tolower_Vetor(char* string, int tam);
/*Funcao que elimina o \n do final das strings e substitui por \0.*/
void Elinima_Final_String(char*  vetor);
/*Funcao que printa cada linha de um arquivo.
  O tamanho se refere a string.*/
void Imprime_Arquivo(FILE* arquivo, int tamanho);
/*Funcao que printa uma matriz de caracteres.*/
void Print_Matriz_Char(int linhas, int colunas, char matriz[linhas][colunas]);
/*Funcao que printa uma matriz de inteiros.*/
void Print_Matriz_Int(int linhas, int colunas, int matriz[linhas][colunas]);
/*Funcao que printa uma matriz de strings.*/
void Print_Matriz_String(int linhas, int colunas, char matriz[linhas][colunas]);
/*Funcao que printa o titulo desejado.*/
void Titulo(char* titulo, int cor);
/*Funcao que zera a string, para nao ocorrer erro na hora de sobrepor.
  O n e o tamanho do vetor.*/
void Zera_String(char* string, int n);
/*Funcao que confere se uma string e igual a outra.
  Retorna 1 caso seja igual e 0 caso contrario.*/
int String_Igual(char* string1, char* string2);
/*Funcao que abre determinado arquivo.
  Retorna 1 caso der certo e 0 caso de erro no arquivo.*/
int Inicializa_Arquivo(FILE* arquivo, char* texto);
/*Funcao que confere se uma determinada letra existe em uma string.
  Retorna a quantidade de vezes que a letra aparece na string.*/
int Existe_Letra(char* string, char letra);


/*Funcao de ordenacao de vetor de inteiros Bolha.*/
void Bolha_Int (int* v, int n );
/*Funcao de ordenacao de vetor de inteiros Bolha Melhorado*/
void BolhaMelhorado_Int (int* v, int n );
/*Funcao de ordenacao de vetor de inteiros Insercao.*/
void Insercao_Int (int* v, int n );
/*Funcao de ordenacao de vetor de inteiros Selecao.*/
void Selecao_Int (int* v, int n);
/*Funcao de ordenacao de vetor de inteiros Shell.*/
void Shellsort_Int (int* A, int n);
/*Funcao que controi o heap.*/
void Constroi_Int(int *A, int *n);
/*Funcao que refaz o head.*/
void Refaz_Int(int Esq, int Dir, int *A);
/*Funcao de ordenacao de vetor de inteiros Heap.*/
void Heapsort_Int(int *A, int *n);
/*Funcao que faz a particao do quick.*/
void Particao_Int(int Esq, int Dir, int *i, int *j, int *A);
/*Funcao que ordena o quick.*/
void Ordena_Int(int Esq, int Dir, int *A);
/*Funcao de ordenacao de vetor de inteiros Quick.*/
void QuickSort_Int(int *A, int n);


/*Funcao de ordenacao de vetor de caracteres Bolha.*/
void Bolha_Char (char* v, int n );
/*Funcao de ordenacao de vetor de caracteres Bolha Melhorado*/
void BolhaMelhorado_Char (char* v, int n );
/*Funcao de ordenacao de vetor de caracteres Insercao.*/
void Insercao_Char (char* v, int n );
/*Funcao de ordenacao de vetor de caracteres Selecao.*/
void Selecao_Char (char* v, int n);
/*Funcao de ordenacao de vetor de caracteres Shell.*/
void Shellsort_Char (char* A, int n);
/*Funcao que controi o heap.*/
void Constroi_Char(char *A, int *n);
/*Funcao que refaz o head.*/
void Refaz_Char(int Esq, int Dir, char *A);
/*Funcao de ordenacao de vetor de caracteres Heap.*/
void Heapsort_Char(char *A, int *n);
/*Funcao que faz a particao do quick.*/
void Particao_Char(int Esq, int Dir, int *i, int *j, char *A);
/*Funcao que ordena o quick.*/
void Ordena_Char(int Esq, int Dir, char *A);
/*Funcao de ordenacao de vetor de caracteres Quick.*/
void QuickSort_Char(char *A, int n);