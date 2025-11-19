#include <stdio.h>

void exibirDivisiveisPorQuatro() {
    printf("--- Numeros divisiveis por 4 menores que 200 ---\n");
    for (int i = 0; i < 200; i += 4) {
        printf("%d\n", i);
    }
    printf("-----------------------------------------------\n\n");
}

int main() {
    exibirDivisiveisPorQuatro();
    return 0;
}