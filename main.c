//PERGUNTAR O QUE É O I
//CONFIRMAR ENTRADA DE DADOS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pessoa.h"
#include "parametros.h"
#include "simulacao.h"
#include "ordenacao.h"
#include "fila.h"
#include "pilha.h"
#include "lista.h"

Lista * lerListaPessoas(int nPessoas) {
    Lista * listaLida = ListaCria();
    if(listaLida == NULL) return NULL;

    for (int i = 0; i < nPessoas; i++) {
        char nome[100];
        int id, idade;
    
        scanf("%s %d %d", nome, &id, &idade);

        Pessoa *p = PessoaCria(id, idade, nome);

        if (p == NULL) printf("Erro ao criar pessoa %d", id);

        InsereOrdenado(listaLida, p);
    }
    
    return listaLida;
}

int main( ) {
    //Ler pessoas
    int N,P,L,K,F,M,D,R,Y,I;
    scanf("%d %d %d %d %d %d %d %d %d %d", &N, &P, &L, &K, &F, &M, &D, &R, &Y, &I);
    Parametros parametros = {N,P,L,K,F,M,D,R,Y,I};

    Lista * pessoasInicio = lerListaPessoas(parametros.N);

    simular(parametros, pessoasInicio);

    return 0;
}