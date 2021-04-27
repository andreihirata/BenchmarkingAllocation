#include "pilhaContigua.h"

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
struct _pilhaContigua {
	TipoElemento* vetor;
	int tamVetor;
	int qtdeElementos;
};


/**************************************
* FUNÇÕES AUXILIARES
**************************************/

void verifica_aumenta(PilhaContigua* p){
    if(p->qtdeElementos < p->tamVetor) return;

    int novoTamanho = p->tamVetor * 2;
    TipoElemento* vetorAuxiliar = (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    for(i = 0; i < p->qtdeElementos; i++) vetorAuxiliar[i] = p->vetor[i];
    free(p->vetor);
    p->vetor = vetorAuxiliar;
    p->tamVetor = novoTamanho;
}

void verifica_reduz(PilhaContigua* p){
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


bool pilha_contigua_ehValida(PilhaContigua* p){
    return (p != NULL? true: false);
    
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/

PilhaContigua* pilha_contigua_criar(){
    PilhaContigua* p = (PilhaContigua*) malloc(sizeof(PilhaContigua));
    p->vetor = (TipoElemento*) calloc(TAM_INICIAL, sizeof(TipoElemento));
    p->tamVetor = TAM_INICIAL;
    p->qtdeElementos = 0;
    return p;
}


/*void pilha_contigua_destruir(Pilha* p){
    if(!pilha_ehValida(p)) return ;

    free(p->vetor);
    free(p);
}*/

void pilha_contigua_destruir(PilhaContigua** endPilha){
    if(!pilha_contigua_ehValida(*endPilha)) return;

    free((*endPilha)->vetor);
    free(*endPilha);
    *endPilha = NULL;
}

bool pilha_contigua_empilhar(PilhaContigua* p, TipoElemento elemento){
    if(!pilha_contigua_ehValida(p)) return false;
    verifica_aumenta(p);

    p->vetor[p->qtdeElementos++] = elemento;
    return true;
}

bool pilha_contigua_desempilhar(PilhaContigua* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_contigua_ehValida(p)) return false;
    if(pilha_contigua_vazia(p)) return false;

    *saida = p->vetor[--p->qtdeElementos];

    verifica_reduz(p);
    
    return true;

}

bool pilha_contigua_topo(PilhaContigua* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_contigua_ehValida(p)) return false;
    if(pilha_contigua_vazia(p)) return false;
    
    *saida = p->vetor[p->qtdeElementos-1];
    return true;

}

bool pilha_contigua_vazia(PilhaContigua* p){
    if(!pilha_contigua_ehValida(p)) return false;

    return (p->qtdeElementos == 0? true: false);
}

/*void pilha_contigua_imprimir(Pilha* p){
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

void pilha_contigua_imprimir(PilhaContigua* p, void (*printElemento)(void*)){
    if(!pilha_contigua_ehValida(p)) return;
    
    printf("Contígua");
    printf("[");
    int i;
    for(i=p->qtdeElementos-1; i >=0 ; i--){
        printElemento(&p->vetor[i]);
        if(i >= 1) printf(", ");
    }
    printf("]");
}

int pilha_tamanho(PilhaContigua* p){
    if(!pilha_contigua_ehValida(p)) return false;

    return p->qtdeElementos;
}

PilhaContigua* pilha_contigua_clone(PilhaContigua* p){
    if(!pilha_contigua_ehValida(p)) return NULL;

    PilhaContigua* clone = pilha_contigua_criar();
    int i;
    for(i=0; i < p->qtdeElementos ; i++){
        pilha_contigua_empilhar(clone, p->vetor[i]);
    }
    return clone;
}

void pilha_contigua_inverter(PilhaContigua* p){
    if(!pilha_contigua_ehValida(p)) return;
    if(pilha_contigua_vazia(p)) return;

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

bool pilha_contigua_empilharTodos(PilhaContigua* p, TipoElemento* vetor, int tamVetor){
    if(!pilha_contigua_ehValida(p)) return false;

    int i;
    for(i=0; i < tamVetor ; i++){
        pilha_contigua_empilhar(p, vetor[i]);
    }
    return true;
}
