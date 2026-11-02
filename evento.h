#ifndef EVENTO_H
#define EVENTO_H

#include "pessoa.h"

typedef struct {
    int dia;
    Pessoa *pessoa;
    int estadoAnterior;
    int estadoAtual;
}Evento;

Evento *EventoCria(int dia, Pessoa *pessoa, int estadoAnterior, int estadoAtual);
Evento *EventoDestroi(Evento *e);
void EventoPrint(Evento *e);


#endif