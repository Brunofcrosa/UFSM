#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_VERTICES 6
#define MAX_FILA NUM_VERTICES

typedef struct NoAdj {
    int idDestino;
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

NoAdj* criaNoAdj(int idDestino) {
    NoAdj* novoNo = (NoAdj*)malloc(sizeof(NoAdj));
    if (novoNo == NULL) {
        exit(EXIT_FAILURE);
    }
    novoNo->idDestino = idDestino;
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

void adicionaAresta(Grafo* grafo, int u, int v) {
    NoAdj* novoNoU = criaNoAdj(v);
    novoNoU->prox = grafo->adj[u];
    grafo->adj[u] = novoNoU;

    NoAdj* novoNoV = criaNoAdj(u);
    novoNoV->prox = grafo->adj[v];
    grafo->adj[v] = novoNoV;
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

int main() {
    Grafo* meuGrafo = criaGrafo(NUM_VERTICES);

    adicionaAresta(meuGrafo, 0, 1);
    adicionaAresta(meuGrafo, 0, 2);
    adicionaAresta(meuGrafo, 0, 3);
    adicionaAresta(meuGrafo, 1, 4);
    adicionaAresta(meuGrafo, 2, 5);
    adicionaAresta(meuGrafo, 4, 5);

    printf("Grafo de exemplo (Nao-Orientado, 6 vertices): Vertices 0 a 5\n");
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