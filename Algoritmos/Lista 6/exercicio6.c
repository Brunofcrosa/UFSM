#include <stdio.h>

int main() {
    int matriz[5][5];
    int i, j;

    printf("Digite os elementos da matriz 5x5:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nElementos acima da diagonal secundária:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {

            if (i + j < 4) {
                printf("%d\t", matriz[i][j]);
            } else {
                printf(" \t"); 
            }
        }
        printf("\n");
    }

    return 0;
}