#ifndef MENU_H
#define MENU_H

#include "Aeronave.h"
#include "Heap.h"

void exibirMenu();
Aeronave* adicionarAeronave();
void atualizacaoAeronave(Heap* heap);
void limparBuffer();

#endif