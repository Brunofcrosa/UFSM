#include <stdio.h>
#include <stdlib.h>
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

void merge(float vetor[], int esq, int meio, int dir, int *pComparacoes, int *pMovimentacoes) {
    int i, j, aux;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    float *esquerdo = (float*)malloc(n1 * sizeof(float));
    float *direito = (float*)malloc(n2 * sizeof(float));
    *pMovimentacoes += n1 + n2;
    for (i = 0; i < n1; i++) {
        esquerdo[i] = vetor[esq + i];
    }
    for (j = 0; j < n2; j++) {
        direito[j] = vetor[meio + 1 + j];
    }
    i = 0;
    j = 0;
    aux = esq;
    while (i < n1 && j < n2) {
        (*pComparacoes)++;
        
        if (esquerdo[i] <= direito[j]) {
            vetor[aux] = esquerdo[i];
            i++;
        } else {
            vetor[aux] = direito[j];
            j++;
        }
        (*pMovimentacoes)++;
        aux++;
    }
    while (i < n1) {
        vetor[aux] = esquerdo[i];
        i++;
        aux++;
        (*pMovimentacoes)++;
    }
    while (j < n2) {
        vetor[aux] = direito[j];
        j++;
        aux++;
        (*pMovimentacoes)++;
    }

    free(esquerdo);
    free(direito);
}

void mergeSort(float vetor[], int esq, int dir, int *pComparacoes, int *pMovimentacoes) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(vetor, esq, meio, pComparacoes, pMovimentacoes);
        mergeSort(vetor, meio + 1, dir, pComparacoes, pMovimentacoes);
        merge(vetor, esq, meio, dir, pComparacoes, pMovimentacoes);
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
    int numMovimentacoes = 0;
    printf("Vetor Original: ");
    imprimirVetor(precos, tamanho);
    clock_t inicio, fim;
    double tempoCPU;
    inicio = clock();
    mergeSort(precos, 0, tamanho - 1, &numComparacoes, &numMovimentacoes);
    fim = clock();
    printf("Vetor Ordenado: ");
    imprimirVetor(precos, tamanho);
    tempoCPU = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %.2f segundos\n", tempoCPU);
    printf("Numero de Comparacoes: %d\n", numComparacoes);
    printf("Numero de Movimentacoes: %d\n", numMovimentacoes);
    return 0;
}