#include "pilha.h"

#include "lista.h"
#include <stdlib.h>

Pilha *PilhaInicia() {
    Pilha *pilha = malloc(sizeof(Pilha));

    if (pilha == NULL)
        return NULL;


    pilha->lista = ListaCria();

    if (pilha->lista == NULL) {
        free(pilha);
        return NULL;
    }

    return pilha;
}

void PilhaLibera(Pilha *pilha) {
    if (pilha == NULL) {
        return;
    }

    ListaEsvazia(pilha->lista);
    free(pilha);
}

bool PilhaEhVazia(Pilha *pilha) {
    if(pilha == NULL) return true;
    return ListaEhVazia(pilha->lista);
}

//o último elemento inserido é o primeiro a sair
//estamos inserindo no início da lista, que representa o topo da pilha.

bool PilhaInsere(Pilha *pilha, void *item) { 
    if(pilha == NULL) return false;

    return ListaInsereInicio(pilha->lista, item);
}

void * PilhaRemove(Pilha *pilha){
    if(pilha == NULL) return false;

    return ListaRemoveInicio(pilha->lista);
}