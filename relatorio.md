# Relatório do Trabalho Prático 2

Para armazenar os dados das pessoas inicialmente, criamos um TAD $Pessoa$ com 3 funções, 2 do tipo $Pessoa$ e a outra do tipo $void$:

### $Pessoa$ *PessoaCria (int id, int idade, char *nome)

    Ela pega as informações de uma pessoa do arquivo e armazena na struct do tipo Pessoa. Preferi alocar espaço para o nome por que se houvesse um caso onde os nomes contidos no arquivo não fossem conhecidos, garantiremos que cada nome tenha seu tamanho total real.

### $Pessoa$ *PessoaDestroi (Pessoa *pPessoa)

    Libera o nome alocado e a struct referente a 01 pessoa.

### $void$ PessoaPrint (Pessoa *pPessoa)

    Imprime as informações de uma pessoa onde for chamada.

\
\
Na parte da implemtentação do TAD $Lista$, criamos uma _lista encadeada com cabeça_ com as funções básicas que julgamos necessárias, considerando também os TAD's Fila, Pilha e Pessoa:

### $bool$ ListaEsvazia (Lista *pLista)

    É chamada depois que as Pessoas são liberadas (em 'ListaDestroi'), dando free normalmente em cada célula da lista com um ponteiro sempre para a próxima célula a ser liberada, começando pelo início. Após liberar todas as células, ela torna a lista reutilizável novamente para uma próxima simulação.

### $Lista$ *ListaDestroi (Lista *pLista)
  
    Libera pesoa por pessoa com 'PessoaDestroi()' antes de liberar as células com o 'ListaEsvazia()' e, posteriormente, a lista.

### $bool$ *ListaInsereInicio (Lista *pLista, void *pPessoa)

    A decisão de implementar um ponteiro para *void nela surgiu quando nosso TAD Eventos começou a barrar o tipo Pessoa que foi anteriormente declarado, agora nossa Pilha de Eventos trabalha com um ponteiro genérico, mantendo a passagem correta dos dados.

\
\
O TAD $Ordenacao$ é responsável por manter a toda a lista de pessoas, a pilha de eventos e a fila de pessoas que já foram infectadas, ordenadas mediante as regras de prioridade:

## $bool$ VerificaPriori (Pessoa *pessoa1, Pessoa *pessoa2)

    A função trabalha como um comparador que retorna true se a pessoa 1 tem prioridade sobre a pessoa 2 quando ela vem antes da 2. Se a pessoa 2 tem a prieridade, (return false) a pessoa 2 é inserida antes da pessoa 1 na lista.
\
Decidimos usar um _Insertion Sort_, rodando toda a lista com as informações provenientes do arquivo.

## $void$ OrdenaInsertion (Lista *pLista)

    