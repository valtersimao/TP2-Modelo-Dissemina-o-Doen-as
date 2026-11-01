#include <stdio.h>
#include <stdlib.h>
#include "evento.h"

Evento *EventoAdiciona(int dia, Pessoa *pessoa, int estadoAnterior, int estadoAtual){
    Evento *evento = (Evento*) malloc(sizeof(Evento));
    if(!evento) return NULL;

    evento->dia = dia;
    evento->pessoa = *pessoa;
    evento->estadoAnterior = estadoAnterior;
    evento->estadoAtual = estadoAtual;

    EventoPrint(evento);
    return evento;
}

void EventoPrint(Evento *e) {
    printf("{");
    printf("Dia: %d | [", e->dia);
    PessoaPrint(&e->pessoa);
    printf("] | Estado %d -> Estado %d}\n", e->estadoAnterior, e->estadoAtual);
}

void EventoDestroi(Evento *e){
    if(e != NULL){
        free(e);
    }
}