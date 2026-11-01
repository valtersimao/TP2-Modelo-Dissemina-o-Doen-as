#ifndef EVENTO_H
#define EVENTO_H

#include "pessoa.h"

typedef struct {
    int dia;
    Pessoa pessoa;
    int estadoAnterior;
    int estadoAtual;
}Evento;

Evento *EventoAdiciona(int dia, Pessoa *pessoa, int estadoAnterior, int estadoAtual);
void EventoPrint(Evento *e);
void EventoDestroi(Evento *e);

#endif