#include <stdio.h>

int main() {
    int matrizA[5][5];
    int matrizB[5][5];
    int matrizC[5][5];
    int i, j, k, l;
    int encontrado;

    printf("Digite os elementos da matriz A (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("\nDigite os elementos da matriz B (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            encontrado = 0; 
            for (k = 0; k < 5; k++) {
                for (l = 0; l < 5; l++) {
                    if (matrizA[i][j] == matrizB[k][l]) {
                        encontrado = 1;
                        break; 
                    }
                }
                if (encontrado) {
                    break; 
                }
            }
            matrizC[i][j] = encontrado;
        }
    }

    printf("\nMatriz C:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", matrizC[i][j]);
        }
        printf("\n");
    }

    return 0;
}