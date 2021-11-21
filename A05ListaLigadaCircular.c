//MÉTODOS:
//inicializar 31
//tamanho 36
//exibir 46
//buscar 54
//inserir 89
//excluir 101
//reinicializar 111

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
    PONT cabeca;
}LISTA;
/////////////////////////////////////////////////////////////////////////////////////////
void incializarLista(LISTA* l){
    l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
}

int tamanho(LISTA* l){
    PONT end = l->cabeca->prox;
    int tam = 0;
    while(end != l->cabeca){
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirLista(LISTA* l){
    PONT end = l->cabeca->prox;
    while (end != l->cabeca){
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
}

PONT buscaSentinela(LISTA* l, TIPOCHAVE ch){
    PONT end = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while(end->reg.chave != ch){
        end = end->prox;
    }
    if(end != l->cabeca)
        return end;
    return NULL;
}

PONT buscaSentinelaOrd(LISTA* l, TIPOCHAVE ch){
    PONT end = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while(end->reg.chave < ch){
        end = end->prox;
    }
    if(end != l->cabeca && end->reg.chave == ch)
        return end;
    return NULL;
}

PONT buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONT* ant){
    *ant = l->cabeca;
    PONT end = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while(end->reg.chave < ch){
        *ant = end;
        end = end->prox
    }
    if(end != l->cabeca && end->reg.chave == ch)
        return end;
    return NULL;
}

bool inserirElemLista(LISTA* l, REGISTRO reg){
    PONT ant, end;
    end = buscaSequencialExc(l, ch, &ant);
    if(end != NULL)
        return false;
    end = (PONT) malloc(sizeof(ELEMENTO));
    end->reg = reg;
    end->prox = ant->prox;
    ant->prox = end;
    return true;
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
    PONT ant, end;
    end = buscaSequencialExc(l, ch, &ant);
    if(end == NULL)
        return false;
    ant->prox = end->prox;
    free(end);
    return true;
}

void reinicializarLista(LISTA* l){
    PONT end = l->cabeca->prox;
    while(end != l->cabeca){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->cabeca->prox = l->cabeca;
}


