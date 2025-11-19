/** 7. A partir de dois números fornecidos pelo usuário, escrever uma das seguintes mensagens:
a) Os dois são pares
b) Os dois são impares
c) O primeiro é par e o segundo é ímpar
d) O primeiro é ímpar e o segundo é par
**/
#include <stdio.h>
int main() 
{
	int num, num2;
	printf("Insira um numero: ");
	scanf("%d",&num);
	printf("Insira outro numero: ");
	scanf("%d",&num2);
	
	if(num % 2 == 0 && num2 % 2 == 0)
	{
		printf("Os dois numeros sao par. [%d] e [%d]", num, num2);
	}
	else if(num % 2 == 0 && num2 % 2 != 0)
	{
		printf("O primeiro [%d] eh par e o segundo [%d] eh impar",num, num2);
	}
	else if(num % 2 != 0 && num2 % 2 == 0)
	{
		printf("O primeiro [%d] eh impar e o segundo [%d] eh par", num, num2);
	}
	else {
		printf("Os dois numeros sao impares. [%d] e [%d]", num, num2);
	}
	
	return 0;
}