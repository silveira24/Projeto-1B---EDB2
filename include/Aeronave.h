#ifndef AERONAVE_H
#define AERONAVE_H

typedef struct Aeronave 
{
    char ID[6];
    int combustivel;
    int horario;
    int tipo;
    int emergencia;
    int prioridade;
} Aeronave;

int calcularPrioridade(Aeronave* aeronave);
Aeronave* criarAeronave(char* ID, int combustivel, int horario, int tipo, int emergencia);
void exibirAeronave(Aeronave* aeronave);
void atualizarAeronave (Aeronave* aeronave, int combustivel, int horario, int tipo, int emergencia);

#endif