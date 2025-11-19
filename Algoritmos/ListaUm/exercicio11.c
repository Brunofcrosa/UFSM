/******************************************************************************


11.	Elaborar um programa que leia dois valores e apresente os resultados das quatro 
operações aritméticas básicas.

*******************************************************************************/
#include <stdio.h>

int main () {
    float valor1, valor2;
    
    printf("Insira o valor1: ");
    scanf("%f",&valor1);
    
    printf("Insira o valor2: ");
    scanf("%f",&valor2);
    
    printf("Resultado da adição: %.1f \n ", valor1 + valor2);
    printf("Resultado da subtração: %.1f \n", valor1 - valor2);
    printf("Resultado da multiplicação: %.1f \n", valor1 * valor2);
    printf("Resultado da divisão : %.1f \n", valor1 / valor2);
    
return 0;
}