#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char caractereParaSubstituir;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Digite o caractere que deseja substituir por '*': ");
    scanf(" %c", &caractereParaSubstituir);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == caractereParaSubstituir) {
            str[i] = '*';
        }
    }

    printf("String modificada: %s\n", str);

    return 0;
}