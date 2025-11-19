#include <stdio.h>
#include <stdlib.h>

struct NoAdj {
	int id_destino;
	struct NoAdj* prox;
};

struct Grafo {
	int numVertices;
	struct NoAdj** adj;
};

struct NoAdj* criarNo(int destino) {
	struct NoAdj* novoNo = (struct NoAdj*) malloc(sizeof(struct NoAdj));
	novoNo->id_destino = destino;
	novoNo->prox = NULL;
	return novoNo;
}

struct Grafo* criarGrafo(int numVertices) {
	int i;
	struct Grafo* grafo = (struct Grafo*) malloc(sizeof(struct Grafo));
	grafo->numVertices = numVertices;
	
	grafo->adj = (struct NoAdj**) malloc(numVertices * sizeof(struct NoAdj*));
	
	for(i=0; i< numVertices; i++) {
		grafo->adj[i] = NULL;
	}
	return grafo;
}

void adicionarAresta(struct Grafo* grafo, int origem, int destino) {
	struct NoAdj* novoNo = criarNo(destino);
	novoNo->prox = grafo->adj[origem];
	grafo->adj[origem] = novoNo;
	
	novoNo = criarNo(origem);
	novoNo->prox = grafo->adj[destino];
	grafo->adj[destino] = novoNo;
}

void imprimirGrafo(struct Grafo* grafo) {
	int i;
	for(i=0; i < grafo-> numVertices; i++) {
		struct NoAdj* temp = grafo->adj[i];
		printf("Vertice %d: ", i);
		while (temp) {
			printf("%d -> ", temp->id_destino);
			temp = temp->prox;
		}
		printf("NULL\n");
	}
}


void liberar(struct Grafo* grafo) {
	int i;
    for (i = 0; i < grafo->numVertices; i++) {
        struct NoAdj* atual = grafo->adj[i];
        while (atual) {
            struct NoAdj* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(grafo->adj);
    free(grafo);
}

int main() {
    int numVertices = 6;
    struct Grafo* grafo = criarGrafo(numVertices);
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 5);
    imprimirGrafo(grafo);
    liberar(grafo);
    return 0;
}