/** . Em uma pesquisa envolvendo 20 entrevistados, uma editora solicitou os seguintes dados:
sexo, idade e quantidade de livros que leu em 2020. Faça um programa que leia os dados
digitados pelo usuário e ao final, calcule e imprima:
a) A quantidade total de livros lidos pelos entrevistados menores de 10 anos;
b) A quantidade de mulheres que leram 5 livros ou mais;
c) O percentual de pessoas que não leram livros.
**/
#include <stdio.h>
#include <string.h>

typedef struct Dados {
	char sexo[50];
	int idade;
	int livros;
} Dados;
typedef struct Resultados {
	int total_livros;
	int count_mulheres;
	float percentual;
} Resultados;

void lerDados(Dados p[]) {
	int i;
	for(i=0; i < 3; i++) {
		printf("Insira a idade: ");
		scanf("%d",&p[i].idade);
		printf("Insira a quantidade de livros que leu: ");
		scanf("%d",&p[i].livros);
		printf("Insira o sexo: ");
		fflush(stdin);
		gets(p[i].sexo);
	}
}

Resultados calcularDados(Dados p[], Resultados x) {
	x.count_mulheres = 0;
	int count_livros = 0;
	x.total_livros = 0;
	int i;
	for(i=0; i < 3; i++) {
		if(p[i].idade < 10) {
			x.total_livros += p[i].livros;
		}
		if(strcmp(p[i].sexo, "F") == 0) {
			if(p[i].livros >= 5) {
				x.count_mulheres++;
			}
		}
		if(p[i].livros == 0) {
			count_livros++;
		}
	}
	x.percentual = (count_livros * 100) / 3;
	return x;
}

void imprimirDados(Resultados x) {
	printf("a) A quantidade total de livros lidos pelos entrevistados menores de 10 anos: %d\n", x.total_livros);
	printf("b) A quantidade de mulheres que leram 5 livros ou mais: %d\n", x.count_mulheres);
	printf("c) O percentual de pessoas que não leram livros: %f\n", x.percentual);
}

int main() {
	Dados p[3];
	Resultados x;
	lerDados(p);
	x = calcularDados(p, x);
	imprimirDados(x);
	return 0;
}                    
	