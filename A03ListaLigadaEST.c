//MÉTODOS:
//inicializar 31
//tamanho 40
//exibir 50
//busca seq 59
//inserir lista ordenada 76
//excluir 105
//reinicializar 121

#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox;
}ELEMENTO;

typedef struct{
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
}LISTA;


void inicializarLista(LISTA* l){
    int i;
    for(i = 0; i < MAX - 1; i++)
        l->A[i].prox = i + 1;
    l->A[MAX-1].prox = INVALIDO;
    l->inicio = INVALIDO;
    l->dispo = 0;
}

int tamanho(LISTA* l){
    int i = l->inicio;
    int tam = 0;
    while(i != INVALIDO){
        tam++
        i = l->A[i].prox;
    }
    return tam;
}

void exibirLista(LISTA* l){
    int i = l->inicio;
    while(i != INVALIDO){
        printf("%i", l->A[i].reg.chave)
        printf("\n");
        i = l->A[i].prox;
    }
}

int buscaSequencialOrd(LISTA* l, TIPOCHAVE ch){
    int i = l->inicio;
    while(i != INVALIDO && l->A[i].reg.chave < ch){
        if(A[i].chave == ch)
            return i;
        else l->A[i].prox;
    }
    return INVALIDO;
}

int obterNo(LISTA* l){
    int resultado = l->dispo;
    if(l->dispo != INVALIDO)
        l->dispo = l->A[l->dispo].prox;
    return resultado;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
    if(l->dispo == INVALIDO)
        return false;
    int ant = INVALIDO;
    int i = l->inicio;
    TIPOCHAVE ch = reg.chave;
    while((i != INVALIDO) && (l->A[i].reg.chave < ch)){
        ant = i;
        i = l->A[i].prox;
    }
    if(i != INVALIDO && l->A[i].reg.chave == ch)
        return false;
    i = obterNo(l);
    l->A[i].reg = reg;
    if (ant == INVALIDO){
        l->A[i].prox = l->inicio;
        l->inicio = i;
    } else {
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
    return true;
}

void devolverNo(LISTA* l, int i){
    l->A[i].prox = l->dispo;
    l->dispo = i;
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
    int ant = INVALIDO;
    int i = l->inicio;
    while ((i != INVALIDO) && (l->A[i].reg.chave < ch)) {
        ant = i;
        i = l->A[i].prox;
    }
    if(i == INVALIDO || l->A[i].reg.chave != ch)
        return false;
    if(ant == INVALIDO)
        l->inicio = l->A[i].prox;
    else l->A[ant].prox = l->A[i].prox;
    deolverNo(l, i);
    return true;
}

void reinicializarLista(LISTA* l){
    inicializarLista(l);
}
