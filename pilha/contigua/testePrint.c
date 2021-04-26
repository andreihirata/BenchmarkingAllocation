#include "pilhaContigua.h"

void printInteiro(void* n){
	int* p = n;
	printf("%d", *p);
}


void printFloat(void* n){
	float* p = n;
	printf("%f", *p);
}

int main(){
	Pilha* p = pilha_criar();
	pilha_empilhar(p, 10);
	pilha_empilhar(p, 20);
	pilha_empilhar(p, 30);
	pilha_imprimir(p, &printInteiro);
	pilha_destruir(&p);
}