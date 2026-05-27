typedef struct grafo Grafo;

Grafo* criarGrafo(int numeroVertices);
void cadastrarRotaEntreLocais(Grafo* grafo, int origem, int destino);
void exibirRedeDistribuicao(Grafo* grafo);
void simularEntregaBFS(Grafo* grafo, int origem, int destino);
void calcularMenorRotaDijkstra(Grafo* grafo, int origem, int destino);