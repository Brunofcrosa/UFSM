#include <stdio.h>
#include <ctype.h> 

void analisarGrupo() {
    int i;
    float altura;
    char sexo;
    float maiorAltura = 0.0f;
    float menorAltura = 99999.0f; 
    float somaAlturasMulheres = 0.0f;
    int contadorMulheres = 0;
    float somaAlturasTotal = 0.0f;

    printf("--- Analise de Grupo (10 Pessoas) ---\n");

    for (i = 1; i <= 10; i++) {
        printf("Pessoa %d:\n", i);
        printf("  Digite a altura (em metros, ex: 1.75): ");
        scanf("%f", &altura);

        printf("  Digite o sexo (M/F): ");
        scanf(" %c", &sexo);
        sexo = toupper(sexo);

        if (altura <= 0) {
            printf("Altura invalida. Por favor, digite uma altura positiva.\n");
            i--; 
            continue;
        }
        if (sexo != 'M' && sexo != 'F') {
            printf("Sexo invalido. Por favor, digite M ou F.\n");
            i--; 
            continue;
        }

        
        if (altura > maiorAltura) {
            maiorAltura = altura;
        }
        if (altura < menorAltura) {
            menorAltura = altura;
        }

        
        if (sexo == 'F') {
            somaAlturasMulheres += altura;
            contadorMulheres++;
        }

    
        somaAlturasTotal += altura;
    }

    printf("\n--- Resultados da Analise ---\n");
    printf("a) Maior altura do grupo: %.2f m\n", maiorAltura);
    printf("   Menor altura do grupo: %.2f m\n", menorAltura);

    if (contadorMulheres > 0) {
        printf("b) Media das alturas das mulheres: %.2f m\n", somaAlturasMulheres / contadorMulheres);
    } else {
        printf("b) Nenhuma mulher foi informada para calcular a media das alturas.\n");
    }

    printf("c) Media das alturas de todos do grupo: %.2f m\n", somaAlturasTotal / 10.0f);
    printf("-------------------------------------\n\n");
}

int main() {
    analisarGrupo();
    return 0;
}