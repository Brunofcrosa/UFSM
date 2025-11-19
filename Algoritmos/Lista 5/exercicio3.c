/**
3. Escrever um programa com uma função que leia N números reais, armazene-os em um vetor e imprimaos na ordem inversa.
**/
#include <stdio.h>
void imprimirInverso() {
    int totalNumeros, i;
    printf("Quantos numeros deseja digitar? ");
    scanf("%d", &totalNumeros);

    float numeros[totalNumeros];

    for (i = 0; i < totalNumeros; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%f", &numeros[i]);
    }

    printf("Numeros na ordem inversa:\n");
    for (i = totalNumeros - 1; i >= 0; i--) {
        printf("%.2f ", numeros[i]);
    }
    printf("\n");
}
int main() {
    imprimirInverso();
    return 0;
}