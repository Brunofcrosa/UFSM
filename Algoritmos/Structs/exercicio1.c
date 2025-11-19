/** 1. Faça um algoritmo com uma função que receba os campos nome, endereço e email de
contato de uma pessoa e armazene-os em um registro. Depois, listar os dados na tela.
**/
#include <stdio.h>
#include <string.h>

typedef struct Dados {
	char nome[50];
	char endereco[50];
	char email[50];
}Dados;

Dados pegarDados(Dados p) {
	printf("Insira o nome: ");
	fflush(stdin);
	gets(p.nome);
	printf("Insira o endereco: ");
	fflush(stdin);
	gets(p.endereco);
	printf("Insira o email: ");
	fflush(stdin);
	gets(p.email);
	return p;
}

Dados listarDados(Dados p) {
	puts(p.nome);
	puts(p.endereco);
	puts(p.email);
	return p;
}

int main() {
	Dados p;
	p = pegarDados(p);
	listarDados(p);
	return 0;
}