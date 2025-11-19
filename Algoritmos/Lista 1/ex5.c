#include <stdio.h>

void calcularValorRestaurante() {
    float pesoPratoKg;
    float precoPorQuilo = 12.00f;
    float valorAPagar;

    printf("--- Restaurante Bem-Bao (por quilo) ---\n");

    printf("Digite o peso do prato montado (em kg): ");
    scanf("%f", &pesoPratoKg);

    if (pesoPratoKg < 0) {
        printf("O peso do prato nao pode ser negativo. Por favor, tente novamente.\n");
        return;
    }

    valorAPagar = pesoPratoKg * precoPorQuilo;

    printf("O valor a pagar pelo seu prato e: R$ %.2f\n", valorAPagar);
    printf("----------------------------------------\n\n");
}

int main() {
    calcularValorRestaurante();
    return 0;
}