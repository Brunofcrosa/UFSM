/******************************************************************************

13.	Calcular o volume de uma lata de óleo utilizando a fórmula: volume = 3.14159 x r² x Altura.

*******************************************************************************/
#include <stdio.h>
#define volume 3.14159
int main() {
    float raio, altura, resultado;
    
    printf("Insira a altura: ");
    scanf("%f",&altura);
    
    printf("Insira o raio: ");
    scanf("%f",&raio);
    resultado = volume * (raio * raio) * altura;
    printf("O resultado eh: %f", resultado);
return 0;
    
}