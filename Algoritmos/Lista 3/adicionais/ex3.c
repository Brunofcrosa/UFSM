#include <stdio.h>
#include <stdlib.h> 

void encontrarMenorDiferenca() {
    int x = 5000;
    int y = 25;
    int menorDiferenca = abs(x - y);
    int xComMenorDiferenca = x;
    int yComMenorDiferenca = y;
    int diferencaAtual;

    while (1) {
        x += 4;
        y += 7;
        diferencaAtual = abs(x - y);

        if (diferencaAtual < menorDiferenca) {
            menorDiferenca = diferencaAtual;
            xComMenorDiferenca = x;
            yComMenorDiferenca = y;
        } else if (diferencaAtual > menorDiferenca && y > x) { 
             break; 
        } else if (x > 1000000 || y > 1000000) { 
            break;
        }
    }

    printf("Os valores de X e Y com a menor diferenca sao:\n");
    printf("X = %d\n", xComMenorDiferenca);
    printf("Y = %d\n", yComMenorDiferenca);
    printf("Menor diferenca encontrada: %d\n", menorDiferenca);
}

int main() {
    encontrarMenorDiferenca();
    return 0;
}