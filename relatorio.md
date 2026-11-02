# Relatório - Trabalho Prático 2

## ``TAD Pessoa``

Para armazenar os dados das pessoas inicialmente, criamos um ``TAD Pessoa`` com 3 funções, 2 sendo do tipo ``Pessoa`` e a outra do tipo ``void``:

### `Pessoa` *PessoaCria (int id, int idade, char *nome)

Ela pega as informações de uma pessoa do arquivo e armazena na struct do tipo ``Pessoa``. Preferi alocar espaço para o nome por que se houvesse um caso onde os nomes contidos no arquivo não fossem conhecidos, garantiremos que cada nome tenha seu tamanho total real.

### `Pessoa` *PessoaDestroi (Pessoa *pPessoa)

Libera o nome alocado e a struct referente a 01 pessoa.

### `void` PessoaPrint (Pessoa *pPessoa)

Imprime as informações de uma pessoa onde for chamada.

## ``TAD Lista``

Na parte da implemtentação do ``TAD Lista``, criamos uma _lista encadeada com cabeça_ com as funções básicas que julgamos necessárias, considerando também os TAD's Fila, Pilha e Pessoa:

### `bool` ListaEsvazia (Lista *pLista)

É chamada depois que as _pessoas_ são liberadas (em `ListaDestroi()`), dando _free_ normalmente em cada célula da lista com um ponteiro sempre para a próxima célula a ser liberada, começando pelo início. Após liberar todas as células, ela torna a lista reutilizável novamente para uma próxima simulação.

### `Lista` *ListaDestroi (Lista *pLista)
  
Libera pesoa por pessoa com `PessoaDestroi()` antes de liberar as células com o `ListaEsvazia()` e, posteriormente, a lista.

### `bool` *ListaInsereInicio (Lista *pLista, void *pPessoa)

A decisão de implementar um ponteiro para *void nela surgiu quando nosso ``TAD Eventos`` começou a barrar o tipo Pessoa que foi anteriormente declarado, agora nossa Pilha de Eventos trabalha com um ponteiro genérico, mantendo a passagem correta dos dados.

## ``TAD Ordenacao``

O ``TAD Ordenacao`` é responsável por manter a toda a lista de pessoas, a pilha de eventos e a fila de pessoas que já foram infectadas, ordenadas mediante as regras de prioridade:

### `bool` VerificaPriori (Pessoa *pessoa1, Pessoa *pessoa2)

A função trabalha como um comparador que retorna _true_ se a pessoa 1 tem prioridade sobre a pessoa 2 quando ela vem antes da 2. Se a pessoa 2 tem a prioridade (_return false_), a pessoa 2 é inserida antes da pessoa 1 na lista. Decidimos usar um _Insertion Sort_, rodando toda a lista com as informações provenientes do arquivo.

### `void` OrdenaInsertion (Lista *pLista)

A ordanção por inserção percorre toda a lista original construindo uma lista temporária do zero. Enquanto a variável `busca` tiver _prioridade_ sobre a `atual`, a lista continua a ser percorrida. Quando `atual` têm prioridade sobre `busca`, ou a nova lista acaba, `atual` é inserida entre `anterior` e `busca` pq tem _prioridade_ sobre `busca`. Vale ressaltar que quando a ordenação acaba, a cabeca da lista original será apontada para a **_nova lista já ordenda_**.

```c
/*atualizar o ponteiro que aponta pro ultimo*/
pLista->cabeca->proximo = cabecaSecond.proximo;

/*reconecta a lista original no primeiro
elemento na cabeça da ordenda secundária*/
Celula *conectaCabeca = cabecaSecond.proximo;

while(conectaCabeca != NULL && conectaCabeca->proximo != NULL){
    conectaCabeca = conectaCabeca->proximo;
}

//atualizaçao
pLista->ultima = conectaCabeca;
```

### InsereOrdenado(Lista *pLista, Pessoa *pPessoa)

Realiza o trabalho _refinado_ de ordenação. Por exemplo, se alguma pessoa se _curar_ e voltar para o `Estado 1`, essa pessoa será inserida ordenadamente conforme a disposição das demais pessoas na lista do `Estado 1`. Toda vez que for preciso transitar uma pessoa sobre uma nova lista, a função insere automaticamente na posição que segue as regras de prioridade.
\
O `while` faz a verificação: se quem já está na lista tem prioridade sobre a **_nova pessoa_** que será inserida.

```c
//se o que está na lista tem prioridade sobre a nova pessoa
while(atual != NULL && VerificaPriori(atual->pessoa, pPessoa)){
    anterior = atual;
    atual = atual->proximo;
}
/*se for false o while sai [pessoa nova
é mais velha ou possui id menor]*/
nova->proximo = atual;
//a nova aponta para a que foi comparada da lista original
anterior->proximo = nova;
//agora ela está inserida entre nova e atual
```

## ``TAD Evento``

O `TAD Evento` foi modificado para atuar de forma independente ao `TAD Pilha`, antes havia gerado um problema de dependênicia circular.

### `Evento` EventoAdiciona(int dia, Pessoa *pessoa, int estadoAnterior, int estadoAtual):

_Aloca_ um evento e depois é passado para a _Pilha_ em `simulacao.c`, registra **dia da ocorrência**, a **pessoa** e a **transição dos Estados**. Ela retorna o _ponteiro do evento_ que foi criado pro motor da simulação e é inserido ali, na Pilha.

### ``void`` EventoDestroi(Evento *e):

Libera a memória alocada em cada _Evento_ quando realiza a liberação da `Pilha` no final de cada `simualção`.

## ``TAD Fila``

Criamos a fila encapsulando o `TAD Lista` conforme as regras _**FIFO** (First-In, First-Out)_, assim conseguimos isolar os eventos de cada dia específico. Inserimos no _início da lista_, que representa o _topo da pilha_.
As funções ``FilaInsere`` e ``FilaRemove`` funcionam por meio das funções ``ListaInsereFim`` e ``ListaRemoveInicio``. O TAD realiza a função de armazenar os novos infectados e os novos doentes, cumprindo a exigência de que uma pessoa infectada no _**dia d**_ só é transferida para o Estado 2 ou 3 no _fim do mesmo dia_, podendo infectar as demais **somente** no dia seguinte _**(d+1)**_.

## ``TAD Pilha``

O `TAD Pilha` segue as regras _**LIFO** (Last-In, First-Out)_ também encapsulanndo o `TAD Lista`. A `Pilha` é responsável por _armazenar o histórico de transições_ das pessoas entre os Estados.

### ``Pilha`` *PilhaInsere() & ``Pilha`` *PilhaRemove():

As operações de **inserir** e **remover** na pilha ocorrem na _cabeça da lista_, isso nos ajudou a manter a ordem cronológica certa em  movimentar os Eventos usando a **ordem reversa** de inserção da pilha.

### ``void`` PilhaLiberaEventos():

A cada simulação $I$ a função esvazia o histórico de _Eventos_ com `EventoDestroi` em cada elemento da Pilha. Assim todos os eventos das $I$ simulações não ficam acumulados.