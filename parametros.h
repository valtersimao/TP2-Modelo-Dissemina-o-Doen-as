#ifndef PARAMETROS_H
#define PARAMETROS_H

typedef struct parametros{
    int N;// -> número de pessoas da cidade
    double P;// -> percentual da população infectada no dia 0
    double L;// -> probabilidade (%) de um infectado do estado 2 infectar um saudável (estado 1)
    double K;// -> probabilidade (%) de um doente do estado 3 infectar um saudável (estado 1) (K > L)
    double F;// -> probabilidade (%) de um infectado (estado 2) desenvolver a doença (estado 3)
    double M;// -> probabilidade (%) de um doente (estado 3) vir a óbito
    int D;// -> duração da simulação, em dias
    int R;// -> dia em que a vacina passa a ser distribuída
    int Y;// -> a cada dia, a partir de R, são distribuídas N/Y vacinas.
    int I;// Repetir sua simulação I vezes. 
} Parametros;

#endif