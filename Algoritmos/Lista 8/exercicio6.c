#include <stdio.h>
#include <string.h>

#define NUM_TECIDOS 8

typedef struct {
    int codigo;
    char descricao[50];
    float precoMetro;
    int quantidadeEstoque;
} Tecido;

Tecido loteTecidos[NUM_TECIDOS];

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarTecidos() {
    int i;
    printf("Cadastro de %d Tecidos:\n", NUM_TECIDOS);
    for (i = 0; i < NUM_TECIDOS; i++) {
        printf("\nDados do Tecido %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &loteTecidos[i].codigo);
        limparBufferEntrada();

        printf("Descrição: ");
        fgets(loteTecidos[i].descricao, sizeof(loteTecidos[i].descricao), stdin);
        loteTecidos[i].descricao[strcspn(loteTecidos[i].descricao, "\n")] = '\0';

        printf("Preço do Metro: R$ ");
        scanf("%f", &loteTecidos[i].precoMetro);
        limparBufferEntrada();

        printf("Quantidade em Estoque (metros): ");
        scanf("%d", &loteTecidos[i].quantidadeEstoque);
        limparBufferEntrada();
    }
}

void relatorioColunas() {
    int i;
    printf("\n--- Relatório de Tecidos (em Colunas) ---\n");
    printf("%-8s %-30s %-15s %-10s\n", "Código", "Descrição", "Preço/Metro", "Estoque");
    printf("-------- ------------------------------ --------------- ----------\n");
    for (i = 0; i < NUM_TECIDOS; i++) {
        printf("%-8d %-30s %-15.2f %-10d\n",
               loteTecidos[i].codigo,
               loteTecidos[i].descricao,
               loteTecidos[i].precoMetro,
               loteTecidos[i].quantidadeEstoque);
    }
}

void relatorioEstoqueBaixo() {
    int i;
    int encontrou = 0;
    printf("\n--- Relatório: Estoque Inferior a 50 Metros ---\n");
    for (i = 0; i < NUM_TECIDOS; i++) {
        if (loteTecidos[i].quantidadeEstoque < 50) {
            printf("Código: %d, Descrição: %s, Estoque: %d metros\n",
                   loteTecidos[i].codigo, loteTecidos[i].descricao, loteTecidos[i].quantidadeEstoque);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum tecido com estoque inferior a 50 metros.\n");
    }
}

void relatorioPrecoBaixo() {
    int i;
    int encontrou = 0;
    printf("\n--- Relatório: Preço do Metro Inferior a R$ 0,60 ---\n");
    for (i = 0; i < NUM_TECIDOS; i++) {
        if (loteTecidos[i].precoMetro < 0.60) {
            printf("Código: %d, Descrição: %s, Preço/Metro: R$ %.2f\n",
                   loteTecidos[i].codigo, loteTecidos[i].descricao, loteTecidos[i].precoMetro);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum tecido com preço do metro inferior a R$ 0,60.\n");
    }
}

int main() {
    cadastrarTecidos();
    relatorioColunas();
    relatorioEstoqueBaixo();
    relatorioPrecoBaixo();
    return 0;
}