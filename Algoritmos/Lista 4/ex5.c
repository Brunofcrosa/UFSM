#include <stdio.h>


float calcularMedia(float n1, float n2, float n3, char tipo) { [cite: 6]
    float media;

    if (tipo == 'A' || tipo == 'a') { [cite: 7]
        media = (n1 + n2 + n3) / 3.0;
    } else if (tipo == 'P' || tipo == 'p') { [cite: 7]
        media = (n1 * 5 + n2 * 3 + n3 * 2) / (5 + 3 + 2); 
    } else {
        printf("Tipo de media invalido. Retornando 0.\n");
        media = 0.0;
    }
    return media;
}

int main() {
    float nota1, nota2, nota3;
    char tipoMedia;
    float resultadoMedia;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("Digite o tipo de media (A para Aritmetica, P para Ponderada): ");
    scanf(" %c", &tipoMedia); 

    resultadoMedia = calcularMedia(nota1, nota2, nota3, tipoMedia); [cite: 8]

    printf("A media calculada e: %.2f\n", resultadoMedia); [cite: 8]

    return 0;
}