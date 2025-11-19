/******************************************************************************

15.	Calcular a quantidade de litros de combustível gasta em uma viagem, 
utilizando um automóvel que faz 12km por litro. 
Para obter o cálculo, o usuário deve fornecer o tempo gasto e a velocidade média durante a viagem.
Desta forma, será possível obter a distância percorrida com a fórmula:
distância = tempo x velocidade
Tendo o valor da distância, basta calcular a quantidade de litros de combustível utilizada 
na viagem com a fórmula: Litros_usados = distância/ 12
O programa deve apresentar os valores da velocidade média, tempo gasto na viagem, 
distância percorrida e a quantidade de litros utilizada na viagem.

*******************************************************************************/
#include <stdio.h>
int main () {
    
    int tempoGasto;
    float velocidadeMedia, distancia, litros_usados;
    printf("Insira o tempo gasto em horas: ");
    scanf("%d",&tempoGasto);
    
    printf("Insira a velocidade media: ");
    scanf("%f",&velocidadeMedia);
    
    distancia = tempoGasto * velocidadeMedia;
    litros_usados = distancia / 12;
    
    printf("A velocidade media eh: %.1f , \n o tempo gasto na viagem eh: %d \n", velocidadeMedia, tempoGasto);
    printf("A distancia percorrida eh: %.1f \n Quantidade de litros usada eh: %.1f", distancia, litros_usados);
    
return 0;
}
    
