//https://www.techiedelight.com/find-execution-time-c-program/
//https://github.com/dlfcn-win32/dlfcn-win32

#include <stdio.h>
#include <time.h>

#include "pilha/contigua/pilhaContigua.h"
#include "pilha/contigua/pilhaContigua.c"

//Tempo
#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

//Constantes
const int dado10 = 10000;
const int dado50 = 50000;
const int dado100 = 100000;
const int dado500 = 500000;

void printInteiro(void* n){
    int* p = n;
    printf("%d", *p);
}

//---------------------------------Funçôes Básicas-------------------------------------------
void basic_function_contigua_empilhar_imprimir(int value){
    printf(">>> TESTE EMPILHAR\n");
    Pilha* p = pilha_criar();
    for(int i=0;i<value;i++){
        pilha_empilhar(p, i);
    }

    pilha_imprimir(p, printInteiro);
    printf("\n");
    pilha_destruir(&p);
}

void basic_function_contigua_empilhar_desempilhar_imprimir(int value){
    printf(">>> TESTE EMPILHAR\n");
    Pilha* p = pilha_criar();
    for(int i=0;i<value;i++){
        pilha_empilhar(p, i);
    }
    printf(">>> TESTE DESEMPILHAR\n");
    int elemento;
    for(int i=0;i<value;i++){
        pilha_desempilhar(p, &elemento);
        printf("Removido: %d\n", elemento);
        int resultado = pilha_desempilhar(p, &elemento);
        if (!resultado){
            printf("Pilha vazia\n");
            break;
        }

    }
    pilha_destruir(&p);
}

void PilhaContiguaTest01(){

}
void PilhaContiguaTest02(){

}
void PilhaContiguaTest03(){

}


int main(){
    //Pilha de Alocação Contígua / Funções Básicas
    TICK(TIME_A);

    //basic_function_contigua_empilhar_imprimir(dado10);
    //basic_function_contigua_empilhar_imprimir(dado50);
    //basic_function_contigua_empilhar_imprimir(dado100);
    //basic_function_contigua_empilhar_imprimir(dado500);

    //basic_function_contigua_empilhar_desempilhar_imprimir((dado10));
    //basic_function_contigua_empilhar_desempilhar_imprimir((dado50));
    //basic_function_contigua_empilhar_desempilhar_imprimir((dado100));
    basic_function_contigua_empilhar_desempilhar_imprimir((dado500));

    TOCK(TIME_A);

    //MemoryTotal();

    //TICK(TIME_B);
    //functionB();
    //TOCK(TIME_B);

    return 0;
}




