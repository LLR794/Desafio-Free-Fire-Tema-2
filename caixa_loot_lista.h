#ifndef CAIXA_LOOT_LISTA_H
#define CAIXA_LOOT_LISTA_H

#include "item.h"

// Nó da lista encadeada
typedef struct No {
    Item item;
    struct No* proximo;
} No;

void inserir_item_lista(No** cabeca, Item novo_item);
void imprimir_lista(const No* cabeca);
void liberar_lista(No** cabeca);

#endif // CAIXA_LOOT_LISTA_H
