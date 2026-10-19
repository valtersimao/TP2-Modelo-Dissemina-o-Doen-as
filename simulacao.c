#include <parametros.h>

void SimulacaoArquivoTexto(Pessoa **pPessoa){
    FILE *arquivoTexto;
    
    arquivoTexto = fopen("pessoa.txt");
    //verificação depois de abrir
    if(!arquivo){
        printf("\nERRO AO ABRIR A LISTA DE PESSOAS\n");
        return;
    }

    fclose(arquivoTexto);
}