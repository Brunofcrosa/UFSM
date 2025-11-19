/** 3.Desenvolva um algoritmo que faça a leitura de dois números inteiros e chame uma
função para verificar se são valores primos. Caso não sejam, altere os valores das
variáveis para armazenar os próximos primos a partir dos valores lidos. Exemplo:
valores lidos: x = 4 e y = 9. (Não são primos)
x = 5 e y = 11 (as variáveis recebem estes valores, pois 5 é o próximo primo
depois de 4 e 11 é o próximo primo depois de 9)  
**/
#include <stdio.h>

int primo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void paraPrimo(int *x, int *y) {
    while (!primo(*x)) {
        (*x)++;
    }
    while (!primo(*y)) {
        (*y)++;
    }
}

int main() {
    int x, y;

    printf("Insira: ");
    scanf("%d %d", &x, &y);

    paraPrimo(&x, &y); 

    printf("Proximos primos: %d %d\n", x, y);

    return 0;
}
