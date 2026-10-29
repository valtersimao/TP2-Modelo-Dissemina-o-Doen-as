#ifndef EVENTO_H
#define EVENTO_H

#include "pessoa.h"
#include "pilha.h"

typedef struct {
    int dia;
    Pessoa pessoa;
    int estadoAnterior;
    int estadoAtual;
}Evento;

void EventoAdiciona(Pilha * pilha, int dia, Pessoa *pessoa, int estadoAnterior, int estadoAtual);
void EventoPrint(Evento e);

#endif