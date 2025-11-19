/** Faça um programa que receba dois valores e, utilizando ponteiros, retorne o maior e
menor deles. O programa deve ter um controle sobre valores iguais.
**/
#include <stdio.h>

void encontraMaiorMenor(int *num1, int *num2, int *maior, int *menor) {
    if (*num1 > *num2) {
        *maior = *num1;
        *menor = *num2;
    } else if (*num2 > *num1) {
        *maior = *num2;
        *menor = *num1;
    } else {
        printf("Os valores são iguais.\n");
        *maior = *num1;
        *menor = *num1;
    }
}

int main() {
	
    int valor1, valor2, maior, menor;
    printf("Insira o primeiro valor: ");
    scanf("%d", &valor1);
    printf("Insira o segundo valor: ");
    scanf("%d", &valor2);
    encontraMaiorMenor(&valor1, &valor2, &maior, &menor);
    printf("O maior valor eh: %d \n", maior);
    printf("O menor valor eh: %d \n", menor);
    return 0;
    
}