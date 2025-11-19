#include <stdio.h>
int main (){
	char luz;
	printf("Insira a letra l para luzes acesas ou d para luzes apagadas: ");
	scanf("%c",&luz);
	if (luz == 'l' || luz == 'L') {
		printf("Luz acesa!");
	}
	else if (luz == 'd' || luz == 'D') {
		printf("Luz apagada!");
	}
	else printf("Valor Invalido!");
	return 0;
}
