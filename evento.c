#include <stdio.h>
#include "evento.h"

void EventoAdiciona(Pilha * pilha, int dia, Pessoa *pessoa, int estadoAnterior, int estadoAtual) {
    Evento evento = {dia, *pessoa, estadoAnterior, estadoAtual};
    PilhaInsere(pilha, &evento);
    EventoPrint(evento);
}

void EventoPrint(Evento e) {
    printf("{");
    printf("Dia: %d | [", e.dia);
    PessoaPrint(&e.pessoa);
    printf("] | Estado %d -> Estado %d}\n", e.estadoAnterior, e.estadoAtual);
}