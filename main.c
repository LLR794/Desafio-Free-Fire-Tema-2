#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "item.h"
#include "inventario_vetor.h"
#include "caixa_loot_lista.h"
#include "ordenacao.h"
#include "busca.h"

// Função para simular a exploração da ilha e encontrar um item
Item encontrar_item_aleatorio() {
    Item itens_possiveis[] = {
        {"Macas", ALIMENTO, 10}, {"Carne Seca", ALIMENTO, 20},
        {"Faca", ARMA, 30}, {"Pistola", ARMA, 70},
        {"Machado", FERRAMENTA, 40}, {"Kit Medico", FERRAMENTA, 80},
        {"Placa de Metal", COMPONENTE_TORRE, 100},
        {"Fio de Cobre", COMPONENTE_TORRE, 100},
        {"Bateria", COMPONENTE_TORRE, 100}
    };
    int num_itens = sizeof(itens_possiveis) / sizeof(Item);
    return itens_possiveis[rand() % num_itens];
}

void verificar_vitoria(InventarioVetor* inv) {
    int tem_metal = busca_sequencial(inv, "Placa de Metal") != -1;
    int tem_fio = busca_sequencial(inv, "Fio de Cobre") != -1;
    int tem_bateria = busca_sequencial(inv, "Bateria") != -1;

    if (tem_metal && tem_fio && tem_bateria) {
        printf("\n**************************************************\n");
        printf("VITORIA! Voce reuniu todos os componentes e construiu a torre de fuga!\n");
        printf("**************************************************\n");
        exit(0); // Encerra o jogo
    } else {
        printf("\nVoce ainda nao tem todos os componentes necessarios para a fuga.\n");
        printf("Componentes necessarios: Placa de Metal, Fio de Cobre, Bateria.\n");
    }
}


int main() {
    srand(time(NULL));
    InventarioVetor mochila;
    No* caixa_de_loot = NULL;
    int opcao;
    int inventario_ordenado = 0; // Flag para saber se podemos usar busca binária

    inicializar_inventario(&mochila);

    // Pré-popula a caixa de loot (lista encadeada) para demonstração
    inserir_item_lista(&caixa_de_loot, encontrar_item_aleatorio());
    inserir_item_lista(&caixa_de_loot, encontrar_item_aleatorio());

    do {
        printf("\n=========== ILHA DA SOBREVIVENCIA ===========\n");
        printf("1. Exibir Mochila\n");
        printf("2. Explorar a Ilha (encontrar item)\n");
        printf("3. Ordenar Mochila (por nome)\n");
        printf("4. Buscar Item na Mochila\n");
        printf("5. Ver Caixa de Loot (Lista Encadeada)\n");
        printf("6. Construir Torre de Fuga\n");
        printf("0. Desistir e Sair\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimir_inventario(&mochila);
                break;
            case 2: {
                Item item_encontrado = encontrar_item_aleatorio();
                printf("\nVoce encontrou: ");
                imprimir_item(&item_encontrado);
                inserir_item_inventario(&mochila, item_encontrado);
                inventario_ordenado = 0; // Inserção desordena o inventário
                break;
            }
            case 3:
                selection_sort_por_nome(&mochila);
                inventario_ordenado = 1;
                break;
            case 4: {
                char nome_busca[50];
                printf("Digite o nome do item a buscar: ");
                scanf("%s", nome_busca);

                if (!inventario_ordenado) {
                    printf("AVISO: A mochila nao esta ordenada. Usando busca sequencial.\n");
                    int idx = busca_sequencial(&mochila, nome_busca);
                    if(idx != -1) printf("Item encontrado no indice %d!\n", idx);
                    else printf("Item nao encontrado.\n");
                } else {
                    printf("Mochila ordenada. Usando busca binaria (recursiva).\n");
                    int idx = busca_binaria_recursiva(mochila.itens, 0, mochila.tamanho_atual - 1, nome_busca);
                     if(idx != -1) printf("Item encontrado no indice %d!\n", idx);
                    else printf("Item nao encontrado.\n");
                }
                break;
            }
            case 5:
                imprimir_lista(caixa_de_loot);
                break;
            case 6:
                verificar_vitoria(&mochila);
                break;
            case 0:
                printf("Voce desistiu da ilha...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 0);

    // Limpeza final da memória
    liberar_lista(&caixa_de_loot);
    printf("Recursos liberados.\n");

    return 0;
}
