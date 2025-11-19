#include <stdio.h>
void contarNumeros() 
{
    int numeros[15], i, count = 0;
    
    for (i = 0; i < 15; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        
        if (numeros[i] > 5) {
            count++;
        }
    }
    printf("Total de numeros maiores que 5: %d\n", count);
}

int main() {
    contarNumeros();
    return 0;
}