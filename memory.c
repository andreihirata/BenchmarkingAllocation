#include <stdio.h>
#include <stdlib.h>

// Variável global que acumula quanta memória foi gasta em Bytes
size_t CURRENT_ALLOCATED_MEMORY = 0;

// Função própria "malloc"
//
// Basicamente chama a função malloc depois de somar o tamanho de
// memória requisitado

/*
calcular a memória alocada.
 É um exemplo bem simples que não leva free() em consideração.
 O problema de fazer um rework em cima do malloc/free inteiro é
 que precisamos armazenar quanta memória foi alocada por endereço. Por exemplo:

char *str;
str = (char *) myMalloc(10 * sizeof(char));
myFree(str);

Na chamada myFree() temos o apontador da área de memória que temos que
 liberar mas não sabemos quanta memória está alocada nesse área.
 Pior do que isso, como é um apontador do tipo void*, não podemos
 calcular quanta memória está alocada nessa área.

Então seria necessário manter uma lista de apontadores
 e quantidades de memórias que foram alocadas em uma HashTable
 (talvez) para poder fazer o gerenciamento.


void *myMalloc(size_t size) {
    void *ptr;

    if ( size > 0 )
        CURRENT_ALLOCATED_MEMORY += size;

    return malloc(size);
}

int main(int argc, char **argv) {
    char *str;

    // Alocação de memória com myMalloc, a chamada é igual a do malloc
    str = myMalloc(10 * sizeof(char));

    // Para verificar quanta memória foi gasta
    fprintf(stdout, "Current memory: %ld\n", CURRENT_ALLOCATED_MEMORY);

    return 1;
}
 */