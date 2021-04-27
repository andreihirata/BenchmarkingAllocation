#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int TipoElemento;

typedef struct _pilhaContigua PilhaContigua;

PilhaContigua* pilha_contigua_criar();
//void pilha_destruir(Pilha* p);
void pilha_contigua_destruir(PilhaContigua** endPilha);
bool pilha_contigua_empilhar(PilhaContigua* p, TipoElemento elemento);
bool pilha_contigua_desempilhar(PilhaContigua* p, TipoElemento* saida);
bool pilha_contigua_topo(PilhaContigua* p, TipoElemento* saida);
bool pilha_contigua_vazia(PilhaContigua* p);
//void pilha_contigua_imprimir(Pilha* p);
void pilha_contigua_imprimir(PilhaContigua* p, void (*printElemento)(void*));
int pilha_contigua_tamanho(PilhaContigua* p);
PilhaContigua* pilha_contigua_clone(PilhaContigua* p);
void pilha_contigua_inverter(PilhaContigua* p);
bool pilha_contigua_empilharTodos(PilhaContigua* p, TipoElemento* vetor, int tamVetor);
