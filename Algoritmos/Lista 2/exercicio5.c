/***5. Ler um número inteiro e imprimir uma mensagem informando se ele é par e divisível totalmente
divisível por 3. ***/
#include <stdio.h>
int main()
{
	int num;
	printf("Insira um numero inteiro: ");
	scanf("%d",&num);
	
	if(num % 2 == 0) {
		printf("O numero eh par!");
	}
	else if(num % 3 == 0) {
		printf("O numero eh totalmente divisivel por 3.");
	}
	else {
		printf("O numero nao eh par e tambem nao eh divisivel totalmente por 3");
	}
return 0;
}