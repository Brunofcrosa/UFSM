/** 1. Faça um algoritmo com uma função que receba os campos nome, endereço e email de
contato de uma pessoa e armazene-os em um registro. Depois, listar os dados na tela.
**/
#include <stdio.h>
#include <string.h>

typedef struct Registro {
	char nome[50];
	char endereco[50];
	char email[50];
} Registro;

Registro lerDados(Registro p) {
	fflush(stdin);
	gets(p.nome);
	fflush(stdin);
	gets(p.endereco);
	fflush(stdin);
	gets(p.email);
	return p;
}

Registro mostrarDados(Registro p) {
	puts(p.nome);
	puts(p.endereco);
	puts(p.email);
	return p;
}

int main() {
	Registro p;
	p = lerDados(p);
	mostrarDados(p);
	return 0;
}
