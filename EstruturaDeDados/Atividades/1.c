#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 7

void imprimeGrafo(int grafo[N][N], char paginas[N][20]) {
    printf("\n%12s", "");
    for (int k = 0; k < N; k++) {
        printf(" %-10.10s", paginas[k]);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%-12s", paginas[i]);
        for (int j = 0; j < N; j++) {
            printf(" %-10d", grafo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void listarAlcancaveis(int grafo[N][N], char paginas[N][20], int inicio) {
    if (inicio < 0 || inicio >= N) {
        printf("Indice invalido.\n");
        return;
    }

    bool visitado[N];
    for(int i = 0; i < N; i++) visitado[i] = false;

    int fila[N];
    int frente = 0;
    int tras = 0;

    fila[tras++] = inicio;
    visitado[inicio] = true;

    printf("Paginas alcancaveis a partir de '%s':\n", paginas[inicio]);

    bool encontrouAlguma = false;

    while (frente < tras) {
        int atual = fila[frente++];

        for (int i = 0; i < N; i++) {
            if (grafo[atual][i] == 1 && !visitado[i]) {
                visitado[i] = true;
                fila[tras++] = i;
                printf("- %s\n", paginas[i]);
                encontrouAlguma = true;
            }
        }
    }

    if (!encontrouAlguma) {
        printf("(Nenhuma pagina alcancavel)\n");
    }
    printf("\n");
}

void paginasPopulares(int grafo[N][N], char paginas[N][20]) {
    printf("Paginas Populares (Grau de entrada > 1):\n");
    
    for (int j = 0; j < N; j++) {
        int grauEntrada = 0;
        for (int i = 0; i < N; i++) {
            if (grafo[i][j] == 1) {
                grauEntrada++;
            }
        }

        if (grauEntrada > 1) {
            printf("- %s (Entradas: %d)\n", paginas[j], grauEntrada);
        }
    }
    printf("\n");
}

void paginasSemSaida(int grafo[N][N], char paginas[N][20]) {
    printf("Paginas Sem Saida (Grau de saida = 0):\n");
    
    for (int i = 0; i < N; i++) {
        int grauSaida = 0;
        for (int j = 0; j < N; j++) {
            if (grafo[i][j] == 1) {
                grauSaida++;
            }
        }

        if (grauSaida == 0) {
            printf("- %s\n", paginas[i]);
        }
    }
    printf("\n");
}

void verificarConectividade(int grafo[N][N]) {
    bool visitado[N];
    for(int i = 0; i < N; i++) visitado[i] = false;

    int fila[N];
    int frente = 0;
    int tras = 0;

    int inicio = 0;
    fila[tras++] = inicio;
    visitado[inicio] = true;
    int contagemVisitados = 0;

    while (frente < tras) {
        int atual = fila[frente++];
        contagemVisitados++;

        for (int i = 0; i < N; i++) {
            if (!visitado[i]) {
                if (grafo[atual][i] == 1 || grafo[i][atual] == 1) {
                    visitado[i] = true;
                    fila[tras++] = i;
                }
            }
        }
    }

    if (contagemVisitados == N) {
        printf("Conectividade: O grafo E conexo (fracamente conexo).\n");
    } else {
        printf("Conectividade: O grafo NAO E conexo.\n");
    }
    printf("\n");
}

int main() {
    char paginas[N][20] = {
        "Inicio",
        "Categorias",
        "Video",
        "Perfil",
        "Historico",
        "Busca",
        "Config"
    };
    
    int grafo[N][N] = {
        {0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0}
    };
    
    imprimeGrafo(grafo, paginas);
    
    listarAlcancaveis(grafo, paginas, 0); 
    
    paginasPopulares(grafo, paginas);
    
    paginasSemSaida(grafo, paginas);
    
    verificarConectividade(grafo);
    
    return 0;
}