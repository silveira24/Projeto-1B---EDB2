#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Heap.h"

int main() {
    
    Heap heap = inicializarHeap();

    Aeronave* aeronave1 = criarAeronave("nave1", 200, 540, 1, 0);
    Aeronave* aeronave2 = criarAeronave("nave2", 200, 120, 1, 0);
    Aeronave* aeronave3 = criarAeronave("nave3", 300, 754, 0, 1);
    Aeronave* aeronave4 = criarAeronave("nave4", 400, 312, 1, 0);
    Aeronave* aeronave5 = criarAeronave("nave5", 400, 213, 0, 0);
    Aeronave* aeronave6 = criarAeronave("nave6", 200, 534, 1, 1);
    Aeronave* aeronave7 = criarAeronave("nave7", 200, 765, 0, 0);
    Aeronave* aeronave8 = criarAeronave("nave8", 100, 345, 0, 1);

    inserirAeronave(&heap, aeronave1);
    inserirAeronave(&heap, aeronave2);
    inserirAeronave(&heap, aeronave3);
    inserirAeronave(&heap, aeronave4);
    inserirAeronave(&heap, aeronave5);
    inserirAeronave(&heap, aeronave6);
    inserirAeronave(&heap, aeronave7);
    inserirAeronave(&heap, aeronave8);

    exibirHeap(heap);
    printf("\n\n\n\n");
    exibirAeronave(removerMaiorPrioridade(&heap));
    printf("\n\n\n\n");
    exibirAeronave(removerMaiorPrioridade(&heap));

    return 0;
}