#include <stdio.h>
#include <string.h> 

void obterCategoriaNadador(int idade) {
    if (idade >= 5 && idade <= 7) { [cite: 2]
        printf("Categoria: Infantil A\n"); [cite: 2]
    } else if (idade >= 8 && idade <= 10) { [cite: 2]
        printf("Categoria: Infantil B\n"); [cite: 2]
    } else if (idade >= 11 && idade <= 13) { [cite: 2]
        printf("Categoria: Juvenil A\n"); [cite: 2]
    } else if (idade >= 14 && idade <= 17) { [cite: 2]
        printf("Categoria: Juvenil B\n"); [cite: 2]
    } else if (idade >= 18) { [cite: 2]
        printf("Categoria: Adulto\n"); [cite: 2]
    } else {
        printf("Idade fora das categorias validas (minimo de 5 anos).\n");
    }
}

int main() {
    int idadeNadador;

    printf("Digite a idade do nadador: ");
    scanf("%d", &idadeNadador);

    obterCategoriaNadador(idadeNadador);

    return 0;
}