#include <stdio.h>


float calcularPrecoComDesconto(float valorProduto, float percentualDesconto) { [cite: 12]
    return valorProduto * (1.0 - percentualDesconto / 100.0);
}


float calcularValorTotalVenda(int quantidade, float precoComDesconto) { [cite: 13]
    return quantidade * precoComDesconto;
}

int main() {
    float precoOriginal, percentualDesconto;
    int quantidade;
    float precoComDescontoAplicado;
    float valorTotalVenda;
    float valorDesconto;

    printf("Digite o preco original do produto: R$ ");
    scanf("%f", &precoOriginal);

    printf("Digite a porcentagem de desconto (ex: 10 para 10%%): ");
    scanf("%f", &percentualDesconto);

    printf("Digite a quantidade vendida: ");
    scanf("%d", &quantidade);

    precoComDescontoAplicado = calcularPrecoComDesconto(precoOriginal, percentualDesconto); [cite: 12]
    valorTotalVenda = calcularValorTotalVenda(quantidade, precoComDescontoAplicado); [cite: 13]
    valorDesconto = precoOriginal - precoComDescontoAplicado;

    printf("\n--- Detalhes da Venda ---\n"); [cite: 14]
    printf("Preco original do produto: R$ %.2f\n", precoOriginal); [cite: 14]
    printf("Desconto aplicado por unidade: R$ %.2f (%.2f%%)\n", valorDesconto, percentualDesconto); [cite: 14]
    printf("Valor total da venda (com desconto): R$ %.2f\n", valorTotalVenda); [cite: 14]

    return 0;
}