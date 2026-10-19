#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdbool.h>
#include "lista.h"
#include "pessoa.h"

/*Função que faz o trabalho de ordenaçao
(se alguem se curar e voltar pro Estado 1).
*/
void InsereOrdenado(Lista *pLista, Pessoa *pPessoa);
/*
True se pessa1 ttem prioridade (vem antes na lsita).
- Mais velho deve estar na frente.
- Se empatou a idade, True para o de menor ID.
*/
bool VerificaPriori(Pessoa *pessoa1, Pessoa *pessoa2);
void AlgoritmoOrdenacaoMerge(Lista *pLista);

#endif