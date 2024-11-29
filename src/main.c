#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Heap.h"

int main() {
    
    Heap heap = inicializarHeap();

    Aeronave* a1 = criarAeronave("NAVE1", 200, 300, 1, 0);
    Aeronave* a2 = criarAeronave("NAVE2", 199, 300, 1, 0);
    Aeronave* a3 = criarAeronave("NAVE3", 300, 300, 1, 0);
    Aeronave* a4 = criarAeronave("NAVE4", 150, 300, 1, 0);
    Aeronave* a5 = criarAeronave("NAVE5", 100, 300, 1, 0);
    Aeronave* a6 = criarAeronave("NAVE6", 70, 300, 1, 0);
    Aeronave* a7 = criarAeronave("NAVE7", 50, 300, 1, 0);

    inserirAeronave(&heap, a1);
    inserirAeronave(&heap, a2);
    inserirAeronave(&heap, a3);
    inserirAeronave(&heap, a4);
    inserirAeronave(&heap, a5);
    inserirAeronave(&heap, a6);
    inserirAeronave(&heap, a7);


    atualizaAeronavePorID(&heap, "NAVE3", 60, 300, 1, 0);

    exibirHeap(heap);

    liberarHeap(&heap);

    return 0;
}
