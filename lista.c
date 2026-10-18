#include "lista.h"
#include <stdlib.h>

typedef struct celula {
    struct celula *proximo;
    Pessoa *pessoa;
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
    Celula *auxiliar = pLista->cabeca->proximo;
    //liberando endereço por endereço
    while(auxiliar){
        //proximo da cabeça anda pra frente e atualiza
        pLista->cabeca->proximo = auxiliar->proximo;
        free(auxiliar);
        //proximo da cabeça anda
        auxiliar = pLista->cabeca->proximo;
    }
    //reiniciar a lista agora
    pLista->ultima = pLista->cabeca;
    return true;
}

Lista *ListaDestroi(Lista *pLista){
    if(!pLista) return NULL;

    Celula *liberaPessoas = pLista->cabeca->proximo;
    //liberando pessoa por pessoa
    while(liberaPessoas){
        PessoaDestroi(liberaPessoas->pessoa);
        liberaPessoas = liberaPessoas->proximo;
    }

    ListaEsvazia(pLista);

    free(pLista->cabeca);
    free(pLista);

    return NULL;
}

bool ListEhVazia(Lista *pLista){
    if(pLista){
        if(pLista->cabeca == pLista->ultima)
            return true;
        else
            return false;
    }
    return false;
}

bool ListaInsereInicio(Lista *pLista, Pessoa *pPessoa){
    if(!pLista) return false;

    Celula *nova = (Celula*) malloc(sizeof(Celula));
    if(!nova) return false;

    nova->pessoa = pPessoa;

    if(pLista->cabeca->proximo == NULL)
        pLista->ultima = nova;

    Celula *auxiliar = pLista->cabeca;
    nova->proximo = auxiliar->proximo;
    auxiliar->proximo = nova;
    
    pLista->tamanhoDaLista++;
    return true;
}

/*
FILA - O index vai ser sempre 0 pra REMOÇÃO FIFO
PILHA - O index vai ser sempre o tamanho da lista
[int tamanhoDaLista] pra REMOÇÃO LIFO
*/

Pessoa *ListaRetiraMeio(Lista *pLista, int pessoa_id){
    if(!pLista) return NULL;

    //vou buscar a que eu quero remover
    Celula *atual = pLista->cabeca->proximo;
    
    while(atual != NULL && atual->pessoa->id != id){
        atual = atual->proximo
    }
    //vou remover o auxiliar
    //(atual->proximo)->proximo
    //(a atual a que eu quero)->(a que eu quero)
    Celula *auxiliar = atual->proximo;//agora atual é a que tá meu valor buscado
    atual->proximo = auxiliar->proximo;
    //anteriror aponta pra onde auxilair ta apontando
    *pessoaPassa = atual->pessoa;//salvo a pessoa que vou remover
    free(auxiliar);
    
    if(index == pLista->tamanhoDaLista-1)
        pLista->ultima = atual;
    
    pLista->tamanhoDaLista--;
    return true;
}

//bool retorna bool
bool ListaRemoveInicio(Lista *pLista, Pessoa *pessoa){
    return ListaRetiraMeio(pLista, 0, pessoa);
}

bool ListaRemoveFim(Lista *pLista, Pessoa *pessoa){
    return ListaRetiraMeio(pLista, pessoa->id);
}