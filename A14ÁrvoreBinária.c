//NOMENCLATURA: 

//grau: 0, 1 ou 2 dependendo da qntd de filhos que o nó tem
//nível: de raiz pra folha
//altura: do nó até a folha (caminho mais longo)
//profundidade: do nó até a raiz 
//folhas: n tem filho 

//METODOS:
//inicializar
//inserir
//criar no
//buscar
//contar
//exibir
//excluir

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
    TIPOCHAVE chave;
    struct aux *esq, *dir;
}NO;

typedef NO* PONT;

PONT inicializarArvore(){
    return(NULL);
}

PONT inserirArvore(PONT raiz, PONT no){
    if(raiz == NULL)
        return no;
    if(no->chave < raiz->chave)
        raiz->esq = inserirArvore(raiz->esq, no);
    else
        raiz->dir = inserirArvore(raiz->dir, no);
    return raiz;
}

/*
int main(){
    PONT r = inicializarArvore();
    PONT no = criaNo('chave a ser inserido');
    r = inserirArvore(r, no);    
}
*/

PONT criaNo(TIPOCHAVE ch){
    PONT novoNo = (PONT) malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return novoNo; 
}

PONT buscaArvore(PONT raiz, TIPOCHAVE ch){
    if(raiz == NULL)
        return NULL;
    if(raiz->chave == ch)
        return raiz;
    if(raiz->chave > ch){
        return buscaArvore(ch, raiz->esq);
    return buscaArvore(ch, raiz->dir); 
    }
}

int numeroNos(PONT raiz){
    if(!raiz)
        return 0;
    return numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir);
}

void exibirArvore(PONT raiz){
    if(raiz != NULL){
        printf("%i", raiz->chave);
        printf("(");
        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
        printf(")");
    }
}

PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){
    PONT atual = raiz;
    *pai = NULL;
    while(atual != NULL){
        if(atual->chave == ch)
            return atual;
        *pai = atual;
        if(ch < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return NULL;
}

PONT excluirNo(PONT raiz, TIPOCHAVE ch){
    PONT pai, no, p, q;
    no = buscaNo(raiz, ch, &pai);
    if(no == NULL)
        return raiz;
    if(no->esq == NULL || no->dir == NULL){
        if(no->esq == NULL)
            q = no->dir;
        q = no->esq;
    } else {
        p = no;
        q = no->esq;
        while(q->dir){
            p = q;
            q = q->dir;
        }
        if(p != no){
            p->dir = q->dir;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if(pai == NULL){
        free(no);
        return q;
    }
    if(ch < pai->chave)
        pai->esq = q;
    else 
        pai->dir = q;
    free(no);
    return raiz;
}
