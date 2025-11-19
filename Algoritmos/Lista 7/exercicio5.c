#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[200];
    int espacosEmBranco = 0;
    int outrosCaracteres = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    for (int i = 0; frase[i] != '\0'; i++) {
        if (isspace(frase[i])) {
            espacosEmBranco++;
        } else {
            outrosCaracteres++;
        }
    }

    printf("Número de espaços em branco: %d\n", espacosEmBranco);
    printf("Número de caracteres diferentes de espaço: %d\n", outrosCaracteres);

    return 0;
}