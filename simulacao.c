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

        //VACINAÇÃO
        if(dia > parametros.R) {
            int vacinasHoje = parametros.N / parametros.Y;
            for (int i = 0; i < vacinasHoje; i++) {
                if(ListaEhVazia(ListaPessoasEstado[0])) break;
                Pessoa *p = ListaRemoveInicio(ListaPessoasEstado[0]);
                InsereOrdenado(ListaPessoasEstado[4], p);
                EventoAdiciona(historicoEventos, dia, p, 1, 5);
            }
            
        }

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
        //Passando de trás para frente para as pessoas removidas não alterarem os indices da lista
            Pessoa *p = ListaRetiraMeioIndice(ListaPessoasEstado[1], i);
            if (sorteia(parametros.F) == 1) {
                FilaInsere(FilaNovosDoentes, p);
                EventoAdiciona(historicoEventos, dia, p, 2, 3);
            } else {
                InsereOrdenado(ListaPessoasEstado[0], p);
                EventoAdiciona(historicoEventos, dia, p, 2, 1);
            }
        }
        
        //Após um dia de desenvolvimento da doença, há uma probabilidade de M% de que um indivíduo do estado 3 venha a óbito
        // (isto é, passe para o estado 4) ou de (100 − M)% que ele se cure (isto é, retorne para o estado 1).
        for (int i = ListaPessoasEstado[2]->tamanhoDaLista - 1; i >= 0; i--) {
            //Passando de trás para frente para as pessoas removidas não alterarem os indices da lista
            Pessoa *p = ListaRetiraMeioIndice(ListaPessoasEstado[2], i);
            if (sorteia(parametros.M) == 1) {
                InsereOrdenado(ListaPessoasEstado[3], p);
                EventoAdiciona(historicoEventos, dia, p, 3, 4);
            } else {
                InsereOrdenado(ListaPessoasEstado[0], p);
                EventoAdiciona(historicoEventos, dia, p, 3, 1);
            }
        }

        //Fim do dia
        //Insersção de novos infectados na Lista do Estado 2 (Infectados)
        while(!FilaEhVazia(FilaNovosInfectados)) {
            InsereOrdenado(ListaPessoasEstado[1], FilaRemove(FilaNovosInfectados));
        }
        //Insersção de novos doentes na Lista do Estado 3
        while(!FilaEhVazia(FilaNovosDoentes)) {
            InsereOrdenado(ListaPessoasEstado[2], FilaRemove(FilaNovosDoentes));
        }
        
    }
    
    //calcular % de cada estado
    printf("\n=============================\n   Porcentagens Finais\n=============================\n");
    printf(" - Pessoas Saudáveis: %.2f%%\n", ((float)ListaPessoasEstado[0]->tamanhoDaLista / parametros.N * 100.0));
    printf(" - Pessoas Infectadas: %.2f%%\n", ((float)ListaPessoasEstado[1]->tamanhoDaLista / parametros.N * 100.0));
    printf(" - Pessoas Doentes: %.2f%%\n", ((float)ListaPessoasEstado[2]->tamanhoDaLista / parametros.N * 100.0));
    printf(" - Pessoas Mortas: %.2f%%\n", ((float)ListaPessoasEstado[3]->tamanhoDaLista / parametros.N * 100.0));
    printf(" - Pessoas Vacinadas: %.2f%%\n", ((float)ListaPessoasEstado[4]->tamanhoDaLista / parametros.N * 100.0));
    printf("=============================\n");
    
    
    FilaLibera(FilaNovosInfectados);
    FilaLibera(FilaNovosDoentes);
    PilhaLibera(historicoEventos);
    for (int i = 0; i < 5; i++) ListaDestroi(ListaPessoasEstado[i]);
}