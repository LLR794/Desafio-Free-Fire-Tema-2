#include <string.h>
#include <stdio.h>
#include "ordenacao.h"

// Ordena o inventário (vetor) por nome usando o algoritmo Selection Sort
void selection_sort_por_nome(InventarioVetor* inv) {
    int i, j, min_idx;
    Item temp;

    for (i = 0; i < inv->tamanho_atual - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < inv->tamanho_atual; j++) {
            // Compara os nomes dos itens
            if (strcmp(inv->itens[j].nome, inv->itens[min_idx].nome) < 0) {
                min_idx = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento
        if(min_idx != i) {
            temp = inv->itens[min_idx];
            inv->itens[min_idx] = inv->itens[i];
            inv->itens[i] = temp;
        }
    }
    printf("\nMochila ordenada por nome.\n");
}
