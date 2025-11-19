#include <stdio.h>

int main() {
    int matrizA[5][5];
    int matrizB[5][5];
    int i, j;

    printf("Digite os elementos da matriz A (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == j) { // Diagonal principal
                matrizB[i][j] = matrizA[i][j] * 3;
            } else {
                matrizB[i][j] = matrizA[i][j] * 2;
            }
        }
    }

    printf("\nMatriz B:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", matrizB[i][j]);
        }
        printf("\n");
    }

    return 0;
}