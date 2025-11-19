/** . 8. Escreva um algoritmo que leia uma letra e imprima uma mensagem dizendo se é vogal ou não.
**/
#include <stdio.h>
int main()
{
	char letra;
	
	printf("Insira uma letra: ");
	scanf("%c", &letra);
	
	if(letra == 'A' || letra == 'a' || letra == 'E' || letra == 'e' || letra == 'I' || letra == 'i' || letra == 'O' || letra == 'o' || letra == 'U' || letra == 'u')
	{
		printf("Eh uma vogal.");
	}
	else
	{
		printf("Nao eh uma vogal.");
	}

	return 0;
}