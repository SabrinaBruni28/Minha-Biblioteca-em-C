#include "bina.h"

/*Funcao que gera um numero aleatorio entre 0 e o numero escolhido.*/
int Numero_Aleatorio(int topo){
    int n;
    srand((unsigned)time(NULL));
    n = rand()%topo;
    return n;
}
/*Funcao que confere se dois numeros sao igual.
  Retorna 1 se forem iguais e 0 caso contrario.*/
int Igual(int a, int b){
    if(a == b) return 1;
    return 0;
}
/*Funcao que printa uma sequencia de asteriscos.*/
void Asterisco(int n, int cor){
    int i;
    char a;
    a = '*';
    for(i=0; i<n; i++) printf("\033[1;%dm%c\033[m",cor,a);
    printf("\n");
}
/*Funcao que escreve uma string no arquivo escolhido.*/
void Insere_String_Arquivo(FILE* arquivo, char* string){
    fprintf(arquivo, "%s", string); 				  
}
/*Funcao que deixa um vetor todo em maiusculo.
  Retornando a nova string maiuscula.*/
char* Toupper_Vetor(char* string, int tam){
    int i;
    char* vetor= (char*)malloc(sizeof(int)*tam);
    strcpy(vetor, string);
    for(i=0;i<tam;i++){
        vetor[i] = toupper(string[i]);
    }
    return vetor;
}
/*Funcao que elimina o \n do final das strings e substitui por \0.*/
void Elinima_Final_Vetor(char*  vetor){
    int i;
    for(i=0; vetor[i]; i++) 
        if(vetor[i]=='\n'){ 
            vetor[i]='\0';
            break;
        }
}
/*Funcao que printa cada linha de um arquivo.*/
void Imprime_Arquivo(FILE* arquivo, int tamanho){
    char string[tamanho];
    fflush(arquivo);
    int cont = 1;
    while(!feof(arquivo)){
        fgets(string, tamanho, arquivo);
        if(!feof(arquivo))
            printf("%d- %s", cont, string);
        cont++;
    }
}
/*Funcao que printa uma matriz de caracteres.*/
void Print_Matriz_Char(int linhas, int colunas, char matriz[linhas][colunas]){
    int i,j;
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++)
            printf("%c ", matriz[i][j]);
        printf("\n");
    }
}
/*Funcao que printa uma matriz de inteiros.*/
void Print_Matriz_Int(int linhas, int colunas, int matriz[linhas][colunas]){
    int i,j;
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

/*Funcao que printa uma matriz de strings.*/
void Print_Matriz_String(int linhas, int colunas, char matriz[linhas][colunas]){
    int i,j;
    for(i=0;i<linhas;i++){
        printf("%s\n", matriz[i]);
    }
}

/*Funcao que printa o titulo desejado.*/
void Titulo(char* titulo, int cor){
    printf("\t\t\033[1;%dm###### %s #######\033[m\n", cor, titulo);
}

/*Funcao que zera a string, para nao ocorrer erro na hora de sobrepor.*/
void Zera_Palavra(char* string, int n){
    int i;
    for(i=0; i<n; i++)
        string[i] = '\0';
}

/*Funcao que confere se uma string e igual a outra.
  Retorna 1 caso seja igual e 0 caso contrario.*/
int String_Igual(char* string1, char* string2){
    int i;
    if(strcmp(Toupper_Vetor(string1, strlen(string1)), Toupper_Vetor(string2, strlen(string2))) == 0) return 1;
    return 0;
}

/*Funcao que abre determinado arquivo.
  Retorna 1 caso der certo e 0 caso de erro no arquivo.*/
int Inicializa_Arquivo(FILE* arquivo, char* texto){
    arquivo = fopen(texto, "r");
    if(arquivo == NULL){
        printf("\033[1;31m**** FALHA AO ABRIR ARQUIVO ****\n\033[m");
        return 0;
    }
    printf("\033[1;32m**** ARQUIVO ABERTO COM SUCESSO ****\n\033[m");
    return 1;
}
/*Funcao que confere se uma determinada letra existe em uma string.
  Retorna a quantidade de vezes que a letra aparece na string.*/
int Existe_Letra(char* string, char letra){
    int i, cont = 0;
    for(i=0; i<strlen(string); i++){
        if((toupper(string[i])) == (toupper(letra))){
            cont++;
        }
    }
    return cont;
}