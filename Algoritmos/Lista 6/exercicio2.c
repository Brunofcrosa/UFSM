#include <stdio.h>

int main() {
    float matriz[4][3];
    int linha, coluna;
    int i, j;

    printf("Digite os elementos da matriz 4x3:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("\nDigite a linha (0-3) e a coluna (0-2) do elemento que deseja visualizar:\n");
    scanf("%d %d", &linha, &coluna);

    if (linha >= 0 && linha < 4 && coluna >= 0 && coluna < 3) {
        printf("O elemento na linha %d e coluna %d é: %.2f\n", linha, coluna, matriz[linha][coluna]);
    } else {
        printf("Posição inválida.\n");
    }

    return 0;
}