#include <stdio.h>

void contarImpares() {
    int numero;
    int contadorImpares = 0;

    printf("--- Contagem de Numeros Impares (digite -999 para parar) ---\n");
    do {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero == -999) {
            break;
        }

        if (numero % 2 != 0) {
            contadorImpares++;
        }
    } while (1); 

    printf("Total de numeros impares digitados: %d\n", contadorImpares);
    printf("----------------------------------------------------------\n\n");
}

int main() {
    contarImpares();
    return 0;
}