#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Heap.h"

int main() {
    
    Heap heap = inicializarHeap();

    carregarAeronaves(&heap, "voos.csv");

    exibirHeap(heap);

    return 0;
}