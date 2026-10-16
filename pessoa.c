#include "pessoa.h"

Pessoa *PessoaCria(int id, int idade, char nome[]){
    Pessoa pPessoa;
    
    int tamanhoNome = strlen(nome);
    int padronizaNome = tamanhoNome-1;
    pPessoa->nome = nome;

    pPessoa->id = id;
    pPessoa->idade = idade;
}