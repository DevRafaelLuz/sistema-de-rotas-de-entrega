#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#define MAX_VERTICES 5 // Valor temporário para testes.


// Função para exibir o menu
void exibirMenu(Grafo* grafo) {
    int opcao;
    do {
        printf("+-----------------------------------+\n");
        printf("|    Sistema de Rotas de Entrega    |\n");
        printf("+-----------------------------------+\n");
        printf("| 1. Cadastrar rota entre locais    |\n");
        printf("| 2. Exibir rede de distribuicao    |\n");
        printf("| 3. Simular entrega (BFS)          |\n");
        printf("| 4. Calcular menor rota (Dijkstra) |\n");
        printf("| 5. Sair                           |\n");
        printf("+-----------------------------------+\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // cadastrarRotaEntreLocais(grafo, origem, destino);
                break;
            case 2:
                // exibirRedeDistribuicao(grafo);
                break;
            case 3:
                // simularEntregaBFS(grafo, origem, destino);
                break;
            case 4:
                // calcularMenorRotaDijkstra(grafo, origem, destino);
                break;
            case 5:
                printf("Fechando sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao < 1 || opcao > 5);
}

int main() {
    Grafo* grafo = criarGrafo(MAX_VERTICES);
    exibirMenu(grafo); //Chama a função para exibir o menu

    liberarGrafo(grafo);

    return 0;
}