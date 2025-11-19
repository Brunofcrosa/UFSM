#include <stdio.h>

int main() {
    int matrizOriginal[2][3];
    int matrizTransposta[3][2];
    int i, j;

    printf("Digite os elementos da matriz 2x3:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrizOriginal[i][j]);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            matrizTransposta[j][i] = matrizOriginal[i][j];
        }
    }

    printf("\nMatriz Transposta:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", matrizTransposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}