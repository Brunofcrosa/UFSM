/**10. Faça um algoritmo para ler os valores gastos em cheque por uma pessoa durante um mês, e depois
imprimir: a lista com todos os valores, o maior valor, o menor valor e a média de todos os valores. No
início do algoritmo o usuário deve informar o número de cheques usados e passa-lo por parâmetro para
uma função para realizar os cálculos.
**/
#include <stdio.h>
void processarCheques(float cheques[], int quantidade) {
    float soma = 0, maior, menor;
    int i;
    maior = menor = cheques[0];
    printf("\nValores dos cheques:\n");
    for (i = 0; i < quantidade; i++) {
        printf("Cheque %d: R$ %.2f\n", i + 1, cheques[i]);
        soma += cheques[i];

        if (cheques[i] > maior)
            maior = cheques[i];

        if (cheques[i] < menor)
            menor = cheques[i];
    }
    float media = soma / quantidade;
    printf("\nMaior valor: R$ %.2f\n", maior);
    printf("Menor valor: R$ %.2f\n", menor);
    printf("Média dos valores: R$ %.2f\n", media);
}

int main() {
    int n;
    printf("Digite a quantidade de cheques usados: ");
    scanf("%d", &n);
    float cheques[n];
    for (int i = 0; i < n; i++) {
        printf("Digite o valor do cheque %d: R$ ", i + 1);
        scanf("%f", &cheques[i]);
    }
    processarCheques(cheques, n);

    return 0;
}
