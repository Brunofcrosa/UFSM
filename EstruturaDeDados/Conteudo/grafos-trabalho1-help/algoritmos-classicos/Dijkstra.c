#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

#define VERTICES 5
#define INFINITO INT_MAX

// --- 1. ESTRUTURA PONDERADA (Lista de Adjacência com Peso) ---
typedef struct No {
    int verticeDestino;
    int peso;             // Novo campo para o peso/custo da aresta
    struct No* proximo;
} No;

// Criação de Aresta adaptada para incluir o peso
void criarAresta(No* grafo[], int origem, int destino, int peso) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria.\n");
        return;
    }
    novo->verticeDestino = destino;
    novo->peso = peso; // Armazena o peso
    novo->proximo = grafo[origem];
    grafo[origem] = novo;
}


// --- FUNÇÃO AUXILIAR PARA ENCONTRAR O PRÓXIMO VÉRTICE ---
// Simula a lógica da Fila de Prioridade:
// Encontra o vértice não visitado com a MENOR distância atual.
int encontrarMenorDistancia(int distancias[], int visitado[], int numVertices) {
    int min = INFINITO;
    int indiceMenor = -1;

    for (int v = 0; v < numVertices; v++) {
        // Verifica se: 1) Não foi visitado, E 2) Tem distância menor que o mínimo atual
        if (visitado[v] == 0 && distancias[v] <= min) {
            min = distancias[v];
            indiceMenor = v;
        }
    }
    return indiceMenor;
}

// 2. ALGORITMO DE DIJKSTRA (Busca do Menor Caminho)
void dijkstra(No* grafo[], int numVertices, int origem) {
    // Array para armazenar a menor distância da origem para cada vértice
    int distancias[numVertices]; 
    
    // Array para marcar se o vértice já foi processado (0=Falso, 1=Verdadeiro)
    int visitado[numVertices]; 

    // Inicialização
    for (int i = 0; i < numVertices; i++) {
        distancias[i] = INFINITO; // Todas as distâncias são infinitas inicialmente
        visitado[i] = 0;          // Ninguém foi visitado
    }

    // A distância da origem para ela mesma é zero
    distancias[origem] = 0;

    // Repete para todos os vértices (o loop externo deve rodar numVertices vezes)
    for (int count = 0; count < numVertices - 1; count++) {
        // Encontra o vértice U não visitado com a menor distância (simulando Priority Queue)
        int u = encontrarMenorDistancia(distancias, visitado, numVertices);

        // Se 'u' for -1 (ou INFINITO), o resto do grafo é inalcançável.
        if (u == -1) break; 
        
        // Marca o vértice U como visitado/processado
        visitado[u] = 1;

        // Itera sobre todos os vizinhos (v) de U
        No* adjacente = grafo[u];
        while (adjacente != NULL) {
            int v = adjacente->verticeDestino;
            int peso_aresta = adjacente->peso;

            // Processo de RELAXAMENTO:
            // Se V não foi visitado E a distância para U é finita E 
            // o caminho através de U é menor que a distância registrada para V:
            if (visitado[v] == 0 && 
                distancias[u] != INFINITO && 
                distancias[u] + peso_aresta < distancias[v]) {
                
                // Atualiza a distância para V
                distancias[v] = distancias[u] + peso_aresta;
            }
            adjacente = adjacente->proximo;
        }
    }

    // Impressão do resultado
    printf("\n--- Menor Caminho a partir da Origem %d (DIJKSTRA) ---\n", origem);
    for (int i = 0; i < numVertices; i++) {
        if (distancias[i] == INFINITO) {
            printf("Vertice %d: Inalcancavel\n", i);
        } else {
            printf("Vertice %d: %d\n", i, distancias[i]);
        }
    }
    printf("------------------------------------------------------\n");
}


// 3. FUNÇÕES DE LIMPEZA E MAIN (Adaptadas)

void desalocarGrafo(No* grafo[], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        No* atual = grafo[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp); 
        }
        grafo[i] = NULL; 
    }
    printf("Memoria do grafo desalocada com sucesso.\n");
}

int main() {
    No* grafo[VERTICES]; 

    // Inicialização
    for (int i = 0; i < VERTICES; i++) {
        grafo[i] = NULL; 
    }

    // CRIAÇÃO DE CONEXÕES PONDERADAS (Origem, Destino, Peso)
    // Exemplo do livro: 
    // 0 -> 1 (Peso 10), 0 -> 4 (Peso 5)
    // 1 -> 2 (Peso 1), 1 -> 4 (Peso 2)
    // 2 -> 3 (Peso 4)
    // 3 -> 2 (Peso 6)
    // 4 -> 1 (Peso 3), 4 -> 2 (Peso 9), 4 -> 3 (Peso 2)
    
    criarAresta(grafo, 0, 1, 10);
    criarAresta(grafo, 0, 4, 5);
    criarAresta(grafo, 1, 2, 1);
    criarAresta(grafo, 1, 4, 2);
    criarAresta(grafo, 2, 3, 4);
    criarAresta(grafo, 3, 2, 6);
    criarAresta(grafo, 4, 1, 3);
    criarAresta(grafo, 4, 2, 9);
    criarAresta(grafo, 4, 3, 2); 

    // 4. EXECUÇÃO DO DIJKSTRA
    dijkstra(grafo, VERTICES, 0); 

    // 5. LIMPEZA
    desalocarGrafo(grafo, VERTICES);
    
    return 0;
}