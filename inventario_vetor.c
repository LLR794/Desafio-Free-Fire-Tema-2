#include <stdio.h>
#include <string.h>
#include "inventario_vetor.h"
#include "busca.h" // Usaremos a busca sequencial daqui

void inicializar_inventario(InventarioVetor* inv) {
    inv->tamanho_atual = 0;
    printf("Mochila de sobrevivencia preparada!\n");
}

int inserir_item_inventario(InventarioVetor* inv, Item novo_item) {
    if (inv->tamanho_atual >= CAPACIDADE_MAXIMA) {
        printf("Mochila cheia! Nao foi possivel pegar o item '%s'.\n", novo_item.nome);
        return 0; // Falha
    }
    inv->itens[inv->tamanho_atual] = novo_item;
    inv->tamanho_atual++;
    printf("Item '%s' adicionado a mochila.\n", novo_item.nome);
    return 1; // Sucesso
}

int remover_item_inventario(InventarioVetor* inv, const char* nome_item) {
    int indice = busca_sequencial(inv, nome_item);

    if (indice == -1) {
        printf("Item '%s' nao encontrado na mochila.\n", nome_item);
        return 0; // Falha
    }

    // Move todos os itens a direita do item removido uma posição para a esquerda
    for (int i = indice; i < inv->tamanho_atual - 1; i++) {
        inv->itens[i] = inv->itens[i + 1];
    }

    inv->tamanho_atual--;
    printf("Item '%s' removido da mochila.\n", nome_item);
    return 1; // Sucesso
}

void imprimir_inventario(const InventarioVetor* inv) {
    printf("\n--- MOCHILA DE SOBREVIVENCIA (%d/%d) ---\n", inv->tamanho_atual, CAPACIDADE_MAXIMA);
    if (inv->tamanho_atual == 0) {
        printf("A mochila esta vazia.\n");
    } else {
        for (int i = 0; i < inv->tamanho_atual; i++) {
            printf("[%d] ", i);
            imprimir_item(&inv->itens[i]);
        }
    }
    printf("---------------------------------------\n");
}

// Implementações auxiliares que ficam melhor aqui
const char* tipo_item_para_string(TipoItem tipo) {
    switch (tipo) {
        case ALIMENTO: return "Alimento";
        case ARMA: return "Arma";
        case FERRAMENTA: return "Ferramenta";
        case COMPONENTE_TORRE: return "Componente";
        default: return "Desconhecido";
    }
}

void imprimir_item(const Item* item) {
    printf("Item: %-20s | Tipo: %-10s | Prioridade: %d\n",
           item->nome, tipo_item_para_string(item->tipo), item->prioridade);
}
