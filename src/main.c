#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Heap.h"

int main() {
    
    Heap heap = inicializarHeap();

    Aeronave* aeronave1 = criarAeronave("TPR123", 300, 540, 1, 0);
    Aeronave* aeronave3 = criarAeronave("TPR321", 300, 120, 1, 0);
    Aeronave* aeronave2 = criarAeronave("TPR957", 300, 540, 1, 1);

    inserirAeronave(&heap, aeronave1);
    inserirAeronave(&heap, aeronave2);
    inserirAeronave(&heap, aeronave3);

    exibirHeap(heap);

    return 0;
}