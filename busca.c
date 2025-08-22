#include <stdio.h>
#include <string.h>
#include "busca.h"

int busca_sequencial(const InventarioVetor* inv, const char* nome_item) {
    for (int i = 0; i < inv->tamanho_atual; i++) {
        if (strcmp(inv->itens[i].nome, nome_item) == 0) {
            return i; // Retorna o índice se encontrar
        }
    }
    return -1; // Retorna -1 se não encontrar
}

int busca_binaria_iterativa(const InventarioVetor* inv, const char* nome_item) {
    int inicio = 0;
    int fim = inv->tamanho_atual - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        int res = strcmp(nome_item, inv->itens[meio].nome);

        if (res == 0) return meio; // Encontrou
        if (res > 0) inicio = meio + 1; // Procura na metade direita
        else fim = meio - 1; // Procura na metade esquerda
    }
    return -1; // Não encontrou
}

int busca_binaria_recursiva(const Item* itens, int inicio, int fim, const char* nome_item) {
    if (inicio > fim) {
        return -1; // Caso base: não encontrou
    }
    int meio = inicio + (fim - inicio) / 2;
    int res = strcmp(nome_item, itens[meio].nome);

    if (res == 0) {
        return meio; // Encontrou
    } else if (res > 0) {
        return busca_binaria_recursiva(itens, meio + 1, fim, nome_item);
    } else {
        return busca_binaria_recursiva(itens, inicio, meio - 1, nome_item);
    }
}
