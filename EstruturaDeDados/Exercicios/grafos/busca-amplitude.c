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

void amplitude(No* grafo[], int inicio, int numVertices) {
    int fila[VERTICES];
    int head = 0; 
    int tail = 0; 

    int visitados[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visitados[i] = 0; 
    }
    
    if (inicio < 0 || inicio >= numVertices) {
        printf("Erro: Vertice inicial invalido.\n");
        return;
    }

    fila[tail++] = inicio;
    visitados[inicio] = 1; 
    printf("busca por amplitude a partir do Vertice %d: ", inicio);

    while (head != tail) {
        int atual = fila[head++];
        printf("%d ", atual); 

        No* vizinho = grafo[atual];
        while (vizinho != NULL) {
            int idVizinho = vizinho->idVizinho;

            if (!visitados[idVizinho]) {
                visitados[idVizinho] = 1; 
                if (tail < VERTICES) {
                    fila[tail++] = idVizinho;
                } else {
                    printf("\nErro: Fila cheia - Algoritmo não foi concluído.\n");
                    return;
                }
            }
            vizinho = vizinho->proximo;
        }
    }
    printf("NULL\n");
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

	amplitude(grafo, 0, VERTICES);
	amplitude(grafo, 1, VERTICES);
	amplitude(grafo, 3, VERTICES);
	
    return 0;
}