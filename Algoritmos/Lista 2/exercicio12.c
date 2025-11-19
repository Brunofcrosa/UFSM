/** 12. Fazer um algoritmo que leia um número inteiro, verifique e escreva se ele e negativo, zero ou
positivo. Caso seja positivo diga ainda se ele e par ou impar.
**/
#include <stdio.h>
int main()
{
	int num1;
	
	printf("Insira um numero inteiro: ");
	scanf("%d", &num1);
	
	if(num1 < 0)
	{
		printf("O numero eh negativo");
	}
	else if(num1 > 0)
	{
		if(num1 % 2 == 0)
		{
			printf("O numero eh positivo e ele eh par.");
		}
		else
		{
			printf("O numero eh positivo e ele eh impar");
		}
	}
	else if(num1 == 0)
	{
		printf("O numero eh zero");
	}
	
	return 0;
}