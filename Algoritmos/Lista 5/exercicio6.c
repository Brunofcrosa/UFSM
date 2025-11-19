/**6. Crie um programa com uma função que leia 8 valores dos vetores A e B. O Vetor A deve aceitar apenas a
entrada de valores que sejam divisíveis por 2 e 3, e o vetor B deve aceitar apenas valores múltiplos de 5.
Esta validação não deve ser feita pelo usuário, mas sim pelo programa. Depois, crie um terceiro vetor que
armazene todos os elementos dos dois vetores (16 posições) e apresente esses valores na tela.
**/
#include <stdio.h>

void processaVetores() {
    int A[8], B[8], C[16];
    int valor, i = 0, j = 0;

    printf("Preenchendo vetor A (valores divisiveis por 2 e 3):\n");
    while (i < 8) {
        printf("Digite um valor para A[%d]: ", i);
        scanf("%d", &valor);
        if (valor % 2 == 0 && valor % 3 == 0) {
            A[i] = valor;
            i++;
        } else {
            printf("Valor invalido! Deve ser divisivel por 2 e 3.\n");
        }
    }

    printf("\nPreenchendo vetor B (valores múltiplos de 5):\n");
    while (j < 8) {
        printf("Digite um valor para B[%d]: ", j);
        scanf("%d", &valor);
        if (valor % 5 == 0) {
            B[j] = valor;
            j++;
        } else {
            printf("Valor invalido! Deve ser multiplo de 5.\n");
        }
    }

    for (i = 0; i < 8; i++) {
        C[i] = A[i];
        C[i + 8] = B[i];
    }

    printf("\nValores do vetor C (A + B):\n");
    for (i = 0; i < 16; i++) {
        printf("C[%d] = %d\n", i, C[i]);
    }
}

int main() {
    processaVetores();
    return 0;
}
