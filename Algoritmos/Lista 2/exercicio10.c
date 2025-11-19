/** O índice de massa corporal (IMC) é calculado dividindo-se o peso de uma pessoa pela sua altura ao
quadrado. A partir do valor de IMC podemos classificar a pessoa quanto ao peso conforme os
intervalos apresentados a seguir (revista Galileu nov2004): 
**/ 
#include <stdio.h>
int main() 
{
	float peso, altura, imc;
	
	printf("Insira o peso da pessoa: ");
	scanf("%f", &peso);
	printf("Insira a altura da pessoa: ");
	scanf("%f", &altura);
	imc = peso / (altura * altura);
	
	if(imc >= 0 && imc < 18.5) 
	{
		printf("Abaixo do peso.");
	}
	else if(imc >= 18.5 && imc < 25)
	{
		printf("Normal.");
	}
	else if(imc >= 25 && imc < 30)
	{
		printf("Pre-obeso");
	}
	else if(imc >= 30 && imc < 35)
	{
		printf("Obeso classe I");
	}
	else if(imc >= 35 && imc < 40)
	{
		printf("Obeso classe II");
	}
	else if(imc >= 40)
	{
		printf("Obeso classe III");
	}
	else
	{
		printf("Insira um numero valido.");
	}
	return 0;
}