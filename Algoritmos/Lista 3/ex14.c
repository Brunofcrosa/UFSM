#include <stdio.h>

void analisarNumeros() {
    int numero;
    int contadorNegativos = 0;
    float somatorioPositivos = 0.0f;
    int contadorPositivos = 0;
    float mediaPositivos = 0.0f;

    printf("--- Analise de Numeros (digite 0 para parar) ---\n");

    while (1) {
        printf("Digite um numero inteiro (digite 0 para parar): ");
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        if (numero < 0) {
            contadorNegativos++;
        } else { 
            somatorioPositivos += numero;
            contadorPositivos++;
        }
    }

    if (contadorPositivos > 0) {
        mediaPositivos = somatorioPositivos / contadorPositivos;
    }

    printf("\nResultados:\n");
    printf("Quantidade de numeros negativos digitados: %d\n", contadorNegativos);
    if (contadorPositivos > 0) {
        printf("Media aritmetica dos numeros maiores que zero: %.2f\n", mediaPositivos);
    } else {
        printf("Nenhum numero maior que zero foi digitado para calcular a media.\n");
    }
    printf("-------------------------------------------------\n\n");
}

int main() {
    analisarNumeros();
    return 0;
}