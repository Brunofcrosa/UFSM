#include <stdio.h>
#include <string.h>

typedef struct {
    char rua[50];
    int numero;
    char cidade[30];
    char estado[3]; 
    char cep[10];   
} Endereco;


typedef struct {
    char nome[50];
    int idade;
    Endereco enderecoResidencial; 
    char telefone[15];
} Pessoa;

int main() {
    Pessoa p1;


    strcpy(p1.nome, "João Silva");
    p1.idade = 30;
    strcpy(p1.telefone, "11987654321");


    strcpy(p1.enderecoResidencial.rua, "Rua das Flores");
    p1.enderecoResidencial.numero = 123;
    strcpy(p1.enderecoResidencial.cidade, "São Paulo");
    strcpy(p1.enderecoResidencial.estado, "SP");
    strcpy(p1.enderecoResidencial.cep, "01234-567");


    printf("Nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Telefone: %s\n", p1.telefone);
    printf("Endereço: %s, %d - %s, %s, CEP: %s\n",
           p1.enderecoResidencial.rua,
           p1.enderecoResidencial.numero,
           p1.enderecoResidencial.cidade,
           p1.enderecoResidencial.estado,
           p1.enderecoResidencial.cep);

    return 0;
}