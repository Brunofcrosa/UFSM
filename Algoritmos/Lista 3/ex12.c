#include <stdio.h>

void calcularFatorial() {
    int numero;
    long long fatorial = 1; 

    printf("--- Calculo de Fatorial ---\n");

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Fatorial nao definido para numeros negativos. Por favor, digite um numero positivo.\n");
        return;
    }

    if (numero == 0) {
        fatorial = 1; 
    } else {
        for (int i = 1; i <= numero; i++) {
            fatorial *= i;
        }
    }

    printf("O fatorial de %d e: %lld\n", numero, fatorial);
    printf("---------------------------\n\n");
}

int main() {
    calcularFatorial();
    return 0;
}