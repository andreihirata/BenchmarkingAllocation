//https://www.techiedelight.com/find-execution-time-c-program/
//https://github.com/dlfcn-win32/dlfcn-win32
//https://pt.slideshare.net/lorivalschapuis/algoritmos-de-ordenao-8366612
//http://www2.dcc.ufmg.br/livros/algoritmos-edicao2/cap3/transp/completo4/cap3.pdf
//https://www.gnu.org/software/time/

#include <stdio.h>
#include <time.h>

#include "pilha/contigua/pilhaContigua.h"
#include "pilha/contigua/pilhaContigua.c"

#include "pilha/encadeada/pilhaEncadeada.h"
#include "pilha/encadeada/pilhaEncadeada.c"

//Tempo
#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

//Constantes

const int dado100mil = 100000;
const int dado500mil = 500000;
const int dado1Milhao = 1000000;
const int dado5Milhao = 5000000;


void printInteiro(void* n){
    int* p = n;
    printf("%d", *p);
}

//---------------------------------<Funçôes Contigua>-------------------------------------------//
void function_contigua_empilhar(int value){
    TICK(TIME_A);
    printf(">>> TESTE EMPILHAR CONTIGUA\n");
    PilhaContigua* p = pilha_contigua_criar();
    for(int i=0;i<value;i++){
        pilha_contigua_empilhar(p, i);
    }
    pilha_contigua_destruir(&p);
    TOCK(TIME_A);
}

void function_contigua_desempilhar(int value){
    printf(">>> TESTE EMPILHAR CONTIGUA\n");
    PilhaContigua* p = pilha_contigua_criar();
    for(int i=0;i<value;i++){
        pilha_contigua_empilhar(p, i);
    }
    TICK(TIME_A);
    printf(">>> TESTE DESEMPILHAR CONTIGUA\n");

    int elemento;
    for(int i=0;i<value;i++){
        pilha_contigua_desempilhar(p, &elemento);
        int resultado = pilha_contigua_desempilhar(p, &elemento);
        if (!resultado){
            break;
        }
    }
    pilha_contigua_destruir(&p);
    TOCK(TIME_A);
}



void combination_function_contigua_empilhar_imprimir(int value){
    TICK(TIME_A);
    printf(">>> TESTE EMPILHAR CONTIGUA\n");

    PilhaContigua* p = pilha_contigua_criar();
    for(int i=0;i<value;i++){
        pilha_contigua_empilhar(p, i);
    }

    pilha_contigua_imprimir(p, printInteiro);
    printf("\n");
    pilha_contigua_destruir(&p);
    TOCK(TIME_A);
}

void combination_function_contigua_empilhar_desempilhar_imprimir(int value){
    TICK(TIME_A);
    printf(">>> TESTE EMPILHAR CONTIGUA\n");
    PilhaContigua* p = pilha_contigua_criar();
    for(int i=0;i<value;i++){
        pilha_contigua_empilhar(p, i);
    }
    printf(">>> TESTE DESEMPILHAR CONTIGUA\n");
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
    TOCK(TIME_A);
}

//---------------------------------</Funçôes Contigua>-------------------------------------------//


//---------------------------------<Funçôes Encadeadas>-------------------------------------------//
void function_encadeada_empilhar(int value){
    TICK(TIME_A);
    printf(">>> TESTE EMPILHAR ENCADEADA\n");
    PilhaEncadeada* p = pilha_encadeada_criar();
    for(int i=0;i<value;i++){
        pilha_encadeada_empilhar(p, i);
    }
    pilha_encadeada_destruir(p);
    TOCK(TIME_A);
}

void function_encadeada_desempilhar(int value){
    TICK(TIME_A);
    printf(">>> TESTE EMPILHAR ENCADEADA\n");
    PilhaEncadeada* p = pilha_encadeada_criar();
    for(int i=0;i<value;i++){
        pilha_encadeada_empilhar(p, i);
    }
    printf(">>> TESTE DESEMPILHAR ENCADEADA\n");
    int elemento;
    for(int i=0;i<value;i++){
        pilha_encadeada_desempilhar(p, &elemento);
        int resultado = pilha_encadeada_desempilhar(p, &elemento);
        if (!resultado){
            break;
        }

    }
    pilha_encadeada_destruir(p);
    TOCK(TIME_A);
}

