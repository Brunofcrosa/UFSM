#include <stdio.h>

void calcularQuadrados() {
    printf("--- Quadrado dos numeros de 15 a 100 ---\n");
    for (int i = 15; i <= 100; i++) {
        printf("O quadrado de %d e %d\n", i, i * i);
    }
    printf("-----------------------------------------\n\n");
}

int main() {
    calcularQuadrados();
    return 0;
}