/******************************************************************************

17.	Elaborar um programa que calcule o volume de uma caixa retangular.
O volume de uma caixa retangular é calculado multiplicando a largura, a altura e o comprimento.
A fórmula é: V = L x h x C. 
*******************************************************************************/

#include <stdio.h>
int main () {
    
    float largura, altura, comprimento, formula;
    
    printf("Insira a altura: ");
    scanf("%f",&altura);
    printf("Insira a largura: ");
    scanf("%f",&largura);
    printf("Insira o comprimento: ");
    scanf("%f",&comprimento);
    formula = largura * altura * comprimento;
    
    printf("O resultado eh: %.2f", formula);
    
return 0;
}