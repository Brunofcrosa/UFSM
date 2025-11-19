/**
3. Faça um algoritmo para realizar cadastro e consulta de informações sobre automóveis
usados na concessionária FastCar, onde é apresentado o seguinte menu:
1. Cadastrar automóvel
2. Consultar automóvel
3. Gerar relatório
4. Sair do programa
Na opção 1 o usuário cadastra a placa, descrição, fabricante, cor, ano de fabricação e
preço. Na opção 2 o usuário deve informar uma placa e o algoritmo deve exibir as
informações sobre o veículo. Caso não encontre, deve exibir uma mensagem informando
isso. A opção 3 deve gerar um relatório contendo todos os dados dos automóveis
cadastrados. Considere um máximo de 12 veículos no cadastro.
**/
#include <stdio.h>
#include <string.h>

typedef struct Automovel {
	char placa[50];
	char descricao[50];
	char fabricante[50];
	char cor[50];
	int ano;
	float preco;
} Automovel;

Automovel cadastrarAutomovel(Automovel p[]) {
	int i;
	for(i=0; i < 2; i++) {
		printf("Insira a placa: ");
		fflush(stdin);
		gets(p[i].placa);
		printf("Insira a descricao: ");
		fflush(stdin);
		gets(p[i].descricao);
		printf("Insira o fabricante: ");
		fflush(stdin);
		gets(p[i].fabricante);
		printf("Insira a cor:");
		fflush(stdin);
		gets(p[i].cor);
		printf("Insira o ano: ");
		fflush(stdin);
		scanf("%d", &p[i].ano);
		printf("Insira o preco: ");
		fflush(stdin);
		scanf("%f", &p[i].preco);
	}
	return p[2];
}

Automovel buscarPlaca(Automovel p[]) {
	char consulta[50];
	printf("Digite uma placa: ");
	fflush(stdin);
	gets(consulta);
	int i;
	for(i=0; i < 2; i++) {
		if(strcmp(p[i].placa, consulta) == 0) {
			printf("placa");
			puts(p[i].placa);
			printf("descricao");
			puts(p[i].descricao);
			printf("fabricante");
			puts(p[i].fabricante);
			printf("cor");
			puts(p[i].cor);
			printf("%d", p[i].ano);
			printf("%f \n", p[i].preco);
		}
		else printf("Não foi encontrado!");
	}
	return p[2];
}

Automovel registros(Automovel p[]) {
	int i;
	for(i=0; i < 2; i++) {
		puts(p[i].placa);
		puts(p[i].descricao);
		puts(p[i].fabricante);
		puts(p[i].cor);
		printf("%d", p[i].ano);
		printf("%f\n", p[i].preco);
	}
	return p[2];
}
int main() {
	int opcao;
	Automovel p[2];
	do {
		printf("Escolha uma opcao: \n");
		printf("(1) - Cadastrar veiculo \n(2) - Buscar placa \n(3) - Listar veiculos \n(4) - Sair \n Opcao: ");
		scanf("%d",&opcao);
		switch(opcao) {
		case 1:
			cadastrarAutomovel(p);
			break;
		case 2:
			buscarPlaca(p);
			break;
		case 3:
			registros(p);
			break;
		case 4:
			break;
		} 
	} while(opcao != 4);

	return 0;
}