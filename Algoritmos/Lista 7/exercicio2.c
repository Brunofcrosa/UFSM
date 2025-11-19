#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palavra[100];
    char tipoConversao;

    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    do {
        printf("Deseja converter para (m)aiúsculas ou mi(n)úsculas? ");
        scanf(" %c", &tipoConversao);

        tipoConversao = tolower(tipoConversao);

        if (tipoConversao != 'm' && tipoConversao != 'n') {
            printf("Opção inválida. Por favor, digite 'm' ou 'n'.\n");
        }
    } while (tipoConversao != 'm' && tipoConversao != 'n');

    if (tipoConversao == 'm') {
        for (int i = 0; palavra[i] != '\0'; i++) {
            palavra[i] = toupper(palavra[i]);
        }
        printf("Palavra em maiúsculas: %s\n", palavra);
    } else {
        for (int i = 0; palavra[i] != '\0'; i++) {
            palavra[i] = tolower(palavra[i]);
        }
        printf("Palavra em minúsculas: %s\n", palavra);
    }

    return 0;
}