#ifndef FILA_H
#define FILA_H

#include "lista.h"
#include "pessoa.h"

typedef struct {
    /* data */
} Fila ;

Fila * FilaInicia();
Fila * FilaLibera(Fila *pilha);
bool FilaEhVazia(Fila *fila);
bool FilaInsere(Fila *fila, Pessoa *pessoa);//ultimo elemento que entrou
bool FilaRemove(Fila *fila, Pessoa *pessoa);//ultimo que entrou saiu primeiro
//insere onde acabou de remover e remove onde acabou de inseri
#endif