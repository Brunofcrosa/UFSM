/******************************************************************************


12.	Ler a temperatura em graus Celsius e apresentá-la convertida em Fahrenheit. 
A fórmula de conversão é:
Fahrenheit = 9 x Celsius + 160
5


*******************************************************************************/

#include <stdio.h>

int main(){
    
    float temperaturaCelsius, temperaturaFahrenheit;
    
    printf("Insira a temperatura em graus Celsius: ");
    scanf("%f",&temperaturaCelsius);
    
    printf("Em Fahrenheit eh:%.2f ", (9*temperaturaCelsius+160)/5);
return 0;
}