#include <stdio.h>


int contarImpares() { [cite: 3]
    int numero;
    int contadorImpares = 0;

    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numero);
        if (numero % 2 != 0) {
            contadorImpares++;
        }
    }
    return contadorImpares;
}

int main() {
    int totalImpares;

    totalImpares = contarImpares();
    printf("Total de numeros impares digitados: %d\n", totalImpares);

    return 0;
}