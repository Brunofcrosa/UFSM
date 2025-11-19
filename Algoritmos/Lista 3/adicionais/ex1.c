#include <stdio.h>

void exibirIntervaloDecrescente(int num1, int num2) {
    int maior, menor;

    if (num1 > num2) {
        maior = num1;
        menor = num2;
    } else {
        maior = num2;
        menor = num1;
    }

    printf("Numeros no intervalo em ordem decrescente:\n");
    for (int i = maior; i >= menor; i--) {
        printf("%d\n", i);
    }
}

int main() {
    int numeroA, numeroB;

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &numeroA);

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &numeroB);

    exibirIntervaloDecrescente(numeroA, numeroB);

    return 0;
}