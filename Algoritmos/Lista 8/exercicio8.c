#include <stdio.h>
#include <string.h>

#define MAX_PECAS 1000
#define CODIGO_ENCERRAMENTO -999

typedef struct {
    int codigo;
    float precoUnitario;
    char descricao[100];
    int quantidadeEstoque;
} Peca;

Peca estoque[MAX_PECAS];
int totalPecas = 0;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarPecas() {
    int codigoLido;
    printf("Cadastro de Peças (digite %d para encerrar):\n", CODIGO_ENCERRAMENTO);
    while (totalPecas < MAX_PECAS) {
        printf("\nCódigo da Peça: ");
        scanf("%d", &codigoLido);
        limparBufferEntrada();

        if (codigoLido == CODIGO_ENCERRAMENTO) {
            break;
        }

        estoque[totalPecas].codigo = codigoLido;

        printf("Descrição da Peça: ");
        fgets(estoque[totalPecas].descricao, sizeof(estoque[totalPecas].descricao), stdin);
        estoque[totalPecas].descricao[strcspn(estoque[totalPecas].descricao, "\n")] = '\0';

        printf("Preço Unitário: R$ ");
        scanf("%f", &estoque[totalPecas].precoUnitario);
        limparBufferEntrada();

        printf("Quantidade Disponível em Estoque: ");
        scanf("%d", &estoque[totalPecas].quantidadeEstoque);
        limparBufferEntrada();

        totalPecas++;
    }
    printf("Cadastro de peças encerrado.\n");
}

void exibirPecasComEstoqueBaixo() {
    int x;
    int i;
    int encontrou = 0;

    if (totalPecas == 0) {
        printf("Nenhuma peça cadastrada.\n");
        return;
    }

    printf("\nDigite a quantidade X para filtrar peças com estoque inferior a X: ");
    scanf("%d", &x);
    limparBufferEntrada();

    printf("\n--- Peças com Menos de %d Unidades em Estoque ---\n", x);
    for (i = 0; i < totalPecas; i++) {
        if (estoque[i].quantidadeEstoque < x) {
            printf("Código: %d, Descrição: %s, Estoque: %d, Preço: R$ %.2f\n",
                   estoque[i].codigo, estoque[i].descricao, estoque[i].quantidadeEstoque, estoque[i].precoUnitario);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhuma peça encontrada com estoque inferior a %d unidades.\n", x);
    }
}

int main() {
    cadastrarPecas();
    exibirPecasComEstoqueBaixo();
    return 0;
}