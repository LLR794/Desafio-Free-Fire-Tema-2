#ifndef INVENTARIO_VETOR_H
#define INVENTARIO_VETOR_H

#include "item.h"

#define CAPACIDADE_MAXIMA 20 // Tamanho fixo da mochila

typedef struct {
    Item itens[CAPACIDADE_MAXIMA];
    int tamanho_atual;
} InventarioVetor;

// Protótipos das funções de gerenciamento do inventário
void inicializar_inventario(InventarioVetor* inv);
int inserir_item_inventario(InventarioVetor* inv, Item novo_item);
int remover_item_inventario(InventarioVetor* inv, const char* nome_item);
void imprimir_inventario(const InventarioVetor* inv);

#endif // INVENTARIO_VETOR_H
