#include "lista.h"
#include <stdlib.h>

Lista *ListaCria(){
    Lista *pLista = (Lista*) malloc(sizeof(Lista));
    if(!pLista) return NULL;
    //Criar a cabeça
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if(!pLista->cabeca){
        free(pLista);
        return NULL;
    }

    pLista->cabeca->pessoa = NULL;

    pLista->cabeca->proximo = NULL;
    pLista->ultima = pLista->cabeca;
    pLista->tamanhoDaLista = 0;

    return pLista;
}

bool ListaEsvazia(Lista *pLista){
    if(!pLista) return false;
    Celula *auxiliar = pLista->cabeca->proximo;
    Celula *proxima = pLista->cabeca;
    //liberando endereço por endereço
    while(auxiliar){
        //proximo da cabeça anda pra frente e atualiza
        proxima = auxiliar->proximo;
        free(auxiliar);
        //proximo da cabeça anda
        auxiliar = proxima;
    }
    //reiniciar a lista toda agora
    pLista->cabeca->proximo = NULL;
    pLista->ultima = pLista->cabeca;
    pLista->tamanhoDaLista = 0;

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

bool ListaEhVazia(Lista *pLista){
    if(pLista){
        if(pLista->cabeca == pLista->ultima)
            return true;
        else
            return false;
    }
    return false;
}

bool ListaInsereFim(Lista *pLista, Pessoa *pPessoa){
    if(!pLista) return false;
    if(!pPessoa) return false;

    Celula *nova = (Celula*) malloc(sizeof(Celula));
    if(!nova) return false;

    nova->pessoa = pPessoa;

    if(pLista->cabeca->proximo == NULL)
        pLista->ultima = nova;

    Celula *auxiliar = pLista->ultima;
    nova->proximo = auxiliar->proximo;
    auxiliar->proximo = nova;//só no caso de ter um ponteiro pra ultima
    
    pLista->tamanhoDaLista++;
    return true;
}

bool ListaInsereInicio(Lista *pLista, Pessoa *pPessoa){
    if(!pLista) return false;
    if(!pPessoa)  return false;

    Celula *nova = malloc(sizeof(Celula));
    if(!nova) return false;
    
    nova->pessoa = pPessoa;

    //momento de troca (simples)
    nova->proximo = pLista->cabeca->proximo;
    pLista->cabeca->proximo = nova;

    if(nova->proximo == NULL)
        pLista->ultima = nova;
    
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

    Celula *anterior = pLista->cabeca;
    Celula *atual = pLista->cabeca->proximo;//a busca começa daqui

    //fazendo a busca da celula
    while(atual != NULL && atual->pessoa->id != pessoa_id){
        anterior = atual;
        atual = atual->proximo;
    }
    if(!atual) return NULL;

    //pra remover a célula encontrada da lista
    anterior->proximo = atual->proximo;
    if(atual == pLista->ultima){//se a que eu removi era a última
        //atualizo o ponteiro que ultima irá apontar
        pLista->ultima = anterior;
    }
    //guarda e passa a pessoa antes de liberar a Célula
    Pessoa *pessoaRemovida = atual->pessoa;
    free(atual);
    
    pLista->tamanhoDaLista--;
    
    return pessoaRemovida;//por isso que é do tipo 'Pessoa'
}

Pessoa *ListaRemoveInicio(Lista *pLista){
    if(!pLista) return NULL;
    //remover a primeira
    Celula *remover = pLista->cabeca->proximo;
    if(!remover) return NULL; // significa que a lista está vazia
    //aponta para o próximo após o primeiro
    pLista->cabeca->proximo = remover->proximo;

    if(remover == pLista->ultima)//se o 1º for igual ao último
        pLista->ultima = pLista->cabeca;
    
    Pessoa *pessoaRemovida = remover->pessoa;
    free(remover);

    pLista->tamanhoDaLista--;

    return pessoaRemovida;
}

Pessoa *ListaRemoveFim(Lista *pLista){
    if(!pLista) return NULL;
    Celula *anterior = pLista->cabeca;
    Celula *atual = pLista->cabeca->proximo;

    if(!atual) return NULL;//SIGNIFICA: Lista Vazia

    while(atual->proximo != NULL){
        /*uso atual->proximo por que quando ele apontar pra NULL
          vou estar atualmente em cima da Célula que eu quero*/
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = NULL;//faz anterior apontar para NULL, desligando atual da lista.
    pLista->ultima = anterior;//apontando o ultimo pro anterior ao que foi removido
    
    Pessoa *pessoaRemovida = atual->pessoa;//essa é a que eu removi da lista (copiei o valor do ponteiro)
    free(atual);//liberei

    pLista->tamanhoDaLista--;

    return pessoaRemovida;
}