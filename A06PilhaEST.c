//MÉTODOS:
//inicializar 28
//tamanho 32
//exibir 36
//inserir 43
//excluir 51
//reinicializar 59

#include <stdio.h>

#define MAX 50
#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int topo;
}PILHA;
/////////////////////////////////////////////////////////////////////////////////////////
void inicializarPilha(PILHA *p){
    p->topo = -1;
}

int tamanho(PILHA *p){
    return p->topo + 1;
}

void exibirPilha(PILHA *p){
    int i;
    for(i = p->topo; i >= 0; i--){
        printf("%i ", p->A[i].chave);
    }
}

bool inserirPilha(PILHA *p, REGISTRO reg){
    if(p->topo >= MAX - 1)
        return false;
    p->topo++;
    p->A[p->topo] = reg;
    return true; 
}

void excluirPilha(PILHA *p, REGISTRO *reg){
    if(p->topo == -1)
        return false;
    *reg = p->A[p->topo];
    p->topo--;
    return true;
}

void reinicializarPilha(PILHA *p){
    p->topo = -1;
}

