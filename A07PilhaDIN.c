//MÉTODOS:
//inicializar 29
//tamanho 33
//pilha vazia 44
//exibir 50
//inserir 58
//excluir 66
//reinicializar 76

#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT topo;
}PILHA;
/////////////////////////////////////////////////////////////////////////////////////////
void inicializarPilha(PILHA *p){
    p->topo = NULL;
}

int tamanho(PILHA *p){
    PONT end = p->topo;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

bool estaVazia(PILHA* p){
    if(p->topo == NULL)
        return true;
    return false;
}

void exibirPilha(PILHA *p){
    PONT end = p->topo;
    while(end != NULL){
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
}

bool inserirPilha(PILHA *p, REGISTRO reg){
    PONT end = (PONT) malloc(sizeof(ELEMENTO));
    end->reg = reg;
    end->prox = p->topo;
    p->topo = end;
    return true;
}

void excluirPilha(PILHA *p, REGISTRO *reg){
    if(p->topo == NULL)
        return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo
    p->topo = p->topo->prox;
    free(apagar)
    return true;
}

void reinicializarPilha(PILHA *p){
    PONT apagar;
    PONT end = p->topo;
    while(end != NULL){
        apagar = end;
        free(apagar);
        end = end->prox;
    }
    p->topo = NULL;
}

