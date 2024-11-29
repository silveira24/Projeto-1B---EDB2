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
void carregarAeronaves(Heap* heap, char* nome_arquivo);
void inserirAeronave(Heap* heap, Aeronave* aeronave);
Aeronave* consultarMaiorPrioridade (Heap* heap);
void removerMaiorPrioridade (Heap* heap);
void exibirHeap(Heap heap);
void liberarHeap(Heap* heap);
int retornaIndicePeloID(Heap* heap, char* ID);
void atualizaAeronavePorID(Heap* heap, char*ID, int combustivel, int horario, int tipo, int emergencia);
void corrigirPraCima(Heap* heap, int i);
void corrigirPraBaixo(Heap* heap, int i);
void trocar(Aeronave* a, Aeronave* b);

#endif