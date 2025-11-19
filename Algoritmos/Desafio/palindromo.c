/** Desenvolver um programa em C que realize análises básicas em uma frase fornecida pelo usuário. O programa deverá ser capaz de:

Validar Palíndromo: Verificar se a frase (desconsiderando espaços e a capitalização) é um palíndromo.
Contar Vogais e Consoantes: Contar o número de vogais e consoantes presentes na frase.
Contar Palavras: Contar o número de palavras na frase.
Observações: utilizar funções para resolver o exercício. O programa deve rodar até que o utilizador decida por encerrá-lo.
**/
#include <stdio.h>
#include <string.h>

int ehLetra(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

char converterParaMinusculo(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int ehPalindromo(char *frase) {
    int inicio = 0;
    int fim = strlen(frase) - 1;

    while (inicio < fim) {
        while (inicio < fim && !ehLetra(frase[inicio])) {
            inicio++;
        }
        while (inicio < fim && !ehLetra(frase[fim])) {
            fim--;
        }

        if (converterParaMinusculo(frase[inicio]) != converterParaMinusculo(frase[fim])) {
            return 0;
        }

        inicio++;
        fim--;
    }

    return 1;
}

void contarVogaisConsoantes(char *frase, int *vogais, int *consoantes) {
    *vogais = 0;
    *consoantes = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        char c = converterParaMinusculo(frase[i]);

        if (ehLetra(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                (*vogais)++;
            } else {
                (*consoantes)++;
            }
        }
    }
}

int contarPalavras(char *frase) {
    int contador = 0;
    int dentroDaPalavra = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        char c = frase[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!dentroDaPalavra) {
                contador++;
                dentroDaPalavra = 1;
            }
        } else {
            dentroDaPalavra = 0;
        }
    }

    return contador;
}

int main() {
    char frase[1000];
    char resposta;

    do {
        printf("Digite uma frase: ");
        fgets(frase, 1000, stdin);
        frase[strcspn(frase, "\n")] = '\0';

        if (ehPalindromo(frase)) {
            printf("A frase eh um palindromo.\n");
        } else {
            printf("A frase NAO eh um palindromo.\n");
        }

        int vogais, consoantes;
        contarVogaisConsoantes(frase, &vogais, &consoantes);
        printf("Numero de vogais: %d\n", vogais);
        printf("Numero de consoantes: %d\n", consoantes);

        int palavras = contarPalavras(frase);
        printf("Numero de palavras: %d\n", palavras);

        printf("\nDeseja analisar outra frase? (s/n): ");
        scanf(" %c", &resposta);
        getchar();

    } while (resposta == 's' || resposta == 'S');

    printf("Programa encerrado. Obrigado!\n");

    return 0;
}