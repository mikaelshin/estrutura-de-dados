//MÉTODOS:
//inicializar 30
//tamanho 36
//exibir 46
//inserir 54
//excluir 64
//reinicializar 75

#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* ant;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT cabeca;
}DEQUE;
/////////////////////////////////////////////////////////////////////////////////////////
void inicializarDeque(DEQUE *d){
    d->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

int tamanho(DEQUE *d){
    PONT end = d->cabeca->prox;
    int tam = 0;
    while(end != d->cabeca){
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirDeque(DEQUE *d){
    PONT end = d->cabeca->ant;
    while(end != d->cabeca){
        printf("%i ", end->reg.chave);
        end = end->ant;
    }
}

bool inserirDequeFim(DEQUE *d, REGISTRO reg){
    PONT end = (PONT) malloc(sizeof(ELEMENTO));
    end->reg = reg;
    end->prox = d->cabeca;
    end->ant = d->cabeca->ant;
    d->cabeca->ant = end;
    end->ant->prox = end;
    return true;
}

void excluirDeque(DEQUE *d, REGISTRO *reg){
    if(d->cabeca->prox == d->cabeca)
        return false;
    PONT apagar = d->cabeca->prox;
    *reg = apagar->reg;
    d->cabeca->prox = apagar->prox;
    apagar->prox->ant = d->cabeca;
    free(apagar);
    return true;
}

void reinicializarDeque(DEQUE *d){
    PONT end = d->cabeca->prox;
    while(end != d->cabeca){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    d->cabeca->ant = d->cabeca;
    d->cabeca->prox = d->cabeca;
}

