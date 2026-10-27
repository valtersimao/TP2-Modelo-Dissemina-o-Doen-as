#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//função que é necessária pra usar o tipo 'uint32_t'
#include <stdint.h>


#include "pessoa.h"
#include "parametros.h"
#include "simulacao.h"
#include "ordenacao.h"
#include "fila.h"
#include "pilha.h"
#include "lista.h"

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

void limpar_buffer(void) {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main( ) {
    //Ler pessoas
    int nPessoas = 100;
    Lista * pessoasEstado1 = ListaCria();
    if(pessoasEstado1 == NULL) printf("Erro ao criar Lista de pessoas no estado 1");

    for (int i = 0; i < nPessoas; i++) {
        char nome[100];
        int id, idade;
    
        scanf("%s %d %d", nome, &id, &idade);
        limpar_buffer();

        Pessoa *p = PessoaCria(id, idade, nome);

        if (p == NULL) printf("Erro ao criar pessoa %d", id);

        InsereOrdenado(pessoasEstado1, p);
    }
    printf("inserido!\n");
    
    for (int i = 0; i < pessoasEstado1->tamanhoDaLista; i++)
    {
        PessoaPrint(ListaRemoveInicio(pessoasEstado1));
    }
    

    return 0;
}