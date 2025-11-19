#include <stdio.h>
#include <math.h> 

void calcularPotenciasDeTres() {
    printf("--- Potencias de 3 (expoente 0 a 15) ---\n");
    for (int i = 0; i <= 15; i++) {
        printf("3 elevado a %d e: %.0f\n", i, pow(3, i));
    }
    printf("----------------------------------------\n\n");
}

int main() {
    calcularPotenciasDeTres();
    return 0;
}