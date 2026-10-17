#ifndef LISTA_H
#define LISTA_H

//cada uma das simulações deve guardar uma pessoa
#include "pessoa.h"

typedef struct lista Lista;

Lista *ListaCria();
Lista *ListaDestroi(Lista *pLista);
bool ListaEsvazia(Lista *pLista);
bool ListaEhVazia(Lista *pLista);
bool ListaInsereMeio(Lista *pLista, int index, Item valor);
bool ListaInsereMeio(Lista *pLista, Pessoa *pessoa, Item valor);

#endif