#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo {
    int numeroVertices;
    int** matrizAdjacencia;
};


Grafo* criarGrafo(int numeroVertices){

    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numeroVertices = numeroVertices;
 
    //Aloca linhas da matriz
    grafo->matrizAdjacencia = (int**)malloc(numeroVertices * sizeof(int*));
 
    //Aloca cada coluna e inicia com 0
    for (int i = 0; i < numeroVertices; i++) {
        grafo->matrizAdjacencia[i] = (int*)calloc(numeroVertices, sizeof(int));
    }
 
    return grafo;
}

void liberarGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numeroVertices; i++) {
        free(grafo->matrizAdjacencia[i]);
    }
    free(grafo->matrizAdjacencia);
    free(grafo);
}

void cadastrarRotaEntreLocais(Grafo* grafo, int origem, int destino, int peso){
    if (origem < 0 || origem >= grafo->numeroVertices || destino < 0 || destino >= grafo->numeroVertices){
        printf("Local invalido.\n");
        return;
    }
 
    grafo->matrizAdjacencia[origem][destino] = peso;
    grafo->matrizAdjacencia[destino][origem] = peso;    
 
    printf("Rota cadastrada: %d <-> %d (peso: %d)\n", origem, destino, peso);
}

// TODO: Implementar o resto das funções declaradas em grafo.h

// Função para exibir a rede de distribuição
void exibirRedeDistribuicao(Grafo* grafo) {
    printf("+-----------------------------------+\n");
    printf("|        Rede de Distribuicao       |\n");
    printf("+-----------------------------------+\n");

    if (grafo->numeroVertices == 0) {
        printf("Nenhuma rota cadastrada!\n");
        return;
    } else {
        for (int i = 0; i < grafo->numeroVertices; i++) {
            for (int j = 0; j < grafo->numeroVertices; j++) {
                if (grafo->matrizAdjacencia[i][j] != 0) {
                    printf("Rota: %d <-> %d (peso: %d)\n", i, j, grafo->matrizAdjacencia[i][j]);
                }
            }
        }
    }
}

// Função para simular a entrega usando BFS
void simularEntregaBFS(Grafo* grafo, int origem, int destino) {
    printf("Simulacao de entrega (BFS) entre %d e %d\n", origem, destino);
    if (origem < 0 || origem >= grafo->numeroVertices || destino < 0 || destino >= grafo->numeroVertices) {
        printf("Local invalido.\n");
        return;
    }

    // Implementar BFS para simular a entrega
    // Para simplicidade, apenas exibiremos os locais visitados durante a simulação
    int visitado[grafo->numeroVertices];
    for (int i = 0; i < grafo->numeroVertices; i++) {
        visitado[i] = 0;
    }

    // Fila para BFS
    int fila[grafo->numeroVertices];
    int inicioFila = 0, fimFila = 0;

    // Enfileirar o ponto de origem
    fila[fimFila++] = origem;
    visitado[origem] = 1;

    printf("Percurso BFS: ");
    while (inicioFila < fimFila) {
        int atual = fila[inicioFila++];
        printf("%d ", atual);

        if (atual == destino) {
            printf("\nDestino %d alcancado!\n", destino);
            return;
        }

        for (int j = 0; j < grafo->numeroVertices; j++) {
            if (grafo->matrizAdjacencia[atual][j] != 0 && !visitado[j]) {
                fila[fimFila++] = j;
                visitado[j] = 1;
            }
        }
    }

    printf("\nDestino %d nao alcancado!\n", destino);
}
// void calcularMenorRotaDijkstra(Grafo* grafo, int origem, int destino) { }