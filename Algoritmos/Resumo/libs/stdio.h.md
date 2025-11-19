| Função       | Descrição                                 |
| ------------ | ----------------------------------------- |
| `printf()`   | Imprime na tela (console).                |
| `putchar(c)` | Imprime um caractere.                     |
| `puts(str)`  | Imprime uma string (com quebra de linha). |

| Função      | Descrição                               |
| ----------- | --------------------------------------- |
| `scanf()`   | Lê valores formatados do teclado.       |
| `getchar()` | Lê um caractere do teclado.             |
| `gets()`    | Lê uma string (evite usar, é insegura). |
| `fgets()`   | Lê uma string com segurança.            |

| Função                 | Descrição                            |
| ---------------------- | ------------------------------------ |
| `fopen()`              | Abre um arquivo.                     |
| `fclose()`             | Fecha um arquivo.                    |
| `fprintf()`            | Escreve dados formatados em arquivo. |
| `fscanf()`             | Lê dados formatados de arquivo.      |
| `fgets()` / `fputs()`  | Lê / escreve strings em arquivos.    |
| `fread()` / `fwrite()` | Lê / escreve blocos binários.        |

#include <stdio.h>

int main() {
    char nome[50];
    int idade;

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Olá %sVocê tem %d anos.\n", nome, idade);

    return 0;
}
