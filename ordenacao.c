#include "ordenacao.h"

#include <stdlib.h>

bool VerificaPriori(Pessoa *pessoa1, Pessoa *pessoa2){//TÁ NO .H
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

////já vem da lista direto pra ca
void *OrdenaInsertion(Lista *pLista){
    if(!cabeca) return;
    if(!pLista->cabeca->pessoa) return;

    //Guarda o 1º elemento válido (m esquerda)
    Celula *atual = pLista->cabeca->proximo;

    //(m direita)
    Celula cabecaTemp;
    cabecaTemp.proximo = NULL;
    
    Celula *anterior = &cabecaTemp;
    Celula *proximoAtual = atual->proximo;

    
    /*OrdenaMerge pode ser util para atualizar a ultima posição:
    //atualizar o ponteiro que aponta pro ultimo
    pLista->cabeca->proximo = ordenaNovaCabeca;//reconecta a lista na cauda depois de ordenada
    Celula *atual = ordenaNovaCabeca;
    while(atual != NULL && atual->proximo != NULL){
        atual = atual->proximo;
    }
    //atualizaçao
    pLista->ultima = atual;
    */
}

//achar o meio da lista e retorna meu ponteiro pra SEGUNDA METD..
Celula *DividirLista(Celula *cabeca){
    if(!cabeca) return NULL;

    Celula *lentinho = cabeca;
    Celula *rapidinho = cabeca->proximo;
    while(rapidinho !=NULL && rapidinho->proximo != NULL){
        lentinho = lentinho->proximo;
        rapidinho = rapidinho->proximo->proximo;
    }
    //terminou o laço, lentinho vai estar no meio da lista
    //no final da minha primeira metade
    Celula *metade2 = lentinho->proximo;//referencia a segunda metade toda
    //agora eu posso cortar minha lista no meio sem perder a referencia
    lentinho->proximo = NULL;

    //retorna o ponteiro apontando pro inicio da minha segunda metade
    return metade2;
}

//juntar as listas em uma nova lista ordenda
Celula *IntercalaListas(Celula *metade1, Celula *metade2){
    //se alguma das 2 for NULA, retorno a outra pra não perder o resto
    if(!metade1) return metade2;
    if(!metade2) return metade1;

    //facilitar a forma de conectar as 2 partes
    Celula cabecaTemp;
    cabecaTemp.proximo = NULL;
    Celula *atual = &cabecaTemp;//aponta pro ultimo elemento

    /*o 'atual' forma a minha lista, as metades são
    inseridas conforme o critério de prioridades*/

    while(metade1 != NULL && metade2 != NULL){//vai rodar enquanto as listas ainda tiverem elem.
        if(VerificaPriori(metade1->pessoa, metade2->pessoa)){//se pessoa da metade 1 se adequar
            atual->proximo = metade1;//CELULAS  
            metade1 = metade1->proximo;//ELEMENTOS DA METADE DA LISTA
        }else{//se pessoa da metade 1 não se adequar
            atual->proximo = metade2;
            metade2 = metade2->proximo;
        }
        //andando na lista
        atual = atual->proximo;
    }

    if(metade1 != NULL){//se ainda estiver sobrando na PRIMEIRA metade
        atual->proximo = metade1;
    } else {//se ainda estiver sobrando na SEGUNDA metade
        atual->proximo = metade2;
    }

    //RETORNA O INÍCIO com a lista já ordenada
    return cabecaTemp.proximo;//aponta pro primeiro pós cabeça
}

Celula *RecursaoMerge(Celula *cabeca){
    if(!cabeca) return cabeca;
    if(!cabeca->proximo) return cabeca;//a cabeça pode ter apenas 1 elem.


    //DIVIDIR PARA..
    //trás o ponteiro pro meu primeiro elemento da segunda metdade
    Celula *inicioMetade2 = DividirLista(cabeca);

    //CONQUISTAR
    Celula *pegaMetade1 = RecursaoMerge(cabeca);
    //passando o ponteiro pra primeira metade dnvv

    Celula *pegaMetade2 = RecursaoMerge(inicioMetade2);//"cabeca" da segunda parte

    //juntando tudo e retornando as 2 jntas
    return IntercalaListas(pegaMetade1, pegaMetade2);
}
//já vem da lista direto pra ca
//Dividir pra Conquistar 
void OrdenaMerge(Lista *pLista){//TÁ NO .H
    if(!pLista || pLista->tamanhoDaLista < 2) return;
    //se a lista tiver só 1 elemento, ela já tá ordenada

    //Guarda o 1º elemento válido
    Celula *primeiraPessoa = pLista->cabeca->proximo;
    Celula *ordenaNovaCabeca = RecursaoMerge(primeiraPessoa);

    //atualizar o ponteiro que aponta pro ultimo
    pLista->cabeca->proximo = ordenaNovaCabeca;//reconecta a lista na cauda depois de ordenada
    Celula *atual = ordenaNovaCabeca;
    while(atual != NULL && atual->proximo != NULL){
        atual = atual->proximo;
    }
    //atualizaçao
    pLista->ultima = atual;
}