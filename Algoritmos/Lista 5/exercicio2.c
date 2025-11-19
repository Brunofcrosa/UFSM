/**
2. Crie um programa com uma função que leia 5 elementos de um vetor A. Construir um vetor B de mesmo
tipo, observando a seguinte lei de formação: Todo elemento de B deve ser o quadrado do elemento de A
correspondente. Apresentar os 2 vetores.
**/
#include <stdio.h>
void function() 
{
    int vetorA[5], vetorB[5], i;

    for (i = 0; i < 5; i++) {
        printf("Digite o elemento A[%d]: ", i);
        scanf("%d", &vetorA[i]);
        vetorB[i] = vetorA[i] * vetorA[i];
    }

    printf("Vetor A: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", vetorA[i]);
    }

    printf("\n Vetor B (quadrado de A): ");
    for (i = 0; i < 5; i++) {
        printf("%d ", vetorB[i]);
    }
    printf("\n");
}

int main() {
    function();
    return 0;
}