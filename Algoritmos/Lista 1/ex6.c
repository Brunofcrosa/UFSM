#include <stdio.h>

void calcularValorCamisetas() {
    int qtdPequenas;
    int qtdMedias;
    int qtdGrandes;

    float precoPequena = 10.00f;
    float precoMedia = 12.00f;
    float precoGrande = 15.00f;

    float totalPequenas;
    float totalMedias;
    float totalGrandes;
    float valorArrecadado;

    printf("--- Fabrica de Camisetas ---\n");

    printf("Digite a quantidade de camisetas PEQUENAS vendidas: ");
    scanf("%d", &qtdPequenas);

    printf("Digite a quantidade de camisetas MEDIAS vendidas: ");
    scanf("%d", &qtdMedias);

    printf("Digite a quantidade de camisetas GRANDES vendidas: ");
    scanf("%d", &qtdGrandes);

    if (qtdPequenas < 0 || qtdMedias < 0 || qtdGrandes < 0) {
        printf("As quantidades de camisetas nao podem ser negativas. Por favor, tente novamente.\n");
        return;
    }

    totalPequenas = qtdPequenas * precoPequena;
    totalMedias = qtdMedias * precoMedia;
    totalGrandes = qtdGrandes * precoGrande;

    valorArrecadado = totalPequenas + totalMedias + totalGrandes;

    printf("\nResumo da Venda:\n");
    printf("Camisetas Pequenas: %d x R$%.2f = R$%.2f\n", qtdPequenas, precoPequena, totalPequenas);
    printf("Camisetas Medias: %d x R$%.2f = R$%.2f\n", qtdMedias, precoMedia, totalMedias);
    printf("Camisetas Grandes: %d x R$%.2f = R$%.2f\n", qtdGrandes, precoGrande, totalGrandes);
    printf("------------------------------------\n");
    printf("VALOR TOTAL ARRECADADO: R$ %.2f\n", valorArrecadado);
    printf("------------------------------------\n\n");
}

int main() {
    calcularValorCamisetas();
    return 0;
}