/**
4. Desenvolver um algoritmo com uma função que leia dois vetores, sendo a primeiro com 5 elementos e o
segundo com 8 elementos. Construir um terceiro vetor que armazene a junção dos dois primeiros vetores
e mostre os valores na tela. Assim, o terceiro vetor deve ter 13 posições.
**/
#include <stdio.h>
void juntarVetores() 
{
    int vetor1[5], vetor2[8], vetor3[13], i;
    
    printf("Digite 5 elementos para o primeiro vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("vetor1[%d]: ", i);
        scanf("%d", &vetor1[i]);
        vetor3[i] = vetor1[i];
    }

    printf("Digite 8 elementos para o segundo vetor:\n");
    for (i = 0; i < 8; i++) {
        printf("vetor2[%d]: ", i);
        scanf("%d", &vetor2[i]);
        vetor3[i + 5] = vetor2[i];
    }

    printf("Terceiro vetor (13 posicoes):\n");
    for (i = 0; i < 13; i++) {
        printf("%d ", vetor3[i]);
    }
    printf("\n");
}

int main() {
    juntarVetores();
    return 0;
}