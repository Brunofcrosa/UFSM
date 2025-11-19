#include <stdio.h>
#include <string.h>

#define NUM_MESES 12

typedef struct {
    char nomeMes[15];
    float gastoAgua;
    float gastoEnergia;
    float gastoTelefone;
} GastoMensal;

GastoMensal gastos[NUM_MESES];

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int i;
    int mesMaisAgua = 0;
    int mesMaisEnergia = 0;
    int mesMaisTelefone = 0;
    float mediaAgua = 0.0;
    float mediaEnergia = 0.0;
    float mediaTelefone = 0.0;

    // Nomes dos meses para facilitar a exibição
    char *nomesMeses[] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    printf("Digite os gastos mensais para Água, Energia e Telefone (último ano):\n");
    for (i = 0; i < NUM_MESES; i++) {
        strcpy(gastos[i].nomeMes, nomesMeses[i]);
        printf("\n--- Mês: %s ---\n", gastos[i].nomeMes);
        printf("Gasto com Água: R$ ");
        scanf("%f", &gastos[i].gastoAgua);
        limparBufferEntrada();

        printf("Gasto com Energia Elétrica: R$ ");
        scanf("%f", &gastos[i].gastoEnergia);
        limparBufferEntrada();

        printf("Gasto com Telefone: R$ ");
        scanf("%f", &gastos[i].gastoTelefone);
        limparBufferEntrada();

        // Encontrar os meses com mais gasto
        if (gastos[i].gastoAgua > gastos[mesMaisAgua].gastoAgua) {
            mesMaisAgua = i;
        }
        if (gastos[i].gastoEnergia > gastos[mesMaisEnergia].gastoEnergia) {
            mesMaisEnergia = i;
        }
        if (gastos[i].gastoTelefone > gastos[mesMaisTelefone].gastoTelefone) {
            mesMaisTelefone = i;
        }

        // Somar para calcular a média depois
        mediaAgua += gastos[i].gastoAgua;
        mediaEnergia += gastos[i].gastoEnergia;
        mediaTelefone += gastos[i].gastoTelefone;
    }

    printf("\n--- Resumo dos Gastos ---\n");
    printf("Mês com mais gasto de Água: %s (R$ %.2f)\n", gastos[mesMaisAgua].nomeMes, gastos[mesMaisAgua].gastoAgua);
    printf("Mês com mais gasto de Energia Elétrica: %s (R$ %.2f)\n", gastos[mesMaisEnergia].nomeMes, gastos[mesMaisEnergia].gastoEnergia);
    printf("Mês com mais gasto de Telefone: %s (R$ %.2f)\n", gastos[mesMaisTelefone].nomeMes, gastos[mesMaisTelefone].gastoTelefone);

    printf("Média de gasto com Água: R$ %.2f\n", mediaAgua / NUM_MESES);
    printf("Média de gasto com Energia Elétrica: R$ %.2f\n", mediaEnergia / NUM_MESES);
    printf("Média de gasto com Telefone: R$ %.2f\n", mediaTelefone / NUM_MESES);

    return 0;
}