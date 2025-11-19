#include <stdio.h>


int verificarCaracteristica(int numero) { [cite: 19]
    int primeiraParte, segundaParte, somaDasPartes, quadradoDaSoma;

    if (numero < 1000 || numero > 9999) {
        return 0; 
    }

    primeiraParte = numero / 100; 
    segundaParte = numero % 100; 

    somaDasPartes = primeiraParte + segundaParte; [cite: 19]
    quadradoDaSoma = somaDasPartes * somaDasPartes; [cite: 19]

    if (quadradoDaSoma == numero) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    printf("Numeros de quatro algarismos com a caracteristica especial:\n"); [cite: 19]
    for (int i = 1000; i <= 9999; i++) { [cite: 19]
        if (verificarCaracteristica(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}