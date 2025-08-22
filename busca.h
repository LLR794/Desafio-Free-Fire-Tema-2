#ifndef BUSCA_H
#define BUSCA_H

#include "inventario_vetor.h"

int busca_sequencial(const InventarioVetor* inv, const char* nome_item);
int busca_binaria_iterativa(const InventarioVetor* inv, const char* nome_item);
int busca_binaria_recursiva(const Item* itens, int inicio, int fim, const char* nome_item);

#endif // BUSCA_H
