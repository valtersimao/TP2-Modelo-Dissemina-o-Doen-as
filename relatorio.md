# Relatório do Trabalho Prático 2

Para armazenar os dados das pessoas inicialmente, criamos um TAD $Pessoa$ com 3 funções, 2 do tipo $Pessoa$ e a outra do tipo $void$:

## Pessoa *PessoaCria (int id, int idade, char *nome)

    Ela pega as informações de uma pessoa do arquivo e armazena na struct do tipo Pessoa. Preferi alocar espaço para o nome por que se houvesse um caso onde os nomes contidos no arquivo não fossem conhecidos, garantiremos que cada nome tenha seu tamanho total real.

## Pessoa *PessoaDestroi (Pessoa *pPessoa)

    Libera o nome alocado e a struct referente a 01 pessoa.

## void PessoaPrint (Pessoa *pPessoa)

    Imprime as informações de uma pessoa onde for chamada.
\
\
Na parte da implemtentação do TAD Lista$, criamos uma _lista encadeada com cabeça_ com as funções básicas que julgamos necessárias, considerando também os TAD's Fila, Pilha e Pessoa:

## ListaEsvazia (Lista *pLista)

    É chamada depois que as Pessoas são liberadas, dando free normalmente em cada célula da lista com um ponteiro sempre para a próxima célula a ser liberada, começando pelo início. Após liberar todas as células, ela torna a lista reutilizável novamente para uma próxima simulação.
