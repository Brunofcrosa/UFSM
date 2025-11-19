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

void insertionSort(float vetor[], int tamanho, int *pComparacoes, int *pMovimentacoes) {
    int i, j;
    float chave;
    *pComparacoes = 0;
    *pMovimentacoes = 0;

    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0) {
            
            (*pComparacoes)++; 
            
            if (vetor[j] > chave) {
                vetor[j + 1] = vetor[j];
                (*pMovimentacoes)++; 
                j = j - 1;
            } else {
                break;
            }
        }
        vetor[j + 1] = chave;
        (*pMovimentacoes)++; 
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
    insertionSort(precos, tamanho, &numComparacoes, &numMovimentacoes);
    fim = clock();
    printf("Vetor Ordenado: ");
    imprimirVetor(precos, tamanho);
    tempoCPU = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %.2f segundos\n", tempoCPU);
    printf("Numero de Comparacoes: %d\n", numComparacoes);
    printf("Numero de Movimentacoes: %d\n", numMovimentacoes);
    return 0;
}