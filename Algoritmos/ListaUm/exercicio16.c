/******************************************************************************

16.	Ler três valores numéricos inteiros e apresentar o resultado das adições e
multiplicações utilizando a propriedade distributiva para a máxima combinação possível
entre as três variáveis. Por exemplo, considerando o uso das variáveis A, B e C, 
devem ser feitas três adições e três multiplicações, ou seja, deve ser combinada 
a variável A com B, A com C e B com C.
*******************************************************************************/
#include <stdio.h>
int main () {
    int num1, num2, num3;
    int adicaoAB,adicaoAC,adicaoBC;
    int multiplicacaoAB,multiplicacaoAC, multiplicacaoBC;
    printf("Insira o primeiro numero inteiro(A): ");
    scanf("%d",&num1);
    printf("Insira o segundo numero inteiro(B): ");
    scanf("%d",&num2);
    printf("Insira o terceiro numero inteiro(C): ");
    scanf("%d",&num3);
    
    adicaoAB = num1 + num2;
    adicaoAC = num1 + num3;
    adicaoBC = num2 + num3;
    
    multiplicacaoAB = num1 * num2;
    multiplicacaoAC = num1 * num3;
    multiplicacaoBC = num2 * num3;
    printf("O resultado de A + B = %d \n",adicaoAB);
    printf("O resultado de A + C = %d \n",adicaoAC);
    printf("O resultado de B + C = %d \n",adicaoBC);
    printf("O resultado de A * B = %d \n",multiplicacaoAB);
    printf("O resultado de A * C = %d \n",multiplicacaoAC);
    printf("O resultado de B * C = %d \n",multiplicacaoBC);
    
return 0;
}
    
