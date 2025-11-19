/** 2. Desenvolva um algoritmo para ler o nome, sexo e idade de 10 pessoas. Em seguida,
solicitar ao usuário que digite um sexo e exibir o nome e idade das pessoas que possuem
aquele sexo.
**/
#include <stdio.h>
#include <string.h>

typedef struct Dados {
	char nome[50];
	int sexo;
	int idade;
} Pessoa;


void lerDados(Pessoa p[], int total) {
	int i;
	for(i = 0; i < total; i++) {
		printf("Insira um nome: ");
		fflush(stdin);
		gets(p[i].nome);
		printf("Insira um sexo:  \n (1) - Masculino  \n (2) - Feminino  \n Opcao: ");
		fflush(stdin);
		scanf("%d", &p[i].sexo);
		printf("Insira uma idade: ");
		fflush(stdin);
		scanf("%d", &p[i].idade);
	}
}

void buscarDados(Pessoa p[], int total) {
	printf("Insira a opcao que deseja buscar: \n (1) - Masculino \n (2) - Feminino \n Opcao: ");
	int opcao;
	int i;
	scanf("%d", &opcao);
	if(opcao == 1 || opcao == 2) {
		for(i = 0; i < total; i++) {
			if(p[i].sexo == opcao) {
				printf("Nome: %s - Idade: %d\n", p[i].nome, p[i].idade);
			}
		}
	} else {
		printf("Opcao invalida!\n");
	}
}

int main() {
	int total;
	Pessoa p[total];
	printf("Insira a quantidade de Pessoas que deseja inserir: ");
	scanf("%d",&total);
	lerDados(p, total);
	buscarDados(p, total);
	return 0;
}