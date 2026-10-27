#ifndef PILHA_H
#define PILHA_H

#include "lista.h"
#include "evento.h"

typedef struct {
    Lista * lista; //Utilizar tudo já implementado na lista
}Pilha;

Pilha *PilhaInicia();
void PilhaLibera(Pilha *pilha);
bool PilhaEhVazia(Pilha *pilha);
bool PilhaInsere(Pilha *pilha, Evento *evento);//ultimo elemento que entrou
Evento * PilhaRemove(Pilha *pilha);//ultimo que entrou saiu primeiro
//insere onde acabou de remover e remove onde acabou de inserir
#endif