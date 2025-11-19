// Grafo Não-Orientado com Matriz de Adjacênci
#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTICES 6
#define MAX_FILA NUM_VERTICES

typedef struct Grafo {
    int numVertices;
    int matrizAdj[NUM_VERTICES][NUM_VERTICES];
} Grafo;

typedef struct Fila {
    int itens[MAX_FILA];
    int frente;
    int tras;
    int tamanho;
} Fila;

Grafo* criaGrafo() {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    if (grafo == NULL) {
        exit(EXIT_FAILURE);
    }
    grafo->numVertices = NUM_VERTICES;

    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            grafo->matrizAdj[i][j] = 0;
        }
    }
    return grafo;
}

void adicionaAresta(Grafo* grafo, int u, int v) {
    if (u >= 0 && u < grafo->numVertices && v >= 0 && v < grafo->numVertices) {
        grafo->matrizAdj[u][v] = 1;
        grafo->matrizAdj[v][u] = 1;
    }
}

void imprimeMatrizAdj(Grafo* grafo) {
    printf("  ");
    for (int i = 0; i < grafo->numVertices; i++) {
        printf(" %d", i);
    }
    printf("\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        printf("%d:", i);
        for (int j = 0; j < grafo->numVertices; j++) {
            printf(" %d", grafo->matrizAdj[i][j]);
        }
        printf("\n");
    }
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

    for (int v = 0; v < grafo->numVertices; v++) {
        if (grafo->matrizAdj[atual][v] == 1 && !visitados[v]) {
            dfs(grafo, v, visitados);
        }
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

        for (int v = 0; v < grafo->numVertices; v++) {
            if (grafo->matrizAdj[atual][v] == 1 && !visitados[v]) {
                visitados[v] = 1;
                printf("%d ", v);
                incluir(&f, v);
            }
        }
    }
}

int main() {
    Grafo* meuGrafo = criaGrafo();

    adicionaAresta(meuGrafo, 0, 1);
    adicionaAresta(meuGrafo, 0, 2);
    adicionaAresta(meuGrafo, 1, 3);
    adicionaAresta(meuGrafo, 2, 4);
    adicionaAresta(meuGrafo, 3, 5);

    printf("Grafo de exemplo (Matriz de Adjacencia, Nao-Orientado): Vertices 0 a 5\n");
    printf("\n");
    imprimeMatrizAdj(meuGrafo);
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

    free(meuGrafo);

    return 0;
}