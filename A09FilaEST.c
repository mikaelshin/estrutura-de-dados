//MÉTODOS:
//inicializar 26
//tamanho 31
//exibir 35
//inserir 44
//excluir 53
//reinicializar 62

#include <stdio.h>

#define MAX 50

tyfedef int bool;
tyfedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int inicio;
    int nroElem;
}FILA;
/////////////////////////////////////////////////////////////////////////////////////////
void inicializarFila(FILA *f){
    f->inicio = 0;
    f->nroElem = 0;
}

int tamanho(FILA *f){
    return f->nroElem;
}

void exibirFila(FILA *f){
    int i;
    int j = f->inicio;
    for(i = 0; i < f->nroElem; i++){
    printf("%i ", f->A[j].chave);
    j = (j + 1) % MAX;
    }
}

bool inserirFila(FILA *f, REGISTRO reg){
    if(f->nroElem > MAX)
        return false;
    int pos = (f->inicio + f->nroElem) % MAX;
    f->A[pos] = reg;
    f->nroElem++;
    return true;
}

void excluirFila(FILA *f, REGISTRO *reg){
    if(f->nroElem == 0)
        return false;
    *reg = f->A[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->nroElem--;
    return true;
}

void reinicializarFila(FILA *f){
    inicializarFila(f);
}

