//https://www.techiedelight.com/find-execution-time-c-program/
//https://github.com/dlfcn-win32/dlfcn-win32
//https://pt.slideshare.net/lorivalschapuis/algoritmos-de-ordenao-8366612
//http://www2.dcc.ufmg.br/livros/algoritmos-edicao2/cap3/transp/completo4/cap3.pdf
//https://www.gnu.org/software/time/

#include <stdio.h>
#include <time.h>

//#include <sys/resource.h>
#include <windows.h>
#include <stdlib.h>
#include <errno.h>
//#include <unistd.h>
#include <psapi.h>

#include "pilha/contigua/pilhaContigua.h"
#include "pilha/contigua/pilhaContigua.c"

#include "pilha/encadeada/pilhaEncadeada.h"
#include "pilha/encadeada/pilhaEncadeada.c"

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

//---------------------------------<Funçôes Contigua>-------------------------------------------//
void basic_function_contigua_empilhar_imprimir(int value){
    printf(">>> TESTE EMPILHAR\n");
    PilhaContigua* p = pilha_contigua_criar();
    for(int i=0;i<value;i++){
        pilha_contigua_empilhar(p, i);
    }

    pilha_contigua_imprimir(p, printInteiro);
    printf("\n");
    pilha_contigua_destruir(&p);
}

void basic_function_contigua_empilhar_desempilhar_imprimir(int value){
    printf(">>> TESTE EMPILHAR\n");
    PilhaContigua* p = pilha_contigua_criar();
    for(int i=0;i<value;i++){
        pilha_contigua_empilhar(p, i);
    }
    printf(">>> TESTE DESEMPILHAR\n");
    int elemento;
    for(int i=0;i<value;i++){
        pilha_contigua_desempilhar(p, &elemento);
        printf("Removido: %d\n", elemento);
        int resultado = pilha_contigua_desempilhar(p, &elemento);
        if (!resultado){
            printf("Pilha vazia\n");
            break;
        }

    }
    pilha_contigua_destruir(&p);
}

//---------------------------------</Funçôes Contigua>-------------------------------------------//


//---------------------------------<Funçôes Encadeadas>-------------------------------------------//
void basic_function_encadeada_empilhar_imprimir(int value){
    printf(">>> TESTE EMPILHAR\n");
    PilhaEncadeada* p = pilha_encadeada_criar();
    for(int i=0;i<value;i++){
        pilha_encadeada_empilhar(p, i);
    }

    pilha_encadeada_imprimir(p);
    printf("\n");
    pilha_encadeada_destruir(p);
}
//---------------------------------</Funçôes Encadeadas>-------------------------------------------//
int main(){

    TICK(TIME_A);

    //-------------------------Teste Pilha de Alocação Contígua / Funções Básicas-------------------------------------//
    //basic_function_contigua_empilhar_imprimir(dado10);
    //basic_function_contigua_empilhar_imprimir(dado50);
    //basic_function_contigua_empilhar_imprimir(dado100);
    //basic_function_contigua_empilhar_imprimir(dado500);

    //basic_function_contigua_empilhar_desempilhar_imprimir((dado10));
    //basic_function_contigua_empilhar_desempilhar_imprimir((dado50));
    //basic_function_contigua_empilhar_desempilhar_imprimir((dado100));
    //basic_function_contigua_empilhar_desempilhar_imprimir((dado500));


    //basic_function_encadeada_empilhar_imprimir(dado10);
    //basic_function_encadeada_empilhar_imprimir(dado50);
    //basic_function_encadeada_empilhar_imprimir(dado100);
    basic_function_encadeada_empilhar_imprimir(dado500);

    TOCK(TIME_A);

    //TICK(TIME_B);
    //functionB();
    //TOCK(TIME_B);


    return 0;
}




