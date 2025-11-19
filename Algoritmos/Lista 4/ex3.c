#include <stdio.h>


void trocar(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}


void ordenarValores(int *a, int *b, int *c) { [cite: 4]

    if (*a < *b) {
        trocar(a, b);
    }
    if (*a < *c) {
        trocar(a, c);
    }


    if (*c > *b) {
        trocar(c, b);
    }
}

int main() {
    int valorA, valorB, valorC;

    printf("Digite o valor para A: ");
    scanf("%d", &valorA);
    printf("Digite o valor para B: ");
    scanf("%d", &valorB);
    printf("Digite o valor para C: ");
    scanf("%d", &valorC);

    printf("Valores antes da ordenacao: A = %d, B = %d, C = %d\n", valorA, valorB, valorC);

    ordenarValores(&valorA, &valorB, &valorC);

    printf("Valores depois da ordenacao: A (maior) = %d, B (medio) = %d, C (menor) = %d\n", valorA, valorB, valorC);

    return 0;
}