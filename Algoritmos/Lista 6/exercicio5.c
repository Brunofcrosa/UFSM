#include <stdio.h>

int main() {
    float alturas[5][10];
    int i, j;
    float maiorAltura;

    printf("Digite as alturas dos atletas para 5 delegações (10 atletas por delegação):\n");
    for (i = 0; i < 5; i++) {
        printf("Delegação %d:\n", i + 1);
        for (j = 0; j < 10; j++) {
            printf("Altura do atleta %d: ", j + 1);
            scanf("%f", &alturas[i][j]);
        }
    }

    printf("\nMaiores alturas por delegação:\n");
    for (i = 0; i < 5; i++) {
        maiorAltura = alturas[i][0]; 
        for (j = 1; j < 10; j++) {
            if (alturas[i][j] > maiorAltura) {
                maiorAltura = alturas[i][j];
            }
        }
        printf("Delegação %d: %.2f\n", i + 1, maiorAltura);
    }

    return 0;
}