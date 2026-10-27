#include "simulacao.h"
#include "ordenacao.h"

void simular( Parametros parametros, Lista * listaPessoasInicio) {
    Pilha * historicoEventos = PilhaInicia();
    //Vetor de 5 posições de ponteiros, onde cada posição indica uma lista de pessoas em estados diferentes
    /*(
    [0] - Estado 1: Pessoas saudáveis
    [1] - Estado 2: Pessoas infectadas que não desenvolveram a doença;
    [2] - Estado 3: Pessoas infectadas que desenvolveram a doença;
    [3] - Estado 4: Pessoas que faleceram;
    [4] - Estado 5: Pessoas imunizadas pela vacina.
    */
    Lista * ListaPessoasEstado[5];    
    ListaPessoasEstado[0] = listaPessoasInicio;
    for (int i = 1; i < 5; i++) { //inicializar cada Lista
        ListaPessoasEstado[i] = ListaCria();
    }
    

    int nInfectadosDia0 = (parametros.N * parametros.P) / 100;
    for (int i = 0; i < nInfectadosDia0; i++) {
        Pessoa *p = ListaRemoveInicio(ListaPessoasEstado[0]);
        InsereOrdenado(ListaPessoasEstado[1], p);
        Evento e = EventoCria(0, p, 1, 2);
        EventoPrint(e);
        //PilhaInsere(historicoEventos, &e);
    }
    


}