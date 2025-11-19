#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char caractereBusca;
    int contador = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Digite o caractere que deseja contar: ");
    scanf(" %c", &caractereBusca);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == caractereBusca) {
            contador++;
        }
    }

    printf("O caractere '%c' aparece %d vezes na string.\n", caractereBusca, contador);

    return 0;
}