#include <stdio.h>
#include <stdlib.h>
#include "caixa_loot_lista.h"

// Insere um item no início da lista
void inserir_item_lista(No** cabeca, Item novo_item) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria para a lista.\n");
        return;
    }
    novo_no->item = novo_item;
    novo_no->proximo = *cabeca;
    *cabeca = novo_no;
}

void imprimir_lista(const No* cabeca) {
    printf("\n--- CAIXA DE LOOT (Lista Encadeada) ---\n");
    if (cabeca == NULL) {
        printf("A caixa esta vazia.\n");
    } else {
        const No* atual = cabeca;
        while (atual != NULL) {
            imprimir_item(&atual->item);
            atual = atual->proximo;
        }
    }
    printf("---------------------------------------\n");
}

// Libera toda a memória alocada para a lista
void liberar_lista(No** cabeca) {
    No* atual = *cabeca;
    No* proximo_no;
    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    *cabeca = NULL; // Garante que a cabeça aponte para NULL
}
