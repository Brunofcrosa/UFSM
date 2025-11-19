#include <stdio.h>
#include <string.h>

void calcularDiasDeVida() {
    char nome[50];
    int idade;
    long long diasDeVida;

    printf("--- Calculo de Dias de Vida ---\n");

    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]%*c", nome);

    printf("Digite a idade da pessoa (em anos completos): ");
    scanf("%d", &idade);

    if (idade < 0) {
        printf("A idade nao pode ser negativa. Por favor, tente novamente.\n");
        return;
    }

    diasDeVida = (long long)idade * 365;

    printf("%s, VOCE JA VIVEU %lld DIAS\n", nome, diasDeVida);
    printf("-------------------------------\n\n");
}

int main() {
    calcularDiasDeVida();
    return 0;
}