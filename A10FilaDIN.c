//MÉTODOS:
//inicializar 28
//tamanho 33
//exibir 42
//inserir 50
//excluir 61
//reinicializar 73

#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO, *PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}FILA;
/////////////////////////////////////////////////////////////////////////////////////////
void inicializarFila(FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanho(FILA *f){
    PONT end = f->inicio;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
}

void exibirFila(FILA *f){
    PONT end = f->inicio;
    while(end != NULL){
        printf("%i ", end->reg.chave);
        end = end->prox;      
    }
}

bool inserirFila(FILA *f, REGISTRO reg){
    PONT end = (PONT) malloc(sizeof(ELEMENTO));
    end->reg = reg;
    end->prox = NULL;
    if(f->inicio == NULL)
        f->inicio = end;
    else f->fim->prox = end;
    f->fim = end;
    return true;
}

void excluirFila(FILA *f, REGISTRO *reg){
    if(f->inicio == NULL)
        return false;
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if(f->inicio == NULL)
        f->fim = NULL;
    return true;
}

void reinicializarFila(FILA *f){
    PONT end = f->inicio;
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

