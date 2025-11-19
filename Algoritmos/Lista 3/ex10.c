#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

void jogoAdivinhacao() {
    int numeroSecreto;
    int tentativa;
    int contadorTentativas = 0;

    printf("--- Jogo de Adivinhacao ---\n");

    printf("Jogador 1: Digite um numero secreto (inteiro positivo): ");
    scanf("%d", &numeroSecreto);

    if (numeroSecreto <= 0) {
        printf("Numero secreto invalido. Deve ser um inteiro positivo.\n");
        return;
    }

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("Ok, Jogador 2, um numero foi escolhido! Tente adivinhar.\n");

    do {
        printf("Jogador 2: Digite sua tentativa: ");
        scanf("%d", &tentativa);
        contadorTentativas++;

        if (tentativa < numeroSecreto) {
            printf("O numero e MAIOR.\n");
        } else if (tentativa > numeroSecreto) {
            printf("O numero e MENOR.\n");
        } else {
            printf("Parabens! Voce ACERTOU o numero %d!\n", numeroSecreto);
            printf("Voce utilizou %d tentativas.\n", contadorTentativas);
        }
    } while (tentativa != numeroSecreto);

    printf("---------------------------\n\n");
}

int main() {
    jogoAdivinhacao();
    return 0;
}