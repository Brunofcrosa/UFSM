/** Fazer um algoritmo que leia dois números e apresente-os em ordem crescente.
**/
#include <stdio.h>
int main()
{
	float num1, num2;
	
	printf("Insira um numero: ");
	scanf("%f", &num1);
	printf("Insira um numero: ");
	scanf("%f", &num2);
	
	if(num1 > num2) {
		printf("Os numeros em ordem crescente sao: %.2f %.2f", num2, num1);
	}
	else
	{
		printf("Os numeros em ordem crescente sao: %.2f %.2f", num1, num2);	
	}
	
	return 0;
}