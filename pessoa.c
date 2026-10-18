#include "pessoa.h"

#include <stdlib.h>
#include <string.h>

//Pegar as infos do aqruivo
Pessoa *PessoaCria(int id, int idade, char *nome){
    
    Pessoa *pPessoa = (Pessoa*) malloc(sizeof(Pessoa));
    if(!pPessoa) return NULL;

    int tamanhoNome = strlen(nome);
    pPessoa->nome = (char*) malloc(sizeof(char) * (tamanhoNome+1));// tamanhoNome+1 pra caber o '\0'
    strcpy(pPessoa->nome, nome);
    
    pPessoa->id = id;
    pPessoa->idade = idade;
    return pPessoa;
}
//usar so no final do programa pra não perder tudo
Pessoa *PessoaDestroi(Pessoa *pPessoa){
    if(!pPessoa) return NULL;
    free(pPessoa->nome);
    free(pPessoa);
}