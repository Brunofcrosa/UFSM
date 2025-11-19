#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    char tipoConversao;
    int i;

    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    do {
        printf("Deseja converter para (m)aiúsculas ou mi(n)úsculas? ");
        scanf(" %c", &tipoConversao);

        if (tipoConversao >= 'A' && tipoConversao <= 'Z') {
            tipoConversao = tipoConversao + 32;
        }

        if (tipoConversao != 'm' && tipoConversao != 'n') {
            printf("Opção inválida. Por favor, digite 'm' ou 'n'.\n");
        }
    } while (tipoConversao != 'm' && tipoConversao != 'n');

    if (tipoConversao == 'm') {
        for (i = 0; palavra[i] != '\0'; i++) {
            if (palavra[i] >= 'a' && palavra[i] <= 'z') {
                palavra[i] = palavra[i] - 32;
            }
        }
        printf("Palavra em maiúsculas: %s\n", palavra);
    } else {
        for (i = 0; palavra[i] != '\0'; i++) {
            if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
                palavra[i] = palavra[i] + 32;
            }
        }
        printf("Palavra em minúsculas: %s\n", palavra);
    }

    return 0;
}