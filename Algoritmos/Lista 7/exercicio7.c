#include <stdio.h>
#include <string.h>
#include <ctype.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char tipoFlor[20];
    int quantidade;
    float precoUnitario;
    char embalagemPresente[4];
    float precoCusto;
    float taxaEntrega;
    float precoVenda;

    printf("--- Cálculo de Vendas da Floricultura ---\n");

    printf("Tipo de flor (rosa, margarida, flores do campo): ");
    fgets(tipoFlor, sizeof(tipoFlor), stdin);
    tipoFlor[strcspn(tipoFlor, "\n")] = '\0';

    printf("Quantidade vendida: ");
    scanf("%d", &quantidade);
    limparBuffer();

    printf("Preço unitário: R$ ");
    scanf("%f", &precoUnitario);
    limparBuffer();

    do {
        printf("Haverá embalagem para presente (Sim/Não)? ");
        fgets(embalagemPresente, sizeof(embalagemPresente), stdin);
        embalagemPresente[strcspn(embalagemPresente, "\n")] = '\0';

        for (int i = 0; embalagemPresente[i] != '\0'; i++) {
            embalagemPresente[i] = tolower(embalagemPresente[i]);
        }

        if (strcmp(embalagemPresente, "sim") != 0 && strcmp(embalagemPresente, "nao") != 0) {
            printf("Resposta inválida. Por favor, digite 'Sim' ou 'Não'.\n");
        }
    } while (strcmp(embalagemPresente, "sim") != 0 && strcmp(embalagemPresente, "nao") != 0);

    precoCusto = quantidade * precoUnitario;

    taxaEntrega = precoCusto * 0.05;

    precoVenda = precoCusto + taxaEntrega;

    printf("\n--- Resumo da Venda ---\n");
    printf("Tipo de Flor: %s\n", tipoFlor);
    printf("Quantidade: %d\n", quantidade);
    printf("Preço Unitário: R$ %.2f\n", precoUnitario);
    printf("Embalagem para Presente: %s\n", (strcmp(embalagemPresente, "sim") == 0 ? "Sim" : "Não"));
    printf("Preço de Custo: R$ %.2f\n", precoCusto);
    printf("Taxa de Entrega (5%%): R$ %.2f\n", taxaEntrega);
    printf("Preço de Venda Total: R$ %.2f\n", precoVenda);

    return 0;
}