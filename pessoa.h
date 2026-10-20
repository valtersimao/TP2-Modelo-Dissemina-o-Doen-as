#ifndef PESSOA_H
#define PESSOA_H

#include <string.h>

typedef struct {
    int id;
    int idade;
    char *nome;
} Pessoa;

Pessoa *PessoaCria(int id, int idade, char *nome);
Pessoa *PessoaDestroi(Pessoa *pPessoa);

#endif