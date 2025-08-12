/** Faça um algoritmo para ler os valores gastos em cheque por uma pessoa durante um
mês na função principal.
Depois crie uma função para encontrar imprimir: a lista com
todos os valores, o maior valor, o menor valor e a média de todos os valores
No início do algoritmo o usuário deve informar quantos cheques foram usados; estabeleça um
número máximo de cheques.
**/
#include <stdio.h>

void analisarCheques(float valores[], int numCheques);

int main() {
    int MAX_CHEQUES = 100;
    int numCheques;

    printf("Quantos cheques foram usados? ");
    scanf("%d", &numCheques);

    if (numCheques > 0 && numCheques <= MAX_CHEQUES) {
        float valores[numCheques];

        for (int i = 0; i < numCheques; i++) {
            printf("Insira o valor do cheque %d: ", i + 1);
            scanf("%f", &valores[i]);
        }

        analisarCheques(valores, numCheques);
    } else {
        printf("Numero de cheques invalido.\n");
    }

    return 0;
}

void analisarCheques(float valores[], int numCheques) {
    if (numCheques <= 0) {
        printf("Nenhum cheque.\n");
        return;
    }

    printf("\nLista de valores: ");
    float soma = 0;
    for (int i = 0; i < numCheques; i++) {
        printf("%.2f ", valores[i]);
        soma += valores[i];
    }
    printf("\n");

    float maior = valores[0];
    float menor = valores[0];

    for (int i = 1; i < numCheques; i++) {
        if (valores[i] > maior) {
            maior = valores[i];
        }
        if (valores[i] < menor) {
            menor = valores[i];
        }
    }

    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);
    printf("Media dos valores: %.2f\n", soma / numCheques);
}
