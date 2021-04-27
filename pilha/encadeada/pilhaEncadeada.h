#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int TipoElemento;

typedef struct _pilhaEncadeada PilhaEncadeada;

PilhaEncadeada* pilha_encadeada_criar();
void pilha_encadeada_destruir(PilhaEncadeada* p);
void pilha_encadeada_destruir_v2(PilhaEncadeada** p);

bool pilha_encadeada_empilhar(PilhaEncadeada* p, TipoElemento elemento);
bool pilha_encadeada_desempilhar(PilhaEncadeada* p, TipoElemento* saida);
bool pilha_encadeada_topo(PilhaEncadeada* p, TipoElemento* saida);
bool pilha_encadeada_vazia(PilhaEncadeada* p);
void pilha_encadeada_imprimir(PilhaEncadeada* p);
int pilha_encadeada_tamanho(PilhaEncadeada* p);

//Implementar como exercicio.
PilhaEncadeada* pilha_encadeada_clone(PilhaEncadeada* p);
void pilha_encadeada_inverter(PilhaEncadeada* p);
bool pilha_encadeada_empilharTodos(PilhaEncadeada* p, TipoElemento* vetor, int tamVetor);
void pilha_encadeada_printQueue(PilhaEncadeada *p, void *printElemento(void *));
