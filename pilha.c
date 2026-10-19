#include "pilha.h"
#include <stdlib.h>

typedef struct {
    Lista * lista; //Utilizar tudo já implementado na lista
} Pilha;

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

bool PilhaInsere(Pilha *pilha, Pessoa *pessoa) { 
    if(pilha == NULL) return false;

    return ListaInsereInicio(pilha->lista, pessoa);
}

bool PilhaRemove(Pilha *pilha, Pessoa *pessoa);