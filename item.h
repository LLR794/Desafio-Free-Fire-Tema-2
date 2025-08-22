#ifndef ITEM_H
#define ITEM_H

// Enum para categorizar os itens
typedef enum {
    ALIMENTO,
    ARMA,
    FERRAMENTA,
    COMPONENTE_TORRE // Itens especiais para o objetivo final
} TipoItem;

// Struct que representa um item no jogo
typedef struct {
    char nome[50];
    TipoItem tipo;
    int prioridade; // Pode ser dano da arma, cura do alimento, etc.
} Item;

// Protótipo da função para imprimir um item de forma legível
void imprimir_item(const Item* item);

// Função auxiliar para converter o tipo do item em string
const char* tipo_item_para_string(TipoItem tipo);

#endif // ITEM_H
