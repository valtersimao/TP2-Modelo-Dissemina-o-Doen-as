#ifndef PESSOA_H
#define PESSOA_H

typedef struct {
    int id;
    int idade;
    char nome[26];
} Pessoa;

Pessoa *PessoaCria(int id, int idade, char nome[]);
void PessoaGet(Pessoa *pPessoa, int id);

#endif