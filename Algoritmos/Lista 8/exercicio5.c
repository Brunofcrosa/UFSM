#include <stdio.h>
#include <string.h>

#define NUM_ENTREVISTADOS 5

typedef struct {
    char sexo;
    int idade;
    int livrosLidos;
} Entrevistado;

Entrevistado pesquisa[NUM_ENTREVISTADOS];

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void imprimirEntrevistado(const Entrevistado *e) {
    printf("Sexo: %c, Idade: %d, Livros Lidos: %d\n", e->sexo, e->idade, e->livrosLidos);
}

int main() {
    int opcao;
    int i;

    printf("Cadastro de Entrevistados (%d Pessoas):\n", NUM_ENTREVISTADOS);
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
    }

    do {
        printf("\n--- Menu de Relatórios ---\n");
        printf("1. Ordem inversa de registro\n");
        printf("2. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                printf("\n--- Relatório: Ordem Inversa de Registro ---\n");
                for (i = NUM_ENTREVISTADOS - 1; i >= 0; i--) {
                    imprimirEntrevistado(&pesquisa[i]);
                }
                break;
            case 2:
                printf("Saindo do programa de relatórios.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 2);

    return 0;
}