#include <stdio.h>

void lerValoresAtePrimeiroMenorQueSegundo() {
    int valor1, valor2;

    do {
        printf("Digite o primeiro valor inteiro: ");
        scanf("%d", &valor1);

        printf("Digite o segundo valor inteiro: ");
        scanf("%d", &valor2);

        if (valor1 >= valor2) {
            printf("O primeiro valor nao e menor que o segundo. Tente novamente.\n");
        }
    } while (valor1 >= valor2);

    printf("Condicao atingida: o primeiro valor (%d) e menor que o segundo valor (%d).\n", valor1, valor2);
}

int main() {
    lerValoresAtePrimeiroMenorQueSegundo();
    return 0;
}