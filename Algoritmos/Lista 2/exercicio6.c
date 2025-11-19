/** Criar um algoritmo que leia um número inteiro e diga a qual mês do ano o mesmo corresponde. Se
o valor for maior que doze ou menor que um, apresente uma mensagem informando que o valor não
corresponde a nenhum mês. Ex.: 3  mês de março **/
#include <stdio.h>
int main()
{
	int num;
	
	printf("Insira um numero inteiro: ");
	scanf("%d",&num);
	
	if(num>12 || num<1) {
		printf("O numero inteiro informado nao corresponde a nenhum mes.");
	}
	else {
		if(num == 1) {
			printf("1. Corresponde ao mes de janeiro");
		}
		else if(num == 2) 
		{
			printf("2. Corresponde ao mes de fevereiro.");
		}
		else if(num == 3) 
		{
			printf("3. Corresponde ao mes de marco");
		}
		else if(num == 4) 
		{
			printf("4. Corresponde ao mes de abril");
		}
		else if(num == 5) 
		{
			printf("5. Corresponde ao mes de maio");
		}
		else if(num == 6) 
		{
			printf("6. Corresponde ao mes de junho");
		}
		else if(num == 7) 
		{
			printf("7. Corresponde ao mes de julho.");
		}
		else if(num == 8) 
		{
			printf("8. Corresponde ao mes de agosto");
		}
		else if(num == 9) 
		{
			printf("9. Corresponde ao mes de setembro");
		}
		else if(num == 10) 
		{
			printf("10. Corresponde ao mes de outubro");
		}
		else if(num == 11) 
		{
			printf("11. Corresponde ao mes de novembro");
		}
		else if(num == 12) 
		{
			printf("12. Corresponde ao mes de dezembro");
		}
	}
	return 0;
}