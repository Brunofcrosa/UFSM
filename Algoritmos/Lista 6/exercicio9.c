#include <stdio.h>

int main() {
 
    char *produtos[] = {"Prego", "Porca", "Parafuso"};
    int vendas[3][12]; 
    int i, j;
    long long totalVendaAnualProduto;
    long long totalVendaMensalEmpresa;

    printf("Digite as vendas (em barris) para cada produto por mês:\n");
    for (i = 0; i < 3; i++) {
        printf("Produto: %s\n", produtos[i]);
        for (j = 0; j < 12; j++) {
            printf("Venda para o mês %d: ", j + 1);
            scanf("%d", &vendas[i][j]);
        }
    }

    // a) Total de venda anual de cada produto
    printf("\nTotal de venda anual de cada produto:\n");
    for (i = 0; i < 3; i++) {
        totalVendaAnualProduto = 0;
        for (j = 0; j < 12; j++) {
            totalVendaAnualProduto += vendas[i][j];
        }
        printf("%s: %lld barris\n", produtos[i], totalVendaAnualProduto);
    }

    // b) Total de venda da empresa em cada mês
    printf("\nTotal de venda da empresa em cada mês:\n");
    for (j = 0; j < 12; j++) {
        totalVendaMensalEmpresa = 0;
        for (i = 0; i < 3; i++) {
            totalVendaMensalEmpresa += vendas[i][j];
        }
        printf("Mês %d: %lld barris\n", j + 1, totalVendaMensalEmpresa);
    }

    return 0;
}