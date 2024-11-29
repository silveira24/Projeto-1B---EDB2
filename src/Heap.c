#include <stdio.h>
#include <stdlib.h>

#include "../include/Heap.h"

Heap inicializarHeap(){
    Heap heap;
    heap.tamanho = 0;
    return heap;
}

int pai (int i) {
    return (i - 1) / 2;
}

int filhoEsquerdo (int i) {
    return 2 * i + 1;
}

int filhoDireito (int i) {
    return 2 * i + 2;
}

void carregarAeronaves(Heap* heap, char* nome_arquivo) {
    FILE* arquivo;
    char linha[50];

    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo\n");
        return;
    }

    char ID[6];
    int combustivel;
    int horario;
    int tipo;
    int emergencia;

    while(fgets(linha, sizeof(linha), arquivo) != NULL) {

        int resultado = sscanf(linha, "%5[^,],%d,%d,%d,%d", ID, &combustivel, &horario, &tipo, &emergencia);

        if (resultado == 5) {
            Aeronave* novaAeronave = criarAeronave(ID, combustivel, horario, tipo, emergencia);
            inserirAeronave(heap, novaAeronave);
        } else {
            printf("erro ao ler aeronave na linha : %s\n", linha);
            printf("resultado = %d\n", resultado);
        }
        
    }
    
    fclose(arquivo);

}

void inserirAeronave(Heap* heap, Aeronave* aeronave) {
    if (heap->tamanho == 50) {
        printf("Erro: heap está cheio!\n");
        return;
    }

    int i = heap->tamanho;
    heap->aeronaves[i] = aeronave;
    heap->tamanho++;

    while (i > 0 && heap->aeronaves[pai(i)]->prioridade < heap->aeronaves[i]->prioridade) {
        Aeronave* temp = heap->aeronaves[i];
        heap->aeronaves[i] = heap->aeronaves[pai(i)];
        heap->aeronaves[pai(i)] = temp;
        i = pai(i);
    }
}

Aeronave* consultarMaiorPrioridade (Heap* heap) {
    return heap->aeronaves[0];
}

Aeronave* removerMaiorPrioridade (Heap* heap) {
    if (heap->tamanho <= 0) {
        printf("heap vazio\n");
        return NULL;
    }

    Aeronave* maximo = heap->aeronaves[0];

    heap->aeronaves[0] = heap->aeronaves[heap->tamanho-1];
    heap->tamanho--;

    int i = 0;
    while(1) {
        int esquerdo = filhoEsquerdo(i);
        int direito = filhoDireito(i);
        int maior = i;

        if (esquerdo < heap->tamanho && heap->aeronaves[esquerdo]->prioridade > heap->aeronaves[maior]->prioridade) {
            maior = esquerdo;
        }

        if (direito < heap->tamanho && heap->aeronaves[direito]->prioridade > heap->aeronaves[maior]->prioridade) {
            maior = esquerdo;
        }

        if (maior == i) {
            break;
        }

        Aeronave* temp = heap->aeronaves[i];
        heap->aeronaves[i] = heap->aeronaves[maior];
        heap->aeronaves[maior] = temp;

        i = maior;
    }

    return maximo;

}

void exibirHeap(Heap heap) {
    printf("HEAP:\n\n");
    for (int i = 0; i < heap.tamanho; i++)
    {
        exibirAeronave(heap.aeronaves[i]);
        printf("\n\n");
    }
}