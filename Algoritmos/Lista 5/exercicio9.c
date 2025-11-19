/**9.  Desenvolva um algoritmo com uma função que contenha um vetor de N elementos. O conteúdo das
posições pares deve ser ‘P’ e das posições ímpares deve ser ‘I’. A inserção dos elementos deve ser feita
automaticamente. Depois, apresente o resultado na tela.
**/
#include <stdio.h>
void preencherVetor(char vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (i % 2 == 0) {
            vetor[i] = 'P';
        } else {
            vetor[i] = 'I';
        }
    }
    
    printf("Vetor gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("vetor[%d] = %c\n", i, vetor[i]);
    }
}

int main() {
    int N;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    char vetor[N];

    preencherVetor(vetor, N);

    return 0;
}
