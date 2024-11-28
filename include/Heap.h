#ifndef HEAP_H
#define HEAP_H

#include "Aeronave.h"

typedef struct
{
    int tamanho;
    Aeronave* aeronaves[50];
} Heap;

Heap inicializarHeap();
int pai(int i);
int filhoEsquerdo(int i);
int filhoDireito(int i);
void inserirAeronave(Heap* heap, Aeronave* aeronave);
Aeronave* consultarMaiorPrioridade (Heap* heap);
void exibirHeap(Heap heap);

#endif