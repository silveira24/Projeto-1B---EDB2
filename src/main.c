#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Heap.h"
#include "../include/Menu.h"

int main() {
    
    Heap heap = inicializarHeap();

    carregarAeronaves(&heap, "voos.csv");

    int menu;

    exibirMenu();
    scanf("%d", &menu);

    while (menu != 0) {
        switch (menu) {
        case 1:
            inserirAeronave(&heap, adicionarAeronave());
            break;
        case 2:
            exibirAeronave(consultarMaiorPrioridade(&heap));
            break;
        case 3:
            removerMaiorPrioridade(&heap);
            break;
        case 4:
            atualizacaoAeronave(&heap);
            break;
        case 5:
            exibirHeap(heap);
            break;
        default:
            printf("Comando inválido, tente novamente\n");
            break;
        }

        exibirMenu();
        scanf("%d", &menu);
    }
    
    printf("saindo do sistema...\n");
    liberarHeap(&heap);

    return 0;
}
