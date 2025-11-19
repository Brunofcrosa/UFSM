/******************************************************************************


20.	Desenvolver um programa que leia três valores inteiros e apresente como resultado
o valor do quadrado da soma dos três valores lidos.

*******************************************************************************/
#include <stdio.h>
int main () {
    int num1, num2, num3;
    printf("Insira o num1: ");
    scanf("%d",&num1);
    printf("Insira o num2: ");
    scanf("%d",&num2);
    printf("Insira o num3: ");
    scanf("%d",&num3);
    
    printf("O resultado eh: %d", (num1 + num2 + num3) * (num1 + num2 + num3));
    
return 0;
}