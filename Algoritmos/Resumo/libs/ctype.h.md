| Função        | Descrição                                                     |
| ------------- | ------------------------------------------------------------- |
| `isalpha(c)`  | Retorna verdadeiro se `c` for uma letra (A–Z ou a–z).         |
| `isdigit(c)`  | Retorna verdadeiro se `c` for um dígito (0–9).                |
| `isalnum(c)`  | Retorna verdadeiro se `c` for alfanumérico (letra ou número). |
| `isspace(c)`  | Retorna verdadeiro se `c` for espaço, tab, nova linha, etc.   |
| `islower(c)`  | Verdadeiro se `c` for letra minúscula.                        |
| `isupper(c)`  | Verdadeiro se `c` for letra maiúscula.                        |
| `ispunct(c)`  | Verdadeiro se `c` for um caractere de pontuação.              |
| `isxdigit(c)` | Verdadeiro se `c` for um dígito hexadecimal (0–9, A–F, a–f).  |

| Função       | Descrição                                 |
| ------------ | ----------------------------------------- |
| `tolower(c)` | Converte `c` para minúscula, se possível. |
| `toupper(c)` | Converte `c` para maiúscula, se possível. |


#include <stdio.h>
#include <ctype.h>

int main() {
    char c;

    printf("Digite um caractere: ");
    scanf("%c", &c);

    if (isalpha(c)) {
        printf("É uma letra!\n");

        if (isupper(c))
            printf("Letra maiúscula.\n");
        else
            printf("Letra minúscula.\n");
    } else if (isdigit(c)) {
        printf("É um dígito!\n");
    } else if (isspace(c)) {
        printf("É um espaço em branco!\n");
    } else {
        printf("Outro tipo de caractere.\n");
    }

    printf("Versão maiúscula: %c\n", toupper(c));
    printf("Versão minúscula: %c\n", tolower(c));

    return 0;
}
