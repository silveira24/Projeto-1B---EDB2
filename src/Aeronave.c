#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Aeronave.h"

int calcularPrioridade(Aeronave* aeronave) {
    int prioridade = (1000 - aeronave->combustivel) + (1440-aeronave->horario) + 500 * (aeronave->tipo) + 5000 * (aeronave->emergencia);

    return prioridade;
}

Aeronave* criarAeronave(char* ID, int combustivel, int horario, int tipo, int emergencia) {
    Aeronave* novaAeronave = (Aeronave*) malloc(sizeof(Aeronave));
    if (novaAeronave == NULL) {
        return NULL;
    }

    strcpy(novaAeronave->ID, ID);
    novaAeronave->combustivel = combustivel;
    novaAeronave->horario = horario;
    novaAeronave->tipo = tipo;
    novaAeronave->emergencia = emergencia;
    novaAeronave->prioridade = calcularPrioridade(novaAeronave);
}

void exibirAeronave(Aeronave* aeronave) {
    printf("AERONAVE\n\n");
    printf("Identificador: %s\n", aeronave->ID);
    printf("Combustivel restante: %d litros\n", aeronave->combustivel);
    
    int horas = (int) aeronave->horario / 60;
    int minutos = aeronave->horario - (horas * 60);
    printf("Horário previsto de chegada ou partida: %02dh%02dm\n", horas, minutos);
    
    if (aeronave->tipo == 0) {
        printf("Tipo de operação: decolagem\n");
    } else {
        printf("Tipo de operação: pouso\n");
    }

    if (aeronave->emergencia == 0) {
        printf("Aeronave não está em situação de emergência\n");
    } else {
        printf("Aeronave está em situação de emergência\n");
    }
    printf("Prioridade: %d", aeronave->prioridade);
}