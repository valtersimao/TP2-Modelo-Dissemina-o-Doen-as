#include "simulacao.h"
#include "ordenacao.h"

#include <stdio.h>
//bilbioteca que é necessária pra usar o tipo 'uint32_t'
#include <stdint.h>
static uint32_t xorshift32(void) {
    static uint32_t state = 12345;
    uint32_t x = state;
   
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
   
    state = x;
    return x;
}

// Sorteia um evento que ocorre com probabilidade de "prob" por cento.
// Retorna 1 (sucesso) ou 0 (fracasso).
static int sorteia(int prob) {
    int valor_sorteado = (int)(xorshift32() % 100u);
    return valor_sorteado < prob;
}

void simular( Parametros parametros, Lista * listaPessoasInicio) {
    Pilha * historicoEventos = PilhaInicia();
    Fila * FilaNovosInfectados = FilaInicia();
    Fila * FilaNovosDoentes = FilaInicia();
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
    
    //Infecção inicial dia 0
    printf("\n==========\n   DIA %d\n==========\n", 0);
    int nInfectadosDia0 = (parametros.N * parametros.P) / 100;
    for (int i = 0; i < nInfectadosDia0; i++) {
        Pessoa *p = ListaRemoveInicio(ListaPessoasEstado[0]);
        InsereOrdenado(ListaPessoasEstado[1], p);
        EventoAdiciona(historicoEventos, 0, p, 1, 2);
        
    }

    //Simulação de cada dia
    for (int dia = 1; dia < parametros.D; dia++) {
        printf("\n==========\n   DIA %d\n==========\n\n", dia);

        //probabilidade de L% que uma pessoa do estado 2 infecte uma pessoa do estado 1
        //transformando-a em uma pessoa do estado 2.
        for (int i = 0; i < ListaPessoasEstado[1]->tamanhoDaLista; i++)  {
            if(sorteia(parametros.L) == 1) {
                if(!ListaEhVazia(ListaPessoasEstado[0])) {
                    Pessoa *p = ListaRemoveInicio(ListaPessoasEstado[0]);
                    FilaInsere(FilaNovosInfectados, p);
                    EventoAdiciona(historicoEventos, dia, p, 1, 2);
                }
            }
        }

        //Há uma probabilidade de K% de que uma pessoa do estado 3 infecte uma pessoa do estado 1
        //transformando-a em uma pessoa do estado 2. Neste cenário, K > L, pois as pessoas que desenvolveram a doença têm uma carga viral muito maior.
        for (int i = 0; i < ListaPessoasEstado[2]->tamanhoDaLista; i++)  {
            if(sorteia(parametros.L) == 1) {
                if(!ListaEhVazia(ListaPessoasEstado[0])) {
                    Pessoa *p = ListaRemoveInicio(ListaPessoasEstado[0]);
                    FilaInsere(FilaNovosInfectados, p);
                    EventoAdiciona(historicoEventos, dia, p, 1, 2);
                }
            }
        }
        
        //Após um dia da infecção, há uma probabilidade de F% que uma pessoa do estado 2 avance para o estado 3 
        //(isto é, desenvolva a Doença-X). Há também uma probabilidade complementar de (100 − F )% 
        //que uma pessoa do estado 2 não desenvolva a doença e novamente se torne uma pessoa do estado 1.
        for (int i = ListaPessoasEstado[1]->tamanhoDaLista - 1; i >= 0; i--) {
        //Passando de trás para frente para as pessoas removidas não alteram os indices da lista
            if (sorteia(parametros.F) == 1) {
                Pessoa *p = ListaRetiraMeioIndice(ListaPessoasEstado[1], i);
                FilaInsere(FilaNovosDoentes, p);
                EventoAdiciona(historicoEventos, dia, p, 2, 3);
            } else if (sorteia(100 - parametros.F) == 1) {
                Pessoa *p = ListaRetiraMeioIndice(ListaPessoasEstado[1], i);
                //FilaInsere(FilaNovosDoentes, p);
                InsereOrdenado(ListaPessoasEstado[0], p);
                EventoAdiciona(historicoEventos, dia, p, 2, 1);
            }
        }
        
        //TO DO (PAREI AQUI)
        
        //Fim do dia
        //Insersção de novos infectados na Lista do Estado 2 (Infectados)
        while(!FilaEhVazia(FilaNovosInfectados)) {
            InsereOrdenado(ListaPessoasEstado[1], FilaRemove(FilaNovosInfectados));
        }
        //Insersção de novos doentes na Lista do Estado 3
        while(!FilaEhVazia(FilaNovosDoentes)) {
            InsereOrdenado(ListaPessoasEstado[2], FilaRemove(FilaNovosInfectados));
        }
        
    }
    
    
    FilaLibera(FilaNovosInfectados);
    FilaLibera(FilaNovosDoentes);
    PilhaLibera(historicoEventos);
    for (int i = 0; i < 5; i++) ListaDestroi(ListaPessoasEstado[i]);
}