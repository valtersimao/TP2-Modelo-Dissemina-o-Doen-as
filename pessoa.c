#include "pessoa.h"

struct pessoa{
    int id;
    int idade;
    char nome[26];
};

Pessoa *PessoaCria(){
    Pessoa *pPessoa = (Pessoa*) malloc(sizeof(Pessoa));
    if(!pPessoa) return NULL;
    pPessoa->id = ;
    pPessoa->idade = ;
    pPessoa->nome = ;
}