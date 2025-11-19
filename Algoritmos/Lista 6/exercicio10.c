#include <stdio.h>

int main() {
    int vetorA[5];
    int vetorB[5];
    int matrizC[5][2];
    int i;

    printf("Digite os 5 elementos do vetor A:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &vetorA[i]);
    }

    printf("\nDigite os 5 elementos do vetor B:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &vetorB[i]);
    }

    for (i = 0; i < 5; i++) {
        matrizC[i][0] = vetorA[i]; // Primeira coluna com elementos de A
        matrizC[i][1] = vetorB[i]; // Segunda coluna com elementos de B
    }

    printf("\nMatriz C:\n");
    for (i = 0; i < 5; i++) {
        printf("%d\t%d\n", matrizC[i][0], matrizC[i][1]);
    }

    return 0;
}