void combination_function_encadeada_empilhar_imprimir(int value){
    TICK(TIME_A);
    printf(">>> TESTE EMPILHAR ENCADEADA\n");
    PilhaEncadeada* p = pilha_encadeada_criar();
    for(int i=0;i<value;i++){
        pilha_encadeada_empilhar(p, i);
    }

    pilha_encadeada_imprimir(p);
    printf("\n");
    pilha_encadeada_destruir(p);
    TOCK(TIME_A);
}

void combination_function_encadeada_empilhar_desempilhar_imprimir(int value){
    TICK(TIME_A);
    printf(">>> TESTE EMPILHAR ENCADEADA\n");
    PilhaEncadeada* p = pilha_encadeada_criar();
    for(int i=0;i<value;i++){
        pilha_encadeada_empilhar(p, i);
    }
    printf(">>> TESTE DESEMPILHAR ENCADEADA\n");
    int elemento;
    for(int i=0;i<value;i++){
        pilha_encadeada_desempilhar(p, &elemento);
        printf("Removido: %d\n", elemento);
        int resultado = pilha_encadeada_desempilhar(p, &elemento);
        if (!resultado){
            printf("Pilha vazia\n");
            break;
        }

    }
    pilha_encadeada_destruir(p);
    TOCK(TIME_A);
}
//---------------------------------</Funçôes Encadeadas>-------------------------------------------//

//Menu


int main(){

    //-------------------------Teste Pilha de Alocação Contígua-------------------------------------//
    //function_contigua_empilhar(dado100mil);
    //function_contigua_empilhar(dado500mil);
    //function_contigua_empilhar(dado1Milhao);
    //function_contigua_empilhar(dado5Milhao);
    //function_contigua_desempilhar(dado100mil);
    //function_contigua_desempilhar(dado500mil);
    //function_contigua_desempilhar(dado1Milhao);
    //function_contigua_desempilhar(dado5Milhao);


    //combination_function_contigua_empilhar_imprimir(dado100mil);
    //combination_function_contigua_empilhar_imprimir(dado500mil);
    //combination_function_contigua_empilhar_imprimir(dado1Milhao);
    //combination_function_contigua_empilhar_imprimir(dado5Milhao);

    //combination_function_contigua_empilhar_desempilhar_imprimir((dado100mil));
    //combination_function_contigua_empilhar_desempilhar_imprimir((dado500mil));
    //combination_function_contigua_empilhar_desempilhar_imprimir((dado1Milhao));
    //combination_function_contigua_empilhar_desempilhar_imprimir((dado5Milhao));


    //-------------------------Teste Pilha de Alocação Encadeada------------------------------------//
    //function_encadeada_empilhar(dado100mil);
    //function_encadeada_empilhar(dado500mil);
    //function_encadeada_empilhar(dado1Milhao);
    //function_encadeada_empilhar(dado5Milhao);

    //function_encadeada_desempilhar(dado100mil);
    //function_encadeada_desempilhar(dado500mil);
    //function_encadeada_desempilhar(dado1Milhao);
    //function_encadeada_desempilhar(dado5Milhao);


    //combination_function_encadeada_empilhar_imprimir(dado100mil);
    //combination_function_encadeada_empilhar_imprimir(dado500mil);
    //combination_function_encadeada_empilhar_imprimir(dado1Milhao);
    //combination_function_encadeada_empilhar_imprimir(dado5Milhao);

    //Problema aqui
    //combination_function_encadeada_empilhar_desempilhar_imprimir((dado100mil));
    //combination_function_encadeada_empilhar_desempilhar_imprimir((dado500mil));
    //combination_function_encadeada_empilhar_desempilhar_imprimir((dado1Milhao));
    //combination_function_encadeada_empilhar_desempilhar_imprimir((dado5Milhao));


    return 0;
}




