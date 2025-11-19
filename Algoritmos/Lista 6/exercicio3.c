#include <stdio.h>

int main() {
    int matrizA[4][4];
    int matrizB[4][4];
    int matrizC[4][4];
    int i, j;

    printf("Digite os elementos da matriz A (4x4):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("\nDigite os elementos da matriz B (4x4):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    printf("\nMatriz C (Soma de A e B):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d\t", matrizC[i][j]);
        }
        printf("\n");
    }

    return 0;
}