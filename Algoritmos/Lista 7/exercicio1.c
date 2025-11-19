#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];

    printf("Digite uma string em letras maiúsculas: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    printf("String em minúsculas: %s\n", str);

    return 0;
}