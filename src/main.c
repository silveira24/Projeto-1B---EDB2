#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Aeronave.h"

int main() {
    Aeronave* aeronave = criarAeronave("TPR123", 300, 540, 1, 0);
    exibirAeronave(aeronave);
    return 0;
}