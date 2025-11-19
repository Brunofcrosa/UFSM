#include <stdio.h>
#include <time.h>

void imprimirVetor(float vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%.2f", vetor[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void trocar(float *pA, float *pB) {
    float temp = *pA;
    *pA = *pB;
    *pB = temp;
}

void ordenar(float vetor[], int tamanho, int *pComparacoes, int *pTrocas) {
    int i, j;
    *pComparacoes = 0;
    *pTrocas = 0;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            (*pComparacoes)++;
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
                (*pTrocas)++;
            }
        }
    }
}

int main() {
    float precos[] = {
        389.42, 148.39, 324.67, 78.23, 203.81,
        271.54, 125.96, 87.58, 450.23, 375.92,
        66.42, 491.01, 410.64, 180.96, 120.78,
        253.33, 42.19, 314.04, 56.88, 171.15
    };
    int tamanho = sizeof(precos) / sizeof(precos[0]);
    int numComparacoes = 0;
    int numTrocas = 0;
    printf("Vetor Original: ");
    imprimirVetor(precos, tamanho);
    clock_t inicio, fim;
    double tempoCPU;
    inicio = clock();
    ordenar(precos, tamanho, &numComparacoes, &numTrocas);
    fim = clock();
    printf("Vetor Ordenado: ");
    imprimirVetor(precos, tamanho);
    tempoCPU = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %.2f segundos\n", tempoCPU);
    printf("Numero de Comparacoes: %d\n", numComparacoes);
    printf("Numero de Trocas: %d\n", numTrocas);
    return 0;
}