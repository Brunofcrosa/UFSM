/******************************************************************************

18.	Elaborar um programa que apresente o valor da conversão em real (R$) de um valor
lido em dólar (US$). O programa deve solicitar o valor da cotação do dólar e também a
quantidade de dólares disponível com o usuário. 
*******************************************************************************/
#include <stdio.h>
int main () {
    float dolar, quantidadeDolar;
    printf("Insira a cotacao do dolar: ");
    scanf("%f",&dolar);
    printf("Insira a quantidade de dolares que possui: ");
    scanf("%f",&quantidadeDolar);
 
    
    printf("Voce possui R$ %.2f ", quantidadeDolar * dolar);
    
return 0;
}