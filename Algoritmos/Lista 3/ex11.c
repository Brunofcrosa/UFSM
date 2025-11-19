#include <stdio.h>

void calcularEstatisticasPositivos() {
    float valor;
    float somatorio = 0.0f;
    int totalValores = 0;
    float media = 0.0f;

    printf("--- Calculo de Somatorio, Media e Total (parar com valor negativo) ---\n");

    while (1) { 
        printf("Digite um valor (digite um numero negativo para parar): ");
        scanf("%f", &valor);

        if (valor < 0) {
            break; 
        }

        somatorio += valor;
        totalValores++;
    }

    if (totalValores > 0) {
        media = somatorio / totalValores;
        printf("\nResultados:\n");
        printf("Somatorio dos valores lidos: %.2f\n", somatorio);
        printf("Media dos valores lidos: %.2f\n", media);
        printf("Total de valores lidos: %d\n", totalValores);
    } else {
        printf("Nenhum valor positivo foi digitado.\n");
    }
    printf("--------------------------------------------------------------------\n\n");
}

int main() {
    calcularEstatisticasPositivos();
    return 0;
}