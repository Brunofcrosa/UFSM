#include <stdio.h>

int main() {
    int matriz[3][4];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            matriz[i][j] = i + j;
        }
    }

    printf("Matriz 3x4 com elementos = soma dos índices:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}