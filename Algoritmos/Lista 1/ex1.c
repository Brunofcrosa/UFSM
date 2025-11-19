#include <stdio.h>

void calcularFerraduras() {
    int quantidadeCavalos;
    int totalFerraduras;

    printf("--- Calculo de Ferraduras ---\n");

    printf("Digite a quantidade de cavalos comprados para o haras: ");
    scanf("%d", &quantidadeCavalos);

    if (quantidadeCavalos < 0) {
        printf("A quantidade de cavalos nao pode ser negativa. Por favor, tente novamente.\n");
        return;
    }

    totalFerraduras = quantidadeCavalos * 4;

    printf("Para %d cavalos, sao necessarias %d ferraduras.\n", quantidadeCavalos, totalFerraduras);
    printf("-----------------------------\n\n");
}

int main() {
    calcularFerraduras();
    return 0;
}