#include <stdio.h>

void contarDez() {
    int numero;
    int contadorDez = 0;

    printf("--- Contagem de Numeros 10 (digite 0 para parar) ---\n");
    do {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        if (numero == 10) {
            contadorDez++;
        }
    } while (1); 

    printf("O numero 10 foi digitado %d vezes.\n", contadorDez);
    printf("--------------------------------------------------\n\n");
}

int main() {
    contarDez();
    return 0;
}