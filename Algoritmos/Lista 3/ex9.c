#include <stdio.h>

void numerosComRestoCinco() {
    printf("--- Numeros entre 1000 e 1999 que divididos por 11 tem resto 5 ---\n");
    for (int i = 1000; i <= 1999; i++) {
        if (i % 11 == 5) {
            printf("%d\n", i);
        }
    }
    printf("------------------------------------------------------------------\n\n");
}

int main() {
    numerosComRestoCinco();
    return 0;
}