#include <stdio.h>

void lerValoresCrescentes() {
    int valorAnterior = 0; 
    int valorAtual;
    char continuar;

    printf("Este programa so permite a leitura de valores maiores que os anteriores.\n");
    printf("Digite 'n' ou 'N' a qualquer momento para parar.\n");

    do {
        printf("Digite um valor inteiro (deve ser maior que %d): ", valorAnterior);

        if (scanf(" %c", &continuar) == 1 && (continuar == 'n' || continuar == 'N')) {
            break; 
        }

        ungetc(continuar, stdin); 
        if (scanf("%d", &valorAtual) != 1) {
            printf("Entrada invalida. Por favor, digite um numero inteiro ou 'n' para parar.\n");

            while (getchar() != '\n');
            continue; 
        }


        if (valorAtual > valorAnterior) {
            valorAnterior = valorAtual;
            printf("Valor aceito.\n");
        } else {
            printf("Valor nao aceito. Deve ser maior que o valor anterior.\n");
        }

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar); 

    } while (continuar == 's' || continuar == 'S');

    printf("Programa encerrado.\n");
}

int main() {
    lerValoresCrescentes();
    return 0;
}