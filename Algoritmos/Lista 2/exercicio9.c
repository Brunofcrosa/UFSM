/** 9. Um professor resolveu considerar, para cálculo da média final do semestre, somente as duas
maiores notas das três provas realizadas pelos alunos. Para auxiliá-lo, deve-se fazer um algoritmo
que leia as três notas de um aluno e escreva a média aritmética considerando apenas as suas duas
maiores notas.
**/
#include <stdio.h>
int main()
{
	float nota1, nota2, nota3, mediaAritmetica;
	
	printf("Insira a nota1: ");
	scanf("%f", &nota1);
	printf("Insira a nota2: ");
	scanf("%f", &nota2);
	printf("Insira a nota3: ");
	scanf("%f", &nota3);
	
	if(nota1 > nota2 && nota2 > nota3)
	{
		mediaAritmetica = (nota1 + nota2) / 2;
		printf("a media do aluno eh: %.2f",mediaAritmetica);
	}
	else if(nota1 > nota2 && nota2 < nota3)
	{
		mediaAritmetica = (nota1 + nota3) / 2;
		printf("a media do aluno eh: %.2f",mediaAritmetica);
	}
	else {
		mediaAritmetica = (nota2 + nota3) / 2;
		printf("a media do aluno eh: %.2f",mediaAritmetica);
	}
	return 0;
}
