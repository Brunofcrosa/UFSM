#include <stdio.h>

void calcularArrecadacaoPadaria() {
    int quantidadePaes;
    int quantidadeBroas;
    float precoPao = 0.12f;
    float precoBroa = 1.50f;
    float totalPaes;
    float totalBroas;
    float arrecadacaoTotal;
    float valorPoupanca;

    printf("--- Arrecadacao da Padaria Hotpao ---\n");

    printf("Digite a quantidade de paes franceses vendidos: ");
    scanf("%d", &quantidadePaes);

    printf("Digite a quantidade de broas vendidas: ");
    scanf("%d", &quantidadeBroas);

    if (quantidadePaes < 0 || quantidadeBroas < 0) {
        printf("As quantidades nao podem ser negativas. Por favor, tente novamente.\n");
        return;
    }

    totalPaes = quantidadePaes * precoPao;

    totalBroas = quantidadeBroas * precoBroa;

    arrecadacaoTotal = totalPaes + totalBroas;

    valorPoupanca = arrecadacaoTotal * 0.10f;

    printf("\nRelatorio de Vendas:\n");
    printf("Total arrecadado com paes: R$ %.2f\n", totalPaes);
    printf("Total arrecadado com broas: R$ %.2f\n", totalBroas);
    printf("Arrecadacao total do dia: R$ %.2f\n", arrecadacaoTotal);
    printf("Valor a ser guardado na poupanca (10%%): R$ %.2f\n", valorPoupanca);
    printf("--------------------------------------\n\n");
}

int main() {
    calcularArrecadacaoPadaria();
    return 0;
}