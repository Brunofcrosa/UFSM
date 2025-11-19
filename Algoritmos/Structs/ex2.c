/** Desenvolva um algoritmo para ler o nome, sexo e idade de 10 pessoas. Em seguida,
solicitar ao usuário que digite um sexo e exibir o nome e idade das pessoas que possuem
aquele sexo.
**/
#include <stdio.h>
#include <string.h>

typedef struct Pessoa {
	char nome[50];
	char sexo[50];
	char idade[50];
} Pessoa;

Pessoa lerDados(Pessoa p[]) {
	int i;
	for(i=0; i<2; i++) {
		printf("Insira Nome: ");
		fflush(stdin);
		gets(p[i].nome);
		printf("Insira H ou M : ");
		fflush(stdin);
		gets(p[i].sexo);
		printf("Insira Idade: ");
		fflush(stdin);
		gets(p[i].idade);
	}
	return p[2];
}

void buscarDados(Pessoa p[]) {
	int i, opcao;
	printf("Escolha um sexo a buscar: \n");
	printf("Opcao: \n - (1) - Homem \n - (2) - Mulher");
	scanf("%d", &opcao);
	fflush(stdin);
	switch(opcao) {
		case 1:
			for(i=0;i < 2; i++) {
				if (strcmp(p[i].sexo, "H") == 0) {
					puts(p[i].nome);
				}
			}
		case 2:
			for(i=0;i < 2; i++) {
				if (strcmp(p[i].sexo, "M") == 0) {
					puts(p[i].nome);
				}
			}
	}
}

int main() {
	Pessoa p[2];
	p[2] = lerDados(p);
	buscarDados(p);
	return 0;
}