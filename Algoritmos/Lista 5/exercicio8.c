/**8.Construa um algoritmo para ler 2 vetores reais de N posições e enviá-los por parâmetro para uma função.
Depois esta função deve criar um terceiro vetor cujo conteúdo de cada posição é: 1, se o número
armazenado em uma posição do 1º vetor é o mesmo armazenado na posição respectiva do 2º vetor, e 0,
se não for o mesmo.
**/
#include <stdio.h>
#include <stdlib.h>

void comparaVetores(float vet1[], float vet2[], int resultado[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vet1[i] == vet2[i]) {
            resultado[i] = 1;
        } else {
            resultado[i] = 0;
        }
    }
}

int main() {
    int N;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &N);

    float vet1[N], vet2[N];
    int resultado[N];

    printf("\nDigite os valores do primeiro vetor:\n");
    for (int i = 0; i < N; i++) {
        printf("vet1[%d]: ", i);
        scanf("%f", &vet1[i]);
    }

    printf("\nDigite os valores do segundo vetor:\n");
    for (int i = 0; i < N; i++) {
        printf("vet2[%d]: ", i);
        scanf("%f", &vet2[i]);
    }

    comparaVetores(vet1, vet2, resultado, N);

    printf("\nVetor resultado (1 = iguais, 0 = diferentes):\n");
    for (int i = 0; i < N; i++) {
        printf("resultado[%d] = %d\n", i, resultado[i]);
    }

    return 0;
}
