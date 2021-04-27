#include "pilhaEncadeada.h"

#include <stdlib.h>

/**************************************
 * DADOS
 **************************************/
typedef struct no{
    TipoElemento dado;
    struct no    *prox;
}No;

struct _pilhaEncadeada{
    No *topo;
    int qtdeElementos;
};

/**************************************
 * FUNÇÕES AUXILIARES
 **************************************/
bool pilha_encadeada_ehValida(PilhaEncadeada* p){
    return (p != NULL? true: false);
}

No* criar_no(TipoElemento elemento, No* proximoNo){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    no->prox = proximoNo;
    return no;
}

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
PilhaEncadeada* pilha_encadeada_criar(){
    PilhaEncadeada* p = (PilhaEncadeada*) malloc(sizeof(PilhaEncadeada));
    p->topo = NULL;
    p->qtdeElementos = 0;
    return p;
}

void pilha_encadeada_destruir(PilhaEncadeada* p){
    if(!pilha_encadeada_ehValida(p)) return;

    No* aux;
    while(p->topo != NULL){
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }

    free(p);
}

bool pilha_encadeada_empilhar(PilhaEncadeada* p, TipoElemento elemento){
    if(!pilha_encadeada_ehValida(p)) return false;

    No* novo = criar_no(elemento, NULL);
    novo->prox = p->topo;
    p->topo = novo;
    p->qtdeElementos++;
    return true;
}

bool pilha_encadeada_desempilhar(PilhaEncadeada* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_encadeada_ehValida(p)) return false;
    if(pilha_encadeada_vazia(p)) return false;

    No* noRemovido = p->topo;
    p->topo = p->topo->prox;
    noRemovido->prox = NULL;
    p->qtdeElementos--;
    *saida = noRemovido->dado;
    free(noRemovido);

    return true;
}

bool pilha_encadeada_topo(PilhaEncadeada* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_encadeada_ehValida(p)) return false;
    if(pilha_encadeada_vazia(p)) return false;

    *saida = p->topo->dado;
    return true;
}

bool pilha_encadeada_vazia(PilhaEncadeada* p){
    return (p->qtdeElementos == 0? true: false);
}

void pilha_encadeada_imprimir(PilhaEncadeada* p){
    if(!pilha_encadeada_ehValida(p)) return;

    printf("Encadeada");
    printf("[");
    No* aux = p->topo;
    while(aux != NULL){
        printf("%d", aux->dado);
        if(aux->prox != NULL) printf(", ");
        aux = aux->prox;
    }
    printf("]");
}

int pilha_encadeada_tamanho(PilhaEncadeada* p){
    return p->qtdeElementos;
}

PilhaEncadeada* pilha_encadeada_clone(PilhaEncadeada* p) {
    PilhaEncadeada *c;

    int size;
    TipoElemento value;
    TipoElemento *buffer;

    c = pilha_encadeada_criar();
    buffer = NULL;
    size = 0;

    while ( pilha_encadeada_desempilhar(p, &value) != false ) {
        buffer = (TipoElemento *) realloc(buffer, ++size * sizeof(TipoElemento));
        buffer[size-1] = value;
    }

    while ( size > 0 ) {
        size--;
        pilha_encadeada_empilhar(p, buffer[size]);
        pilha_encadeada_empilhar(c, buffer[size]);
    }

    free(buffer);
    return c;
}
;
void pilha_encadeada_inverter(PilhaEncadeada* p) {
    int i;
    int size;
    TipoElemento value;
    TipoElemento *buffer;

    buffer = NULL;
    size = 0;

    while ( pilha_encadeada_desempilhar(p, &value) != false ) {
        buffer = (TipoElemento *) realloc(buffer, ++size * sizeof(TipoElemento));
        buffer[size-1] = value;
    }

    i = 0;
    while ( i < size ) {
        pilha_encadeada_empilhar(p, buffer[i]);
        i++;
    }

    free(buffer);
}

bool pilha_encadeada_empilharTodos(PilhaEncadeada* p, TipoElemento* vetor, int tamVetor) {
    int i;

    for ( i = 0; i < tamVetor; i++ ) {
        pilha_encadeada_empilhar(p, vetor[i]);
    }

    return true;
}

void pilha_encadeada_printQueue(PilhaEncadeada *p, void *printElemento(void *)) {
    printElemento(p);
}
