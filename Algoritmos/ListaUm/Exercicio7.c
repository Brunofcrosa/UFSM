/******************************************************************************


7.	Desenvolva um algoritmo que:
a.	Declare uma variável float.
b.	Atribua um valor a ela.
c.	Mostre seu valor na tela.


*******************************************************************************/
#include <stdio.h>

int main()
{
    float variavel1;
    
    printf("Insira um valor: ");
    scanf("%f", &variavel1);
    
    printf("O seu valor eh %.2f", variavel1);

    return 0;
}