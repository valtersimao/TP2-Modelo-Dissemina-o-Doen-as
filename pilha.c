#include "pilha.h"
#include <stdlib.h>

struct {
    Celula *cabeca;
} Pilha;

Pilha *PilhaInicia(){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    if(!pilha) return NULL;
    pilha->cabeca = (Celula*) malloc(sizeof(Celula));
    if(!pilha->cabeca){
        free(pilha);
        pilha = NULL;
        return pilha;
    }
    pilha->cabeca->proximo = NULL;
    return pilha;
}

Pilha *PilhaLibera(Pilha *pilha){
    if(!pilha) return NULL;
    ListaLibera(pilha);
    free(pilha->cabeca);
    free(pilha);
    return NULL;
}

bool PilhaPush(Pilha *pilha, Pessoa *pessoa){

}