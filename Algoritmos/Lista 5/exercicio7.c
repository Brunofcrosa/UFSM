/**7. Faça um algoritmo com uma função para criar um vetor de 20 posições. As primeiras 10 posições são
valores informados pelo usuário, as últimas 10 posições deverão ter valores que obedecem a seguinte
regra: os valores de posições ímpares da primeira metade deverão ser acrescidos de 5 % na segunda
metade. E, os valores pares da primeira metade deverão ser acrescidos de 2% na segunda metade. Ex.:
Vet[0] = 10, logo, Vet[10] = 10 + 2%.
**/
#include <stdio.h>

void preencherVetorComRegras() {
    float vet[20];
    int i;

    printf("Digite 10 valores para preencher as primeiras posições do vetor:\n");
    for (i = 0; i < 10; i++) {
        printf("vet[%d] = ", i);
        scanf("%f", &vet[i]);
    }

    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            vet[i + 10] = vet[i] + (vet[i] * 0.02);
        } else {
            vet[i + 10] = vet[i] + (vet[i] * 0.05);
        }
    }

    printf("\nVetor final:\n");
    for (i = 0; i < 20; i++) {
        printf("vet[%d] = %.2f\n", i, vet[i]);
    }
}

int main() {
    preencherVetorComRegras();
    return 0;
}
