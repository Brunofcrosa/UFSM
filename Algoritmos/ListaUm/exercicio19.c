/******************************************************************************

19.	Desenvolver um programa que leia três valores inteiros e apresente como resultado
o valor da soma dos quadrados dos três valores lidos.
*******************************************************************************/
#include <stdio.h>
int main () {
    int valor1, valor2, valor3;
    int resultado = 0;
    
    printf("Insira o valor1: ");
    scanf("%d",&valor1);
    printf("Insira o valor2: ");
    scanf("%d",&valor2);
    printf("Insira o valor3: ");
    scanf("%d",&valor3);
    resultado = (valor1 * valor1) + (valor2 * valor2) + (valor3 * valor3);
    
    printf("O resultado da soma dos quadrados eh: %d", resultado);
    
return 0;
}