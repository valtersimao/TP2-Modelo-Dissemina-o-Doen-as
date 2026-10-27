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

////já vem da lista toda direto pra cá
void OrdenaInsertion(Lista *pLista) { //O(n²) no pior caso
    if(!pLista || pLista->tamanhoDaLista < 2) return;
    if(!pLista->cabeca->proximo) return;//verificar se o primeiro é NULL

    //Guarda o 1º elemento valido (mao esquerda)
    Celula *atual = pLista->cabeca->proximo;//antecessor de proximoAtual
    //pra percorrer a lista original

    //Cabeça falsa (mao direita)
    Celula cabecaSecond;
    cabecaSecond.proximo = NULL;

    //elementos para trabalhar na minha lista falsa
    Celula *anterior = &cabecaSecond;
    Celula *proximoAtual;//guardar o proximo apos o atual antes de mexer nele
    Celula *busca;

    while(atual != NULL){//percorrer a minha lista original
        proximoAtual = atual->proximo;//guardando
        //pra cada atual é preciso saber onde será sua poisção na lista
        //conforme a regra de inserção
        anterior = &cabecaSecond;
        busca = cabecaSecond.proximo;//andando na lista falsa e guardando o anterior
        
        //enquanto a nova lista não finalizar e
        //a Verificação ainda receber células com pessoas válidas
        while(busca != NULL && VerificaPriori(busca->pessoa, atual->pessoa)){//pessoa da secundaria e pessoa da original
            //laço ordenando com base na regra papae [se a pessoa de busca tem prioridade]
            anterior = busca;//ordena o de prioridade antes do menos prioritário
            busca = busca->proximo;//anda para a próxima célula da lista secundária até a da atual for prioridade
        }//agora, o anterior[que recebeu busca] fica na célula depois da que a atual vai ficar

        //agora é só passar pra la [inserir o atual entre o anterior e o busca]
        atual->proximo = busca;//atual vai apontar pra da frente dele [pq busca ta depois]
        anterior->proximo = atual;

        //continuar avançando uma célula na originial
        atual = proximoAtual;//depois que eu guardei la em cima posso mexer aq embaixo
    }

    /*atualizar o ponteiro que aponta pro ultimo*/
    pLista->cabeca->proximo = cabecaSecond.proximo;//reconecta a lista original no primeiro elemento na cabeça da ordenda secundária
    Celula *conectaCabeca = cabecaSecond.proximo;//poderia ser 'pLista->cabeca->proximo' tbm
    while(conectaCabeca != NULL && conectaCabeca->proximo != NULL){
        conectaCabeca = conectaCabeca->proximo;
    }
    //atualizaçao
    pLista->ultima = conectaCabeca;
}

void InsereOrdenado(Lista *pLista, Pessoa *pPessoa){ //O(n) no pior caso
    if(!pLista || !pPessoa) return;

    Celula *nova = (Celula*) malloc(sizeof(Celula));
    if(!nova) return;

    nova->pessoa = pPessoa;//passa a pessoa pra nova celula criada
    nova->proximo = NULL;
    Celula *anterior = pLista->cabeca;//guarda a anterior começando na cabeça
    Celula *atual = pLista->cabeca->proximo;//ponteiro pra andar na lista

    while(atual != NULL && VerificaPriori(atual->pessoa, pPessoa)){//se o que está na lista tem prioridade sobre a nova pessoa
        anterior = atual;
        atual = atual->proximo;
    }//se for false o while sai [pessoa nova é mais velha ou possui id menor]
    //agora, a 'anterior' aponta pra célula que deve vir antes na 'nova' e 'atual' vem depois
    nova->proximo = atual;//a nova aponta para a que foi comparada da lista original
    anterior->proximo = nova;//anterior agora aponta pra nova inserida

    pLista->tamanhoDaLista++;//inserção
    //se caso a atual for a última
    if(atual == NULL)   
        pLista->ultima = nova;//o ponteiro pra ultima é atualizado
}