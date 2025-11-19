#include <stdio.h>
#include <string.h>

#define NUM_ENTREVISTADOS 20

typedef struct {
    char sexo;
    int idade;
    int livrosLidos;
} Entrevistado;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Entrevistado pesquisa[NUM_ENTREVISTADOS];
    int totalLivrosMenores10 = 0;
    int mulheres5ouMaisLivros = 0;
    int pessoasNaoLeram = 0;
    int i;

    printf("Pesquisa de Leitura de Livros (20 Entrevistados):\n");
    for (i = 0; i < NUM_ENTREVISTADOS; i++) {
        printf("\nDados do Entrevistado %d:\n", i + 1);
        do {
            printf("Sexo (M/F): ");
            scanf(" %c", &pesquisa[i].sexo);
            limparBufferEntrada();
            if (pesquisa[i].sexo >= 'a' && pesquisa[i].sexo <= 'z') {
                pesquisa[i].sexo = pesquisa[i].sexo - 32;
            }
            if (pesquisa[i].sexo != 'M' && pesquisa[i].sexo != 'F') {
                printf("Sexo inválido. Digite 'M' ou 'F'.\n");
            }
        } while (pesquisa[i].sexo != 'M' && pesquisa[i].sexo != 'F');

        printf("Idade: ");
        scanf("%d", &pesquisa[i].idade);
        limparBufferEntrada();

        printf("Quantidade de livros lidos em 2020: ");
        scanf("%d", &pesquisa[i].livrosLidos);
        limparBufferEntrada();

        if (pesquisa[i].idade < 10) {
            totalLivrosMenores10 += pesquisa[i].livrosLidos;
        }

        if (pesquisa[i].sexo == 'F' && pesquisa[i].livrosLidos >= 5) {
            mulheres5ouMaisLivros++;
        }

        if (pesquisa[i].livrosLidos == 0) {
            pessoasNaoLeram++;
        }
    }

    printf("\n--- Resultados da Pesquisa ---\n");
    printf("a) Quantidade total de livros lidos pelos entrevistados menores de 10 anos: %d\n", totalLivrosMenores10);
    printf("b) Quantidade de mulheres que leram 5 livros ou mais: %d\n", mulheres5ouMaisLivros);
    
    if (NUM_ENTREVISTADOS > 0) {
        float percentualNaoLeram = (float)pessoasNaoLeram / NUM_ENTREVISTADOS * 100;
        printf("c) Percentual de pessoas que não leram livros: %.2f%%\n", percentualNaoLeram);
    } else {
        printf("c) Não há entrevistados para calcular o percentual.\n");
    }

    return 0;
}