/** Desenvolver um programa que possua a função alteraValores() para realizar a troca
dos valores de duas variáveis. Essa função recebe os endereços das variáveis passadas
pela função main(), armazenando-os nos ponteiros p1 e p2. Dentro da função, trocamse os conteúdos dos endereços, retornando para a função chamadora, onde deverão
ser impressos
**/
#include <stdio.h>

void alteraValores(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int a, b;
    printf("Insira o valor de a: ");
    scanf("%d", &a);
    printf("Insira o valor de b: ");
    scanf("%d", &b);

    printf("Antes da troca: a = %d, b = %d\n", a, b);

    alteraValores(&a, &b);

    printf("Depois da troca: a = %d, b = %d\n", a, b);

    return 0;
}