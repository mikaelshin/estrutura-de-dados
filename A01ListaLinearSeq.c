//MÉTODOS:
//inicializar 25
//tamanho 29
//exibir 32
//buscar 40
//inserir 50
//excluir 62
//reinicializar 74

#include <stdio.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int nroElem;
} LISTA;
/////////////////////////////////////////////////////////////////////////////////////////
void inicializarLista(LISTA* l){
    l->nroElem = 0;
}

int tamanho(LISTA* l){
    return l->tamanho;
}
void exibirLista(LISTA* l){
    int i;+++
    for(i = 0; i < l->nroElem; i++){
        printf("%i", l->A[i].chave)
        printf("\n");
    }
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch){
    int i;
    while(i < l->nroElem){
        if(ch == l->A[i].chave)
            return i;
        else i++;
    }
    return -1;
}

bool inserirElemLista(LISTA* l, REGISTRO reg, int i){
    int j;
    if((l->nroELem == MAX || (i < 0) || (i > l->nroElem))
        return false;
    for(j = l->nroElem; j > i; j--){
        l->A[j] = l->A[j - 1];
    }
    l->A[i] = reg;
    l->nroElem++;
    return true; 
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
    int pos, i;
    pos = buscaSequencial(l, ch);
    if (pos = -1)
        return false;
    for(i = pos; i < l->nroElem; i++){
        l->A[i] = l->A[i + 1];    
    }
    l->nroElem++;
    return true;
}

void reinicializarLista(LISTA* l){
    l->nroElem = 0;
}
