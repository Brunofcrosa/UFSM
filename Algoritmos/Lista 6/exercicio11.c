#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

int main() {
    int matrizA[4][5];
    int matrizB[4][5];
    int matrizC[4][5];
    int i, j;
    int valor;

    srand(time(NULL)); 

    printf("Preenchendo Matriz A (divisíveis por 3 e 4):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            do {
                valor = rand() % 1000 + 1; 
            } while (valor % 3 != 0 || valor % 4 != 0); 
            matrizA[i][j] = valor;
            printf("%d\t", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\nPreenchendo Matriz B (divisíveis por 5 e 6):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            do {
                valor = rand() % 1000 + 1; 
            } while (valor % 5 != 0 || valor % 6 != 0); 
            matrizB[i][j] = valor;
            printf("%d\t", matrizB[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz C (A - B):\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            matrizC[i][j] = matrizA[i][j] - matrizB[i][j];
            printf("%d\t", matrizC[i][j]);
        }
        printf("\n");
    }

    return 0;
}