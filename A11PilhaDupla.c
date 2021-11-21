/MÉTODOS:
//inicializar 25
//tamanho 30
//exibir 34
//inserir 47
//excluir 60
//reinicializar 77

#include <stdio.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int topo1;
    int topo2;
}PILHADULHA;
/////////////////////////////////////////////////////////////////////////////////////////
void inicializarPilhaDupla(PILHADUPLA *p){
    p->topo1 = -1;
    p->topo2 = MAX;
}

int tamanhoPilhaDupla(PILHADUPLA *p){
    return p->topo1 + 1 + MAX - p->topo2;
}

void exibirPilhaDupla(PILHADUPLA *p, int pilha){
    if (pilha < 1 || pilha > 2)
        return false;
    int i;  
    if (pilha == 1) 
        for (i = p->topo1; i>=0; i--) 
            printf("%i ", p->A[i].chave);
    else for (i = p->topo2; i<MAX; i++) 
        printf("%i ", p->A[i].chave);
    return true;
    }
}

bool inserirPilhaDupla(PILHADUPLA *p, REGISTRO reg, int pilha){
    if (pilha < 1 || pilha > 2)
        return false;
    if(pilha == 1){
        p->topo1++;
        p->A[p->topo1] = reg;
    } else {
        p->topo2--;
        p->A[p->topo2] = reg;
    }
    return true;
}

void excluirPilhaDupla(PILHADUPLA *p, REGISTRO *reg, int pilha){
    if (pilha < 1 || pilha > 2)
        return false;
    if(pilha == 1){
        if(p->topo1 == -1)
            return false
        *reg = p->A[p->topo1];
        p->topo1--;
    } else {
        if(p->topo2 == MAX)
            return false
        *reg = p->A[p->topo2];
        p->topo2++;
    }
    return true;
}

void reinicializarPilhaDupla(PILHADUPLA *p){
    inicializarPilhaDupla(p);
}

