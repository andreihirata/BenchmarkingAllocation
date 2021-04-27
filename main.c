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
const int dado10 = 10000;
const int dado50 = 50000;
const int dado100 = 100000;
const int dado500 = 500000;

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
    //function_contigua_empilhar(dado10);
    //function_contigua_empilhar(dado50);
    //function_contigua_empilhar(dado100);
    //function_contigua_empilhar(dado500);

    //function_contigua_desempilhar(dado10);
    //function_contigua_desempilhar(dado50);
    //function_contigua_desempilhar(dado100);
    //function_contigua_desempilhar(dado500);


    //combination_function_contigua_empilhar_imprimir(dado10);
    //combination_function_contigua_empilhar_imprimir(dado50);
    //combination_function_contigua_empilhar_imprimir(dado100);
    //combination_function_contigua_empilhar_imprimir(dado500);

    //combination_function_contigua_empilhar_desempilhar_imprimir((dado10));
    //combination_function_contigua_empilhar_desempilhar_imprimir((dado50));
    //combination_function_contigua_empilhar_desempilhar_imprimir((dado100));
    //combination_function_contigua_empilhar_desempilhar_imprimir((dado500));


    //-------------------------Teste Pilha de Alocação Encadeada------------------------------------//
    //function_encadeada_empilhar(dado10);
    //function_encadeada_empilhar(dado50);
    //function_encadeada_empilhar(dado100);
    //function_encadeada_empilhar(dado500);

    //Problema aqui
    //function_encadeada_desempilhar(dado10);
    //function_encadeada_desempilhar(dado50);
    //function_encadeada_desempilhar(dado100);
    //function_encadeada_desempilhar(dado500);


    //combination_function_encadeada_empilhar_imprimir(dado10);
    //combination_function_encadeada_empilhar_imprimir(dado50);
    //combination_function_encadeada_empilhar_imprimir(dado100);
    //combination_function_encadeada_empilhar_imprimir(dado500);

    //Problema aqui
    //combination_function_encadeada_empilhar_desempilhar_imprimir((dado10));
    //combination_function_encadeada_empilhar_desempilhar_imprimir((dado50));
    //combination_function_encadeada_empilhar_desempilhar_imprimir((dado100));
    combination_function_encadeada_empilhar_desempilhar_imprimir((dado500));


    return 0;
}




