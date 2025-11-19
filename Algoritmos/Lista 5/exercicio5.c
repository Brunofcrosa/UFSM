/**Criar um programa com uma função que leia os N valores de um vetor do tipo inteiro e, então, construir
um segundo vetor de mesma dimensão, sendo que cada elemento do segundo vetor é o somatório do
elemento correspondente no primeiro. Ex.: VetA[0] = 5; logo, VetB[0] = 15 (1 + 2 + 3 + 4 + 5 = 15).
**/
#include <stdio.h>
int somatorio(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += i;
    }
    return soma;
}

void lerVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("VetA[%d] = ", i);
        scanf("%d", &vetor[i]);
    }
}

void preencherSomatorios(int vetorA[], int vetorB[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetorB[i] = somatorio(vetorA[i]);
    }
}

void exibirVetor(int vetor[], int tamanho, char nome[]) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s[%d] = %d\n", nome, i, vetor[i]);
    }
}

int main() {
    int N;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    int VetA[N], VetB[N];

    lerVetor(VetA, N);
    preencherSomatorios(VetA, VetB, N);
    exibirVetor(VetB, N, "VetB");

    return 0;
}
