#include "fila.h"
#include <stdlib.h>

Fila *FilaInicia() {
    Fila *fila = malloc(sizeof(fila));

    if (fila == NULL)
        return NULL;


    fila->lista = ListaCria();

    if (fila->lista == NULL) {
        free(fila);
        return NULL;
    }

    return fila;
}

void FilaLibera(Fila *fila) {
    if (fila == NULL) {
        return;
    }

    ListaEsvazia(fila->lista);
    free(fila);
}

bool FilaEhVazia(Fila *fila) {
    if(fila == NULL) return true;
    return ListaEhVazia(fila->lista);
}
//o primeiro elemento inserido é o primeiro a sair
//estamos inserindo no início da lista, que representa o topo da pilha.
bool FilaInsere(Fila *fila, Pessoa *pessoa) {
    if(fila == NULL) return false;
    return ListaInsereFim(fila->lista, pessoa);
}
Pessoa * FilaRemove(Fila *fila) {
    if(fila == NULL) return false;

    return ListaRemoveInicio(fila->lista);
}