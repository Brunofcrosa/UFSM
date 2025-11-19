#include <stdio.h>

void calcularLitrosGasolina() {
    float precoLitro;
    float valorPagamento;
    float litrosColocados;

    printf("--- Calculo de Litros de Gasolina ---\n");

    printf("Digite o preco do litro da gasolina (R$): ");
    scanf("%f", &precoLitro);

    printf("Digite o valor em reais que deseja abastecer (R$): ");
    scanf("%f", &valorPagamento);

    if (precoLitro <= 0) {
        printf("O preco do litro da gasolina deve ser maior que zero. Por favor, tente novamente.\n");
        return;
    }
    if (valorPagamento < 0) {
        printf("O valor do pagamento nao pode ser negativo. Por favor, tente novamente.\n");
        return;
    }

    litrosColocados = valorPagamento / precoLitro;

    printf("Com R$ %.2f, voce conseguiu colocar %.2f litros de gasolina.\n", valorPagamento, litrosColocados);
    printf("---------------------------------------\n\n");
}

int main() {
    calcularLitrosGasolina();
    return 0;
}