#ifndef PILHA_H
#define PILHA_H

#include "lista.h"
#include "pessoa.h"

typedef struct Pilha;

Pilha *PilhaInicia();
Pilha *PilhaLibera(Pilha *pilha);
bool PilhaEhVazia(Pilha *pilha);
bool PilhaInsere(Pilha *pilha, Pessoa *pessoa);//ultimo elemento que entrou
bool PilhaRemove(Pilha *pilha, Pessoa *pessoa);//ultimo que entrou saiu primeiro
//insere onde acabou de remover e remove onde acabou de inserir
#endif