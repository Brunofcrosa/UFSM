/******************************************************************************


10.	Ler um número inteiro e apresentar o quadrado deste número.

*******************************************************************************/
#include <stdio.h>

int main () {
    int num1;
    
    printf("Insira um numero inteiro: ");
    scanf("%d",&num1);
    
    printf("O quadrado desse numero eh: %d", num1 * num1);
    
return 0;
}