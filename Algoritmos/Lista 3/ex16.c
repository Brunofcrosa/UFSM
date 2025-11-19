#include <stdio.h>

void analisarAplicacaoFinanceira() {
    float saldoInicial;
    float jurosMensal = 0.05f;
    float saqueMensal = 200.00f;
    int meses = 0;
    float saldoAtual;

    printf("--- Analise de Aplicacao Financeira ---\n");

    printf("Digite o valor inicial aplicado (R$): ");
    scanf("%f", &saldoInicial);

    if (saldoInicial < 0) {
        printf("O saldo inicial nao pode ser negativo.\n");
        return;
    }

    saldoAtual = saldoInicial;

    printf("\nRelatorio da Aplicacao:\n");
    printf("Mes %d: Saldo Inicial = R$ %.2f\n", meses, saldoAtual);

    while (saldoAtual >= saqueMensal) {
        meses++;
        saldoAtual = saldoAtual * (1 + jurosMensal); 
        saldoAtual = saldoAtual - saqueMensal;     
        printf("Mes %d: Saldo (aplica juros e saca) = R$ %.2f\n", meses, saldoAtual);
    }

    printf("\nConclusao:\n");
    printf("O saldo se tornou insuficiente para sacar R$ %.2f apos %d meses.\n", saqueMensal, meses);
    printf("O saldo restante apos o ultimo saque (ou antes do saque se for insuficiente) e: R$ %.2f\n", saldoAtual);
    printf("---------------------------------------\n\n");
}

int main() {
    analisarAplicacaoFinanceira();
    return 0;
}