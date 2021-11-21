//MÉTODOS:
//inicializar 31
//tamanho 35
//exibir 45
//buscar 54
//inserir 86
//excluir 104
//reinicializar 116

#include <stdio.h>
#include <malloc.h>

typedef int bool;
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
    PONT inicio;
}LISTA;
/////////////////////////////////////////////////////////////////////////////////////////
void incializarLista(LISTA* l){
    l->inicio = NULL;
}

int tamanho(LISTA* l){
    PONT end = l->inicio;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirLista(LISTA* l){
    PONT end = l->inicio;
    while (end != NULL){
        printf("%i", end->reg.chave);
        printf("\n");
        end = end->prox;
    }
}

PONT buscaSequencial(LISTA* l, TIPOCHAVE ch){
    PONT end = l->inicio;
    while(end != NULL){
        if(end->reg.chave == ch)
            return end;
        end = end->prox;
    }
    return NULL;
}

PONT buscaSequencialOrd(LISTA* l, TIPOCHAVE ch){
    PONT end = l->inicio;
    while(end != NULL && end->reg.chave < ch){
        end = end->prox;
        if(end->reg.chave == ch && end != NULL) 
            return end;
    }
    return NULL;
}

PONT buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONT* ant){
    *ant = NULL;
    PONT atual = l->inicio;
    while((atual != NULL) && (atual->reg.chave < ch)){
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL) && (atual->reg.chave == ch))
        retuan atual;
    return NULL;
}

bool inserirElemLista(LISTA* l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if(i != NULL)
        return false;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    if(ant == NULL){
        i->prox = l->inicio;
        l->inicio = i;
    } else {
        i->prox = ant->prox;
        ant->prox = i;
    }
    return true;
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
    PONT ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if (i == NULL)
        return false;
    if (ant == NULL)
        l->inicio = i->prox;;
    else ant->prox = i->prox;
    free(i);
    return true;
}

void reinicializarLista(LISTA* l){
    PONT end = l->inicio;
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}


