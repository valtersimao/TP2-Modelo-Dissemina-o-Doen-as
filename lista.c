#include "lista.h"
#include <stdlib.h>

typedef struct celula {
    struct celula *proximo;
    Item item;
} Celula;

struct lista {
    int tamanhoDaLista;
    Celula *cabeca, *ultima;
};

Lista *ListaCria(){
    Lista *pLista = (Lista*) malloc(sizeof(Lista));
    if(!pLista) return NULL;
    //Criar a cabeça
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if(pLista->cabeca){
        free(pLista);
        return NULL;
    }
    pLista->cabeca->proximo = NULL;
    pLista->ultima = pLista->cabeca;
    pLista->tamanhoDaLista = 0;

    return pLista;
}

bool ListaEsvazia(Lista *pLista){
    if(!pLista) return false;
    Celula *auxilair = pLista->cabeca->proximo;
    //liberando endereço by endereço
    while(auxiliar){
        //proximo da cabeça anda pra frente e atualiza
        pLista->cabeca->proximo = auxiliar->proximo;
        free(auxiliar);
        //proximo da cabeça anda pra frente
        auxiliar = pLista->cabeca->proximo;
    }
    //reiniciar a lista agora
    pLista->ultima = pLista->cabeca;
    return true;
}

Lista *ListaDestroi(Lista *pListas){
    if(!pLista) return NULL;
    ListaEsvazia(pLista);
    free(pLista->cabeca);
    free(pLista);
    return NULL;
}

bool ListEhVazia(Lista *pLista){
    if(pLista){
        if(pLista->cabeca == pLista->ultimo)
            return true;
        else
            return false;
    }
    return false;
}

bool ListaInsereMeio(Lista *pLista, int index, Item valor){
    if(!pLista) return false;
    if(index < pLista->cabeca || index > pLista->ultimo) return false;

    Celula *nova = (Celula*) malloc(sizeof(Celula));
    if(!nova) return false;

    nova->item = valor;
    Celula *auxiliar = pLista->cabeca;
    //anda na lista
    for(int i = 0; i < index; i++)
        auxiliar = auxiliar->proximo;
    
    nova->proximo = auxiliar->proximo;
    auxiliar->proximo = nova;

    if(index == pLista->tamanhoAtual)
        pLista->ultimo = nova;// nova é a "ultima celula"
    //de qualquer forma, executa
    pLista->tamanhoAtual++;
    return true;
}

bool ListaRetiraMeio(Lista *pLista, int index, Item *pX){
    if(!pLista || !pX) return false;
    if(index < 0 || index >= pLista->tamanhoAtual) return false;

    //vou buscar a que eu quero remover
    Celula *anterior = pLista->cabeca;
    
    for(int j = 0; j < index; j++)
        anterior = anterior->proximo;
    //o anterior aponta para a célula antes da que vai sair
    
    //vou remover o auxiliar
    //(anterior->proximo)->proximo
    //(a anterior a que eu quero)->(a que eu quero)
    Celula *auxiliar = anterior->proximo;//agora auxiliar é a que tá meu valor buscado
    anterior->proximo = auxiliar->proximo;
    //anteriror aponta pra onde auxilair ta apontando
    *pX = auxiliar->item;//salvo o item da que vou remover
    free(auxiliar);
    
    if(index == pLista->tamanhoAtual-1)
        pLista->ultimo = anterior;
    
    pLista->tamanhoAtual--;
    return true;
}

bool ListaInsereInicio(Lista *pLista, Pessoa *pessoa, Item item){
    ListaInsereMeio(pLista, 0, item);
}//true or false

bool ListaRetiraMeio(){
    
}