// 1. Dígrafo Ponderado (Grafo Orientado com Pesos)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_VERTICES 5
#define MAX_FILA NUM_VERTICES

typedef struct NoAdj {
    int idDestino;
    int peso;
    struct NoAdj* prox;
} NoAdj;

typedef struct Grafo {
    int numVertices;
    NoAdj** adj;
} Grafo;

typedef struct Fila {
    int itens[MAX_FILA];
    int frente;
    int tras;
    int tamanho;
} Fila;

NoAdj* criaNoAdj(int idDestino, int peso) {
    NoAdj* novoNo = (NoAdj*)malloc(sizeof(NoAdj));
    if (novoNo == NULL) {
        exit(EXIT_FAILURE);
    }
    novoNo->idDestino = idDestino;
    novoNo->peso = peso;
    novoNo->prox = NULL;
    return novoNo;
}

Grafo* criaGrafo(int numVertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    if (grafo == NULL) {
        exit(EXIT_FAILURE);
    }
    grafo->numVertices = numVertices;
    grafo->adj = (NoAdj**)malloc(numVertices * sizeof(NoAdj*));
    if (grafo->adj == NULL) {
        free(grafo);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numVertices; i++) {
        grafo->adj[i] = NULL;
    }
    return grafo;
}

void adicionaArcoPonderado(Grafo* grafo, int origem, int destino, int peso) {
    NoAdj* novoNo = criaNoAdj(destino, peso);
    novoNo->prox = grafo->adj[origem];
    grafo->adj[origem] = novoNo;
}

void liberaGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        NoAdj* atual = grafo->adj[i];
        NoAdj* prox;
        while (atual != NULL) {
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }
    free(grafo->adj);
    free(grafo);
}

void inicializaFila(Fila* f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int filaVazia(Fila* f) {
    return f->tamanho == 0;
}

void incluir(Fila* f, int item) {
    if (f->tamanho == MAX_FILA) {
        return;
    }
    f->tras = (f->tras + 1) % MAX_FILA;
    f->itens[f->tras] = item;
    f->tamanho++;
}

int retirar(Fila* f) {
    if (filaVazia(f)) {
        return -1;
    }
    int item = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX_FILA;
    f->tamanho--;
    return item;
}

void dfs(Grafo* grafo, int atual, int visitados[]) {
    visitados[atual] = 1;
    printf("%d ", atual);

    NoAdj* vizinho = grafo->adj[atual];
    while (vizinho != NULL) {
        int v = vizinho->idDestino;
        if (!visitados[v]) {
            dfs(grafo, v, visitados);
        }
        vizinho = vizinho->prox;
    }
}

void bfs(Grafo* grafo, int inicio) {
    int visitados[grafo->numVertices];
    for (int i = 0; i < grafo->numVertices; i++) {
        visitados[i] = 0;
    }

    Fila f;
    inicializaFila(&f);

    visitados[inicio] = 1;
    printf("%d ", inicio);
    incluir(&f, inicio);

    while (!filaVazia(&f)) {
        int atual = retirar(&f);

        NoAdj* vizinho = grafo->adj[atual];
        while (vizinho != NULL) {
            int v = vizinho->idDestino;
            if (!visitados[v]) {
                visitados[v] = 1;
                printf("%d ", v);
                incluir(&f, v);
            }
            vizinho = vizinho->prox;
        }
    }
}

void imprimeGrafoPonderado(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        NoAdj* no = grafo->adj[i];
        printf("Lista de adjacencia do vertice %d (saidas):", i);
        while (no) {
            printf(" -> %d (peso: %d)", no->idDestino, no->peso);
            no = no->prox;
        }
        printf("\n");
    }
}

int main() {
    Grafo* meuGrafo = criaGrafo(NUM_VERTICES);

    adicionaArcoPonderado(meuGrafo, 0, 1, 10);
    adicionaArcoPonderado(meuGrafo, 0, 2, 5);
    adicionaArcoPonderado(meuGrafo, 1, 3, 20);
    adicionaArcoPonderado(meuGrafo, 2, 3, 5);
    adicionaArcoPonderado(meuGrafo, 3, 4, 3);
    adicionaArcoPonderado(meuGrafo, 4, 0, 15);

    printf("Grafo de exemplo (Orientado e Ponderado): Vertices 0 a 4\n");
    printf("\n");
    imprimeGrafoPonderado(meuGrafo);
    printf("\n");

    int visitadosDFS[NUM_VERTICES];
    for (int i = 0; i < NUM_VERTICES; i++) {
        visitadosDFS[i] = 0;
    }
    printf("Percurso em Profundidade (DFS) a partir do no 0:\n");
    dfs(meuGrafo, 0, visitadosDFS);
    printf("\n");

    printf("Percurso em Amplitude (BFS) a partir do no 0:\n");
    bfs(meuGrafo, 0);
    printf("\n");

    liberaGrafo(meuGrafo);

    return 0;
}