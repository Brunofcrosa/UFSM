#include <stdio.h>
int main () {
	int valor1, valor2, valor3;
	printf("Insira o primeiro valor: ");
	scanf("%d", &valor1);
	printf("Insira o segundo valor: ");
	scanf("%d", &valor2);
	printf("Insira o terceiro valor: ");
	scanf("%d", &valor3);
	
	if(valor1 > valor2 || valor1 > valor3) {
		printf("O maior valor eh %d", valor1);
	}
	else if(valor2 > valor1 || valor2 > valor3) {
		printf("O maior valor eh %d", valor2);
	}
	else if(valor3 > valor1 || valor3 > valor2) {
		printf("O maior valor eh %d", valor3);
	}
	
return 0;
}