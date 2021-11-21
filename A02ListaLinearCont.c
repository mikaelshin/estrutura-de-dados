//MÉTODOS:
//busca por sentinela 21
//busca binaria 32
//excluir 49

#include <stdio.h>

#define MAX 50 

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX + 1];
    int nroElem;
} LISTA;

int buscaSentinela(LISTA* l, TIPOCHAVE ch){
    l->A[l->nroElem].chave = ch;
    int i = 0;
    while (ch != l->A[i].chave){
        i++;
    }
    if (i == l->A[nroElem])
        return -1;
    else return i;
}

int buscaBinaria(LISTA* l, TIPOCHAVE ch){
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem - 1;
    while(esq < dir){
        meio = (esq+dir)/2;
        if(ch == l->A[meio])
            return meio;
        else{
            if(ch > l->A[meio])
                esq = meio + 1;
            else dir = meio - 1;
        }
    }
    return -1;
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
    int pos, i;
    pos = buscaBinaria(l, ch);
    if(pos == -1) 
        return false;
    for(j = pos; j < nroElem - 1; j++)
        l->A[i] = l->A[i + 1];
        l->nroElem--;
        return true;
}