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

    //alocar resultado simulacao
    float * resultadoSimulacao = malloc(5 * sizeof(float));
    for (int i = 0; i < 5; i++) resultadoSimulacao[i] = 0;
    

    for (int sim = 0; sim < parametros.I; sim++) {
        printf("\nSimulação %d:\n", sim+1);
        float * temp = simular(parametros, ListaDuplica(pessoasInicio)); //manda uma lista duplicada para não afetar a lista original
        for (int i = 0; i < 5; i++) resultadoSimulacao[i] += temp[i];
        free(temp);
        
    }
    
    for (int i = 0; i < 5; i++) resultadoSimulacao[i] /= parametros.I;   
    //calcular % de cada estado
    printf("\n=============================\n   Porcentagens Finais \n=============================\n");
    printf(" - Pessoas Saudáveis: %.2f%%\n", resultadoSimulacao[0]);
    printf(" - Pessoas Infectadas: %.2f%%\n",resultadoSimulacao[1]);
    printf(" - Pessoas Doentes: %.2f%%\n", resultadoSimulacao[2]);
    printf(" - Pessoas Mortas: %.2f%%\n", resultadoSimulacao[3]);
    printf(" - Pessoas Vacinadas: %.2f%%\n", resultadoSimulacao[4]);
    printf("=============================\n");

    free(resultadoSimulacao);
    free(pessoasInicio);

    return 0;
}