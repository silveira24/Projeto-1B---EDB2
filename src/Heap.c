#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    if (retornaIndicePeloID(heap, aeronave->ID) != -1) {
        printf("Voo com mesmo identificador já cadastrado no sistema\n");
        free(aeronave);
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

void removerMaiorPrioridade (Heap* heap) {
    if (heap->tamanho <= 0) {
        printf("heap vazio\n");
        return;
    }

    Aeronave* maximo = heap->aeronaves[0];

    heap->aeronaves[0] = heap->aeronaves[heap->tamanho-1];
    heap->tamanho--;

    corrigirPraBaixo(heap, 0);

    free(maximo);

}

void exibirHeap(Heap heap) {
    printf("HEAP:\n\n");
    for (int i = 0; i < heap.tamanho; i++)
    {
        exibirAeronave(heap.aeronaves[i]);
        printf("\n\n");
    }
}

void liberarHeap(Heap* heap) {
    for(int i = heap->tamanho-1; i>=0; i--) {
        free(heap->aeronaves[i]);
    }
}

int retornaIndicePeloID(Heap* heap, char* ID) {
    for (int i = 0; i < heap->tamanho; i++) {
        if(strcmp(heap->aeronaves[i]->ID, ID) == 0) {
            return i;
        }
    }
    
    return -1;
}

void atualizaAeronavePorID(Heap* heap, char*ID, int combustivel, int horario, int tipo, int emergencia) {
    int i = retornaIndicePeloID(heap, ID);

    if (i == -1) {
        printf("Voo não encontrado no sistema\n");
        return;
    }
    int antigaPrioridade = heap->aeronaves[i]->prioridade;

    atualizarAeronave(heap->aeronaves[i], combustivel, horario, tipo, emergencia);

    int novaPrioridade = heap->aeronaves[i]->prioridade;

    if (novaPrioridade > antigaPrioridade) {
        corrigirPraCima(heap, i);
    } else if (novaPrioridade < antigaPrioridade) {
        corrigirPraBaixo(heap, i);
    }
}

void corrigirPraCima(Heap* heap, int i) {
    while(i > 0 && heap->aeronaves[pai(i)]->prioridade < heap->aeronaves[i]->prioridade) {
        trocar(heap->aeronaves[pai(i)], heap->aeronaves[i]);
        i = pai(i);
    }
}

void corrigirPraBaixo(Heap* heap, int i) {
    int maior = i;
    int esquerdo = filhoEsquerdo(i);
    int direito = filhoDireito(i);

    if (esquerdo < heap->tamanho && heap->aeronaves[esquerdo]->prioridade > heap->aeronaves[maior]->prioridade) {
        maior = esquerdo;
    }

    if (direito < heap->tamanho && heap->aeronaves[direito]->prioridade > heap->aeronaves[maior]->prioridade) {
        maior = direito;
    }

    if (maior != i) {
        trocar(heap->aeronaves[i], heap->aeronaves[maior]);
        corrigirPraBaixo(heap, maior);
    }
}

void trocar(Aeronave* a, Aeronave* b) {
    Aeronave temp = *a;
    *a = *b;
    *b = temp;
}