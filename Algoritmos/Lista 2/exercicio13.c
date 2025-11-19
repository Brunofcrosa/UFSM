/** Fazer um algoritmo que leia valores para as variáveis hora, minuto e segundo; verificando e
escrevendo se elas correspondem a um horário válido ou não. Para um horário ser valido, a hora
deve estar no intervalo de 0 a 23, o minuto e o segundo no intervalo de 0 a 59.
**/
#include <stdio.h>
int main() {
	int hora, minuto, segundo;
	
	printf("Insira valor para hora: ");
	scanf("%d", &hora);
	
	if(hora >= 0 && hora < 24)
	{
	printf("Insira valor para minuto: ");
	scanf("%d", &minuto);
		if(minuto >= 0 && minuto > 60)
		{
		printf("Insira valor para segundo: ");
		scanf("%d", &segundo);
			if(segundo >= 0 && segundo > 60)
			{
				
			}
		}
		else
		{
		printf("Digitou um numero invalido para minuto.")
		}
	}
	else
	{
		printf("Digitou um numero invalido para hora.");
	}
	return 0;
}