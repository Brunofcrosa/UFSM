/******************************************************************************


21.	Ler o valor correspondente ao salário mensal (SM) de um trabalhador e também
o valor do percentual (PE) de reajuste a ser atribuído. Apresentar o valor do novo salário (NS).

*******************************************************************************/
#include <stdio.h>
int main () {
    float salarioMensal, reajuste, calculo;
    printf("Insira o salario mensal: ");
    scanf("%f",&salarioMensal);
    printf("Insira o reajuste: ");
    scanf("%f",&reajuste);
    calculo = (salarioMensal * reajuste) / 100;
    
    printf("O novo salario a ser recebido eh: %1.f", salarioMensal + calculo);
    
return 0;

}