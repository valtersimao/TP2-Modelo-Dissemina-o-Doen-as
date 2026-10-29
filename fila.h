#ifndef FILA_H
#define FILA_H

#include "lista.h"
#include "pessoa.h"

typedef struct {
    Lista * lista; //Utilizar tudo já implementado na lista
} Fila ;

Fila * FilaInicia();
void FilaLibera(Fila *fila);
bool FilaEhVazia(Fila *fila);
bool FilaInsere(Fila *fila, Pessoa *pessoa);
Pessoa * FilaRemove(Fila *fila);
//insere no fim e remove do inicio
#endif