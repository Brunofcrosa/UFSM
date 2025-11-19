#include <stdio.h>
#include <limits.h> 

void encontrarMaiorMenor() {
    int valor;
    int maior = INT_MIN; 
    int menor = INT_MAX; 
    int primeiroValor = 1; 

    printf("--- Encontrar Maior e Menor Valor (parar com negativo) ---\n");

    while (1) {
        printf("Digite um valor inteiro positivo (digite um numero negativo para parar): ");
        scanf("%d", &valor);

        if (valor < 0) {
            break;
        }

        if (primeiroValor) {
            maior = valor;
            menor = valor;
            primeiroValor = 0;
        } else {
            if (valor > maior) {
                maior = valor;
            }
            if (valor < menor) {
                menor = valor;
            }
        }
    }

    if (primeiroValor) { 
        printf("Nenhum valor positivo foi digitado.\n");
    } else {
        printf("\nResultados:\n");
        printf("Maior valor digitado: %d\n", maior);
        printf("Menor valor digitado: %d\n", menor);
    }
    printf("----------------------------------------------------------\n\n");
}

int main() {
    encontrarMaiorMenor();
    return 0;
}