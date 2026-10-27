#ifndef EVENTO_H
#define EVENTO_H

#include "pessoa.h"

typedef struct evento
{
    int dia;
    Pessoa pessoa;
    int estadoAnterior;
    int estadoAtual;
}Evento;

Evento EventoCria(int dia, Pessoa *pessoa, int estadoAnterior, int estadoAtual);
void EventoPrint(Evento e);

#endif