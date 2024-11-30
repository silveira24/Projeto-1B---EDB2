#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Menu.h"

void exibirMenu() {
    printf("Escolha uma das opções:\n");
    printf("1 - adicionar voo\n");
    printf("2 - consultar voo com maior prioridade\n");
    printf("3 - remover voo com maior prioridade\n");
    printf("4 - atualizar dados de um voo\n");
    printf("5 - exibir heap dos voos\n");
    printf("0 - sair do sistema\n");
}

Aeronave* adicionarAeronave() {
    char ID[6];
    int combustivel;
    int horario;
    int tipo;
    int emergencia;

    printf("digite os dados do voo\n");

    printf("Digite o identificador do voo: ");
    limparBuffer();
    fgets(ID, sizeof(ID), stdin);
    ID[strcspn(ID, "\n")] = '\0';

    printf("Digite a quantidade de combustivel da aeronave (em litros): ");
    scanf("%d", &combustivel);

    printf("Digite o horário do voo previsto(em minutos do dia): ");
    scanf("%d", &horario);

    printf("Digite o tipo de operação (0 para decolagem, 1 para pouso): ");
    scanf("%d", &tipo);
    while (tipo != 0 && tipo != 1) {
        printf("Valor inválido\n");
        printf("Digite o tipo de operação (0 para decolagem, 1 para pouso): ");
        scanf("%d", &tipo);
    }
    
    printf("Informe se o voo está em situação de emergencia (0 para não, 1 para sim): ");
    scanf("%d", &emergencia);
    while (emergencia != 0 && emergencia != 1) {
        printf("Valor inválido\n");
        printf("Informe se o voo está em situação de emergencia (0 para não, 1 para sim): ");
        scanf("%d", &emergencia);
    }

    return criarAeronave(ID, combustivel, horario, tipo, emergencia);
}

void atualizacaoAeronave(Heap* heap) {
    char ID[6];
    int combustivel;
    int horario;
    int tipo;
    int emergencia;

    printf("digite os dados do voo\n");

    printf("Digite o identificador do voo: ");
    limparBuffer();
    fgets(ID, sizeof(ID), stdin);
    ID[strcspn(ID, "\n")] = '\0';

    if(retornaIndicePeloID(heap, ID) == -1) {
        printf("Voo não encontrado no sistema\n");
        return;
    }

    printf("Digite a quantidade de combustivel da aeronave (em litros): ");
    scanf("%d", &combustivel);

    printf("Digite o horário do voo previsto(em minutos do dia): ");
    scanf("%d", &horario);

    printf("Digite o tipo de operação (0 para decolagem, 1 para pouso): ");
    scanf("%d", &tipo);
    while (tipo != 0 && tipo != 1) {
        printf("Valor inválido\n");
        printf("Digite o tipo de operação (0 para decolagem, 1 para pouso): ");
        scanf("%d", &tipo);
    }
    
    printf("Informe se o voo está em situação de emergencia (0 para não, 1 para sim): ");
    scanf("%d", &emergencia);
    while (emergencia != 0 && emergencia != 1) {
        printf("Valor inválido\n");
        printf("Informe se o voo está em situação de emergencia (0 para não, 1 para sim): ");
        scanf("%d", &emergencia);
    }

    atualizaAeronavePorID(heap, ID, combustivel, horario, tipo, emergencia);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}