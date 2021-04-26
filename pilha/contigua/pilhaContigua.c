#include "pilhaContigua.h"

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
struct _pilha {
	TipoElemento* vetor;
	int tamVetor;
	int qtdeElementos;
};


/**************************************
* FUNÇÕES AUXILIARES
**************************************/

void verifica_aumenta(Pilha* p){
    if(p->qtdeElementos < p->tamVetor) return;

    int novoTamanho = p->tamVetor * 2;
    TipoElemento* vetorAuxiliar = (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    for(i = 0; i < p->qtdeElementos; i++) vetorAuxiliar[i] = p->vetor[i];
    free(p->vetor);
    p->vetor = vetorAuxiliar;
    p->tamVetor = novoTamanho;
}

void verifica_reduz(Pilha* p){
    int livre = p->tamVetor - p->qtdeElementos;
    if( livre < (p->tamVetor / 2) || p->tamVetor == TAM_INICIAL ) return;

    int novoTamanho = p->tamVetor / 2;
    TipoElemento* vetorAuxiliar = (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    for(i = 0; i < p->qtdeElementos; i++) 
        vetorAuxiliar[i] = p->vetor[i];
    free(p->vetor);
    p->vetor = vetorAuxiliar;
    p->tamVetor = novoTamanho;
}


bool pilha_ehValida(Pilha* p){
    return (p != NULL? true: false);
    
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/

Pilha* pilha_criar(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->vetor = (TipoElemento*) calloc(TAM_INICIAL, sizeof(TipoElemento));
    p->tamVetor = TAM_INICIAL;
    p->qtdeElementos = 0;
    return p;
}


/*void pilha_destruir(Pilha* p){
    if(!pilha_ehValida(p)) return ;

    free(p->vetor);
    free(p);
}*/

void pilha_destruir(Pilha** endPilha){
    if(!pilha_ehValida(*endPilha)) return;

    free((*endPilha)->vetor);
    free(*endPilha);
    *endPilha = NULL;
}

bool pilha_empilhar(Pilha* p, TipoElemento elemento){
    if(!pilha_ehValida(p)) return false;
    verifica_aumenta(p);

    p->vetor[p->qtdeElementos++] = elemento;
    return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_ehValida(p)) return false;
    if(pilha_vazia(p)) return false;

    *saida = p->vetor[--p->qtdeElementos];

    verifica_reduz(p);
    
    return true;

}

bool pilha_topo(Pilha* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_ehValida(p)) return false;
    if(pilha_vazia(p)) return false;
    
    *saida = p->vetor[p->qtdeElementos-1];
    return true;

}

bool pilha_vazia(Pilha* p){
    if(!pilha_ehValida(p)) return false;

    return (p->qtdeElementos == 0? true: false);
}

/*void pilha_imprimir(Pilha* p){
    if(!pilha_ehValida(p)) return;
    
    printf("Contígua");
    printf("[");
    int i;
    for(i=p->qtdeElementos-1; i >=0 ; i--){
        printf("%d", p->vetor[i]);
        if(i >= 1) printf(", ");
    }
    printf("]");
}*/

void pilha_imprimir(Pilha* p, void (*printElemento)(void*)){
    if(!pilha_ehValida(p)) return;
    
    printf("Contígua");
    printf("[");
    int i;
    for(i=p->qtdeElementos-1; i >=0 ; i--){
        printElemento(&p->vetor[i]);
        if(i >= 1) printf(", ");
    }
    printf("]");
}

int pilha_tamanho(Pilha* p){
    if(!pilha_ehValida(p)) return false;

    return p->qtdeElementos;
}

Pilha* pilha_clone(Pilha* p){
    if(!pilha_ehValida(p)) return NULL;

    Pilha* clone = pilha_criar();
    int i;
    for(i=0; i < p->qtdeElementos ; i++){
        pilha_empilhar(clone, p->vetor[i]);
    }
    return clone;
}

void pilha_inverter(Pilha* p){
    if(!pilha_ehValida(p)) return;
    if(pilha_vazia(p)) return;

    int inicio = 0;
    int fim = p->qtdeElementos-1;

    while(inicio < fim){
        int temp = p->vetor[inicio];
        p->vetor[inicio] = p->vetor[fim];
        p->vetor[fim] = temp;

        inicio++;
        fim--;
    }
}

bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
    if(!pilha_ehValida(p)) return false;

    int i;
    for(i=0; i < tamVetor ; i++){
        pilha_empilhar(p, vetor[i]);
    }
    return true;
}
