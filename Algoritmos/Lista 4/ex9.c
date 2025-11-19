#include <stdio.h>


float adicao(float num1, float num2);
float subtracao(float num1, float num2);
float multiplicacao(float num1, float num2);
float divisao(float num1, float num2);

int main() {
    int opcao;
    float numero1, numero2, resultado;

    do {
        printf("\n--- Calculadora ---\n"); [cite: 17]
        printf("1 - Adicao\n"); [cite: 18]
        printf("2 - Subtracao\n"); [cite: 18]
        printf("3 - Multiplicacao\n"); [cite: 18]
        printf("4 - Divisao\n"); [cite: 18]
        printf("0 - Sair\n"); [cite: 18]
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            printf("Digite o primeiro numero: ");
            scanf("%f", &numero1);
            printf("Digite o segundo numero: ");
            scanf("%f", &numero2);
        }

        switch (opcao) {
            case 1:
                resultado = adicao(numero1, numero2);
                printf("Resultado da adicao: %.2f\n", resultado);
                break;
            case 2:
                resultado = subtracao(numero1, numero2);
                printf("Resultado da subtracao: %.2f\n", resultado);
                break;
            case 3:
                resultado = multiplicacao(numero1, numero2);
                printf("Resultado da multiplicacao: %.2f\n", resultado);
                break;
            case 4:
                if (numero2 != 0) {
                    resultado = divisao(numero1, numero2);
                    printf("Resultado da divisao: %.2f\n", resultado);
                } else {
                    printf("Erro: Divisao por zero nao e permitida.\n");
                }
                break;
            case 0:
                printf("Encerrando o programa da calculadora.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

float adicao(float num1, float num2) {
    return num1 + num2;
}

float subtracao(float num1, float num2) {
    return num1 - num2;
}

float multiplicacao(float num1, float num2) {
    return num1 * num2;
}

float divisao(float num1, float num2) {

    return num1 / num2;
}