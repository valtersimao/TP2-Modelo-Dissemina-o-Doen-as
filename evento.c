#include <stdio.h>
#include "evento.h"

Evento EventoCria(int dia, Pessoa *pessoa, int estadoAnterior, int estadoAtual) {
    Evento evento = {dia, *pessoa, estadoAnterior, estadoAtual};
    return evento;
}

void EventoPrint(Evento e) {
    printf("[");
    printf("DIA: %d | (");
    PessoaPrint(&e.pessoa);
    printf(") | Estado %d -> Estado %d]\n", e.estadoAnterior, e.estadoAtual);
}