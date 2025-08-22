# Desafio Free Fire – Tema 2

## Sobre o Desafio

Este projeto é um mini-game de sobrevivência em C, desenvolvido como parte do desafio da TechNova para a nova versão do modo sobrevivência do Free Fire. O foco principal não é a complexidade do jogo, mas sim a aplicação e comparação de diferentes estruturas de dados e algoritmos fundamentais da ciência da computação.

O cenário é uma ilha hostil onde o jogador precisa gerenciar um inventário, encontrar recursos, otimizar a busca por itens e, finalmente, coletar componentes específicos para construir uma torre de sinalização e escapar.

## Estrutura do Projeto

O código foi rigorosamente modularizado para promover as boas práticas de desenvolvimento, como separação de responsabilidades, legibilidade e manutenibilidade.

-   `main.c`: O ponto de entrada e o controlador principal do jogo. Apresenta o menu ao jogador e gerencia o fluxo das ações.
-   `item.h`: Define a `struct Item`, a entidade base para todos os objetos do jogo (armas, alimentos, ferramentas, etc.).
-   `inventario_vetor.h` / `.c`: Implementa a mochila do jogador utilizando um **vetor (lista sequencial)**. Esta estrutura possui tamanho fixo e demonstra operações de inserção e remoção com deslocamento de elementos.
-   `caixa_loot_lista.h` / `.c`: Implementa uma "caixa de loot" utilizando uma **lista encadeada**. Serve como contraponto ao vetor, demonstrando a flexibilidade da alocação dinâmica de memória, ideal para quando o número de itens é desconhecido.
-   `ordenacao.h` / `.c`: Contém a implementação do algoritmo **Selection Sort**, utilizado para ordenar os itens na mochila por nome.
-   `busca.h` / `.c`: Implementa algoritmos de busca:
    -   **Busca Sequencial**: Usada como padrão em dados não ordenados.
    -   **Busca Binária (Iterativa e Recursiva)**: Usada para encontrar itens de forma eficiente em um inventário previamente ordenado, demonstrando a grande melhoria de performance.
-   `README.md`: Esta documentação.

## Funcionalidades e Conceitos Aplicados

-   **Inventário (Vetor/Lista Sequencial):** O inventário principal do jogador é um vetor de `structs`. Ideal para um número fixo e pequeno de itens, mas demonstra a ineficiência na inserção e remoção em grandes listas.
-   **Caixa de Loot (Lista Encadeada):** Para fins de comparação, uma caixa de loot no cenário é implementada com lista encadeada, mostrando como a inserção é mais eficiente (O(1)) e como o tamanho pode crescer dinamicamente.
-   **Algoritmos de Ordenação:** Foi implementado o **Selection Sort** (complexidade O(n²)) para ordenar a mochila por nome, um pré-requisito para a busca binária.
-   **Algoritmos de Busca:** O programa utiliza a busca adequada para cada situação:
    -   **Sequencial:** Quando a mochila está desordenada.
    -   **Binária:** Quando a mochila está ordenada, oferecendo uma busca muito mais rápida (complexidade O(log n)). A implementação inclui as versões iterativa e recursiva para fins de estudo.

## Objetivo do Mini-Game

O objetivo final do jogador é sobreviver e escapar da ilha. Para isso, ele deve explorar o mapa para encontrar três itens especiais do tipo `COMPONENTE_TORRE`:
1.  **Placa de Metal**
2.  **Fio de Cobre**
3.  **Bateria**

Uma vez que todos os três componentes estejam na mochila, o jogador pode usar a opção "Construir Torre de Fuga" para vencer o jogo.

## Como Compilar e Executar

Você precisará de um compilador C (como o GCC). No terminal, navegue até a pasta onde os arquivos foram salvos e execute o comando de compilação:

```bash
gcc main.c inventario_vetor.c caixa_loot_lista.c ordenacao.c busca.c -o free_fire_survival
