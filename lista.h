#ifndef LISTA_H
#define LISTA_H

//cada uma das simulações deve guardar uma pessoa
#include "pessoa.h"
#include <stdbool.h>

typedef struct celula {
    struct celula *proximo;
    Pessoa *pessoa;
} Celula;

typedef struct lista {
    int tamanhoDaLista;
    Celula *cabeca, *ultima;
} Lista;

Lista *ListaCria();
Lista *ListaDestroi(Lista *pLista);
bool ListaEsvazia(Lista *pLista);
bool ListaEhVazia(Lista *pLista);
bool ListaInsereFim(Lista *pLista, Pessoa *pPessoa);
bool ListaInsereInicio(Lista *pLista, Pessoa *pPessoa);

Pessoa *ListaRetiraMeio(Lista *pLista, int pessoa_id);
Pessoa *ListaRemoveInicio(Lista *pLista);
Pessoa *ListaRemoveFim(Lista *pLista);

#endif