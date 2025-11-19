#include <stdio.h>

void verificarPrimo() {
    int numero;
    int ehPrimo = 1; 

    printf("--- Verificacao de Numero Primo ---\n");

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 1) {
        ehPrimo = 0; 
    } else if (numero == 2) {
        ehPrimo = 1; 
    } else if (numero % 2 == 0) {
        ehPrimo = 0; 
    } else {
        
        for (int i = 3; i * i <= numero; i += 2) {
            if (numero % i == 0) {
                ehPrimo = 0; 
                break;
            }
        }
    }

    if (ehPrimo) {
        printf("%d e um numero primo.\n", numero);
    } else {
        printf("%d nao e um numero primo.\n", numero);
    }
    printf("-----------------------------------\n\n");
}

int main() {
    verificarPrimo();
    return 0;
}