| Função                  | Descrição                                        |
| ----------------------- | ------------------------------------------------ |
| `strlen(str)`           | Retorna o tamanho da string (sem contar o `\0`). |
| `strcpy(dest, src)`     | Copia a string `src` para `dest`.                |
| `strncpy(dest, src, n)` | Copia até `n` caracteres de `src` para `dest`.   |

| Função                  | Descrição                                                |
| ----------------------- | -------------------------------------------------------- |
| `strcat(dest, src)`     | Adiciona `src` ao final de `dest`.                       |
| `strncat(dest, src, n)` | Adiciona até `n` caracteres de `src` ao final de `dest`. |

| Função                   | Descrição                                         |
| ------------------------ | ------------------------------------------------- |
| `strcmp(str1, str2)`     | Compara duas strings (retorna 0 se forem iguais). |
| `strncmp(str1, str2, n)` | Compara até `n` caracteres.                       |

| Função                | Descrição                                                                      |
| --------------------- | ------------------------------------------------------------------------------ |
| `strchr(str, c)`      | Retorna ponteiro para a primeira ocorrência de `c` em `str`.                   |
| `strrchr(str, c)`     | Retorna ponteiro para a última ocorrência de `c`.                              |
| `strstr(str, substr)` | Retorna ponteiro para a primeira ocorrência de `substr` em `str`.              |
| `strpbrk(str, chars)` | Retorna ponteiro para o primeiro caractere de `str` que esteja em `chars`.     |
| `strspn(str, chars)`  | Retorna o comprimento do trecho inicial de `str` só com caracteres de `chars`. |
| `strcspn(str, chars)` | Retorna o comprimento até encontrar algum caractere de `chars`.                |

| Função                  | Descrição                                                 |
| ----------------------- | --------------------------------------------------------- |
| `memcpy(dest, src, n)`  | Copia `n` bytes de `src` para `dest`.                     |
| `memset(ptr, c, n)`     | Preenche os `n` primeiros bytes de `ptr` com o valor `c`. |
| `memcmp(ptr1, ptr2, n)` | Compara os primeiros `n` bytes entre `ptr1` e `ptr2`.     |

#include <stdio.h>
#include <string.h>

int main() {
    char nome1[20] = "Bruno";
    char nome2[20];

    strcpy(nome2, nome1);  // Copia nome1 para nome2

    strcat(nome2, " Fetzer");  // Adiciona sobrenome

    printf("Nome completo: %s\n", nome2);
    printf("Tamanho: %lu\n", strlen(nome2));

    if (strcmp(nome1, "Bruno") == 0) {
        printf("Nome1 é Bruno.\n");
    }

    return 0;
}
