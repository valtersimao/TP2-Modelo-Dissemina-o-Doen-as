#ifndef LISTA_H
#define LISTA_H

//cada uma das simulações deve guardar uma pessoa
#include "pessoa.h"

typedef struct lista Lista;

Lista *ListaCria(Pessoa *pPessoa);
Lista *ListaDestroi(Lista *pLista);
bool ListaEsvazia(Lista *pLista);
bool ListaEhVazia(Lista *pLista);
bool ListaInsereInicio(Lista *pLista, Pessoa *pPessoa);

Pessoa *ListaRetiraMeio(Lista *pLista, int pessoa_id);
Pessoa *ListaRemoveInicio(Lista *pLista);
Pessoa *ListaRemoveFim(Lista *pLista);

#endif