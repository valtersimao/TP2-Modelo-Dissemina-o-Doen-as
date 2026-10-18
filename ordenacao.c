#include "ordenacao.h"

#include <stdlib.h>

bool VerificaPriori(Pessoa *pessoa1, Pessoa *pessoa2){
    if(!pessoa1 || !pessoa2) return false;

    if(pessoa1->idade > pessoa2->idade){
        return true;//pessoa1 tem idade mais avançada
    } else if(pessoa1->idade == pessoa2->idade){
        if(pessoa1->id < pessoa2->id){
            return true;//p1 tem o id menor
        }
    }
    //se pessoa1 não se encaixou em nenhum requisito
    return false;//não ocorre a troca
}

//já vem da lista direto pra ca
//Dividir pra Conquistar 
void AlgoritmoOrdenacaoMerge(Lista *pLista){
    if(!pLista || pLista->tamanhaDaLista < 2) return;
    //se a lista tiver só 1 elemento, ela já tá ordenada

    //Guarda o 1º elemento válido
    Celula *primeiraPessoa = pLista->cabeca->proximo;
    Celula *ordenaNovaCabeca = RecursaoMegre(primeiraPessoa);

    //atualizar o ponteiro que aponta pro ultimo
    pLista->cabeca->proximo = ordenaNovaCabeca;//reconecta a lista na cauda depois de ordenada
    Celula *atual = ordenaNovaCabeca;
    while(atual != NULL && atual->proximo != NULL){
        atual = atual->proximo;
    }
    //atualizaçao
    pLista->ultimo atual;
}