#include <stdio.h>
#include <stdlib.h>
#define VERTICES 5
typedef struct No {
    int idVizinho;
    struct No* proximo;
} No;

void criarAresta(No* grafo[], int origem, int destino) {
    No* novo = (No*) malloc(sizeof(No));
    novo->idVizinho = destino;
    
    novo->proximo = grafo[origem]; 
    grafo[origem] = novo; 
}

void imprimirGrafo(No* grafo[], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        printf("Vertice %d: ", i);
        No* atual = grafo[i];
        while (atual != NULL) {
            printf("%d -> ", atual->idVizinho);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}
void profundidade(No* grafo[], int atual, int visitados[], int totalNos) {
    printf("%d ", atual);
    visitados[atual] = 1;

    No* vizinho = grafo[atual];
    while (vizinho != NULL) {
        int idVizinho = vizinho->idVizinho;
        
        if (!visitados[idVizinho]) {
            profundidade(grafo, idVizinho, visitados, totalNos);
        }
        vizinho = vizinho->proximo;
    }
}

void iniciarProfundidade(No* grafo[], int inicio, int totalNos) {
    int visitados[totalNos];
    for (int i = 0; i < totalNos; i++) {
        visitados[i] = 0;
    }
    
    printf("\nBusca em Profundidade a partir do vertice %d:\n", inicio);
    profundidade(grafo, inicio, visitados, totalNos);
    printf("\n");
}


int main() {
    No* grafo[VERTICES]; 

    for (int i = 0; i < VERTICES; i++) {
        grafo[i] = NULL;
    }
    criarAresta(grafo, 0, 1);
    criarAresta(grafo, 0, 4);
    criarAresta(grafo, 1, 2);
    criarAresta(grafo, 3, 2);
    criarAresta(grafo, 3, 4);
	iniciarProfundidade(grafo, 0, 5);
	iniciarProfundidade(grafo, 1, 5);
	
    return 0;
}