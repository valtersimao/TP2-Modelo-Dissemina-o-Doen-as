#include <stdio.h>
#include <stdlib.h>
#include "evento.h"

Evento * EventoCria(int dia, Pessoa *pessoa, int estadoAnterior, int estadoAtual) {
    Evento * evento = malloc(sizeof(Evento));
    evento->dia = dia;
    evento->pessoa = pessoa;
    evento->estadoAnterior = estadoAnterior;
    evento->estadoAtual = estadoAtual;
    //EventoPrint(evento);
    return evento;
}

Evento * EventoDestroi(Evento *e) {
    free(e);
    return NULL;
}

void EventoPrint(Evento *e) {
    printf("{");
    printf("Dia: %d | [", e->dia);
    PessoaPrint(e->pessoa);
    printf("] | Estado %d -> Estado %d}\n", e->estadoAnterior, e->estadoAtual);
}