/**
4. Faça um algoritmo que leia um vetor de 10 elementos na função principal. Depois,
chame uma função para modificar o vetor de modo que o primeiro elemento passe
para a última posição, e desloque todos os outros para uma posição a esquerda.
Imprima o vetor modificado na função main.
Exemplo:
Antes: 12 35 25 14 1 85 10 110 44 996
Depois: 35 25 14 1 85 10 110 44 996 12
**/
#include <stdio.h>

void deslocaVetor(int vetor[], int tamanho) {
    int primeiroElemento = vetor[0];
    for (int i = 0; i < tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    vetor[tamanho - 1] = primeiroElemento;
}

int main() {
    int tamanho;
	int vetor[100]; 
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 1 || tamanho > 100) {
        printf("Tamanho invalido. Use um valor entre 2 e 100.\n");
        return 1;
    }
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("\nVetor original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    deslocaVetor(vetor, tamanho);
    printf("Vetor modificado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
