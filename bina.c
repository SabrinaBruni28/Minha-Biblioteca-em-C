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
int Igual_Inteiro(int a, int b){
    if(a == b) return 1;
    return 0;
}
/*Funcao que confere se dois caracteres sao igual.
  Retorna 1 se forem iguais e 0 caso contrario.*/
int Igual_char(char a, char b){
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
    char* vetor_maiusculo= (char*)malloc(sizeof(char)*tam);
    strcpy(vetor_maiusculo, string);
    for(i=0;i<tam;i++){
        vetor_maiusculo[i] = toupper(string[i]);
    }
    return vetor_maiusculo;
}
/*Funcao que deixa um vetor todo em minusculo.
  Retornando a nova string minuscula.*/
char* Tolower_Vetor(char* string, int tam){
    int i;
    char* vetor_minusculo= (char*)malloc(sizeof(char)*tam);
    strcpy(vetor_minusculo, string);
    for(i=0; i<tam; i++){
        vetor_minusculo[i] = tolower(string[i]);
    }
    return vetor_minusculo;
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

/*   Funcoes de Ordenar Vetores de Inteiros   */
/*Funcao de ordenacao de vetor de inteiros Bolha.*/
void Bolha_Int (int* v, int n ){
    int i, j;
    int aux;
    for( i = 0 ; i < n-1 ; i++ ){
        for( j = 1 ; j < n-i ; j++ )
            if ( v[j] < v[j-1] ){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
    }
}
/*Funcao de ordenacao de vetor de inteiros Bolha Melhorado*/
void BolhaMelhorado_Int (int* v, int n ){
    int i, j, troca;
    int aux;
    for( i = 0 ; i < n-1 ; i++ ){
        troca = 0;
        for( j = 1 ; j < n-i ; j++ ){
            if ( v[j] < v[j-1] ){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                troca = 1;
            } 
        }
    if (troca == 0)
        break;
    }
}
/*Funcao de ordenacao de vetor de inteiros Insercao.*/
void Insercao_Int (int* v, int n ){
    int i,j;
    int aux;
    for (i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
        while ( ( j >= 0 ) && ( aux < v[j] ) ){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}
/*Funcao de ordenacao de vetor de inteiros Selecao.*/
void Selecao_Int (int* v, int n){
    int i, j, Min;
    int aux;
    for (i = 0; i < n - 1; i++){
        Min = i;
        for (j = i + 1 ; j < n; j++)
            if ( v[j] < v[Min])
                Min = j;
            aux = v[Min];
            v[Min] = v[i];
            v[i] = aux;
    }
}
/*Funcao de ordenacao de vetor de inteiros Shell.*/
void Shellsort_Int (int* A, int n){
    int i, j;
    int h = 1;
    int aux;
    do h = h * 3 + 1; while (h < n);
    do{
        h = h/3;
        for( i = h ; i < n ; i++ ){
            aux = A[i]; j = i;
            while (A[j - h] > aux){
                A[j] = A[j - h]; j -= h;
                if (j < h) 
                    break;
            }
            A[j] = aux;
        }
    } while (h != 1);
}
/*Funcao que controi o heap.*/
void Constroi_Int(int *A, int *n){
    int Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1){
        Esq--;
        Refaz_Int(Esq, *n, A);
    }
}
/*Funcao que refaz o head.*/
void Refaz_Int(int Esq, int Dir, int *A){
    int j = Esq * 2;
    int aux = A[Esq];
    while (j <= Dir){
        if ((j < Dir)&&(A[j] < A[j+1])) 
            j++;
        if (aux >= A[j]) 
            break;
        A[Esq] = A[j];
        Esq = j; j = Esq * 2;
    }
    A[Esq] = aux;
}
/*Funcao de ordenacao de vetor de inteiros Heap.*/
void Heapsort_Int(int *A, int *n){
    int Esq, Dir;
    int aux;
    Constroi_Int(A, n); /* constroi o heap */
    Esq = 1; 
    Dir = *n;
    while (Dir > 1){ /* ordena o vetor */
        aux = A[1]; 
        A[1] = A[Dir]; 
        A[Dir] = aux;
        Dir--;
        Refaz_Int(Esq, Dir, A);
    }
}
/*Funcao que faz a particao do quick.*/
void Particao_Int(int Esq, int Dir, int *i, int *j, int *A){
    int pivo, aux;
    *i = Esq; *j = Dir;
    pivo = A[(*i + *j)/2]; /* obtem o pivo x */
    do{
        while (pivo > A[*i]) 
            (*i)++;
        while (pivo < A[*j]) 
            (*j)--;
        if (*i <= *j){
            aux = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = aux;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}
/*Funcao que ordena o quick.*/
void Ordena_Int(int Esq, int Dir, int *A){
    int i,j;
    Particao_Int(Esq, Dir, &i, &j, A);
    if (Esq < j) 
        Ordena_Int(Esq, j, A);
    if (i < Dir) 
        Ordena_Int(i, Dir, A);
}
/*Funcao de ordenacao de vetor de inteiros Quick.*/
void QuickSort_Int(int *A, int n){
    Ordena_Int(0, n-1, A);
}

/*   Funcoes de Ordenar Vetores de caracteres   */
/*Funcao de ordenacao de vetor de caracteres Bolha.*/
void Bolha_Char (char* v, int n ){
    int i, j;
    char aux;
    for( i = 0 ; i < n-1 ; i++ ){
        for( j = 1 ; j < n-i ; j++ )
            if ( v[j] < v[j-1] ){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
    }
}
/*Funcao de ordenacao de vetor de caracteres Bolha Melhorado*/
void BolhaMelhorado_Char (char* v, int n ){
    int i, j, troca;
    char aux;
    for( i = 0 ; i < n-1 ; i++ ){
        troca = 0;
        for( j = 1 ; j < n-i ; j++ ){
            if ( v[j] < v[j-1] ){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                troca = 1;
            } 
        }
    if (troca == 0)
        break;
    }
}
/*Funcao de ordenacao de vetor de caracteres Insercao.*/
void Insercao_Char (char* v, int n ){
    int i,j;
    char aux;
    for (i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
        while ( ( j >= 0 ) && ( aux < v[j] ) ){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}
/*Funcao de ordenacao de vetor de caracteres Selecao.*/
void Selecao_Char (char* v, int n){
    int i, j, Min;
    char aux;
    for (i = 0; i < n - 1; i++){
        Min = i;
        for (j = i + 1 ; j < n; j++)
            if ( v[j] < v[Min])
                Min = j;
            aux = v[Min];
            v[Min] = v[i];
            v[i] = aux;
    }
}
/*Funcao de ordenacao de vetor de caracteres Shell.*/
void Shellsort_Char (char* A, int n){
    int i, j;
    int h = 1;
    char aux;
    do h = h * 3 + 1; while (h < n);
    do{
        h = h/3;
        for( i = h ; i < n ; i++ ){
            aux = A[i]; j = i;
            while (A[j - h] > aux){
                A[j] = A[j - h]; j -= h;
                if (j < h) 
                    break;
            }
            A[j] = aux;
        }
    } while (h != 1);
}
/*Funcao que controi o heap.*/
void Constroi_Char(char *A, int *n){
    int Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1){
        Esq--;
        Refaz_Char(Esq, *n, A);
    }
}
/*Funcao que refaz o head.*/
void Refaz_Char(int Esq, int Dir, char *A){
    int j = Esq * 2;
    char aux = A[Esq];
    while (j <= Dir){
        if ((j < Dir)&&(A[j] < A[j+1])) 
            j++;
        if (aux >= A[j]) 
            break;
        A[Esq] = A[j];
        Esq = j; j = Esq * 2;
    }
    A[Esq] = aux;
}
/*Funcao de ordenacao de vetor de caracteres Heap.*/
void Heapsort_Char(char *A, int *n){ 
    int Esq, Dir;
    char aux;
    Constroi_Char(A, n); /* constroi o heap */
    Esq = 1; 
    Dir = *n;
    while (Dir > 1){ /* ordena o vetor */
        aux = A[1]; 
        A[1] = A[Dir]; 
        A[Dir] = aux;
        Dir--;
        Refaz_Char(Esq, Dir, A);
    }
}
/*Funcao que faz a particao do quick.*/
void Particao_Char(int Esq, int Dir, int *i, int *j, char *A){
    char pivo, aux;
    *i = Esq; *j = Dir;
    pivo = A[(*i + *j)/2]; /* obtem o pivo x */
    do{
        while (pivo > A[*i]) 
            (*i)++;
        while (pivo < A[*j]) 
            (*j)--;
        if (*i <= *j){
            aux = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = aux;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}
/*Funcao que ordena o quick.*/
void Ordena_Char(int Esq, int Dir, char *A){
    int i,j;
    Particao_Char(Esq, Dir, &i, &j, A);
    if (Esq < j) 
        Ordena_Char(Esq, j, A);
    if (i < Dir) 
        Ordena_Char(i, Dir, A);
}
/*Funcao de ordenacao de vetor de caracteres Quick.*/
void QuickSort_Char(char *A, int n){
    Ordena_Char(0, n-1, A);
}