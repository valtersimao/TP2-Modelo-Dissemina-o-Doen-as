#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//função que é necessária pra usar o tipo 'uint32_t'
#include <stdint.h>

#include "pessoa.h"
#include "parametros.h"
#include "simulacao.h"

static uint32_t xorshift32(void) {
    static uint32_t state = 12345;
    uint32_t x = state;
   
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
   
    state = x;
    return x;
}

// Sorteia um evento que ocorre com probabilidade de "prob" por cento.
// Retorna 1 (sucesso) ou 0 (fracasso).
static int sorteia(int prob) {
    int valor_sorteado = (int)(xorshift32() % 100u);
    return valor_sorteado < prob;
}

//Utilize o código abaixo para verificar se a função fornecida de fato funcionará conforme esperado.

int main(){

    

    // for(int i = 0; i < 20; i++){
    //     int valor_sorteado = (int)(xorshift32() % 100u);
    //     printf("%d", valor_sorteado);
    //     if(i < 20-1)
    //         printf(",");
    // }
    // printf("\n");

    return 0;
}