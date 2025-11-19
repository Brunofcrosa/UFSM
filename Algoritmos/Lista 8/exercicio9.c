#include <stdio.h>
#include <string.h>

#define MAX_PROJETOS 50

typedef struct {
    char nomeInventor[50];
    char nomeProjeto[100];
    char descricao[200];
    float valorFinanciamento;
    int prazoMeses;
    int atrasado; // 0 para não, 1 para sim
} Projeto;

Projeto projetos[MAX_PROJETOS];
int totalProjetos = 0;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarProjetos() {
    int i;
    printf("Cadastro de Projetos (máximo %d):\n", MAX_PROJETOS);
    for (i = 0; i < MAX_PROJETOS; i++) {
        printf("\n--- Projeto %d ---\n", i + 1);
        printf("Nome do Inventor (ou 'fim' para encerrar): ");
        fgets(projetos[i].nomeInventor, sizeof(projetos[i].nomeInventor), stdin);
        projetos[i].nomeInventor[strcspn(projetos[i].nomeInventor, "\n")] = '\0';

        if (strcmp(projetos[i].nomeInventor, "fim") == 0) {
            break;
        }

        printf("Nome do Projeto: ");
        fgets(projetos[i].nomeProjeto, sizeof(projetos[i].nomeProjeto), stdin);
        projetos[i].nomeProjeto[strcspn(projetos[i].nomeProjeto, "\n")] = '\0';

        printf("Breve Descrição do Invento: ");
        fgets(projetos[i].descricao, sizeof(projetos[i].descricao), stdin);
        projetos[i].descricao[strcspn(projetos[i].descricao, "\n")] = '\0';

        printf("Valor de Financiamento Solicitado: R$ ");
        scanf("%f", &projetos[i].valorFinanciamento);
        limparBufferEntrada();

        printf("Prazo de Execução em Meses: ");
        scanf("%d", &projetos[i].prazoMeses);
        limparBufferEntrada();

        printf("O projeto está atrasado? (1-Sim / 0-Não): ");
        scanf("%d", &projetos[i].atrasado);
        limparBufferEntrada();

        totalProjetos++;
    }
    printf("Cadastro de projetos encerrado.\n");
}

void listarProjetosCurtoPrazo() {
    int i;
    float totalFinanciadoCurtoPrazo = 0.0;
    printf("\n--- Projetos com até 6 Meses de Prazo ---\n");
    if (totalProjetos == 0) {
        printf("Nenhum projeto cadastrado.\n");
        return;
    }

    for (i = 0; i < totalProjetos; i++) {
        if (projetos[i].prazoMeses <= 6) {
            printf("Nome do Projeto: %s, Prazo: %d meses\n", projetos[i].nomeProjeto, projetos[i].prazoMeses);
            totalFinanciadoCurtoPrazo += projetos[i].valorFinanciamento;
        }
    }
    printf("Total financiado para projetos com até 6 meses de prazo: R$ %.2f\n", totalFinanciadoCurtoPrazo);
}

void listarProjetosEmAtraso() {
    int i;
    float totalFinanciadoAtraso = 0.0;
    printf("\n--- Projetos em Atraso ---\n");
    if (totalProjetos == 0) {
        printf("Nenhum projeto cadastrado.\n");
        return;
    }

    for (i = 0; i < totalProjetos; i++) {
        if (projetos[i].atrasado == 1) {
            printf("Nome do Projeto: %s, Inventor: %s\n", projetos[i].nomeProjeto, projetos[i].nomeInventor);
            totalFinanciadoAtraso += projetos[i].valorFinanciamento;
        }
    }
    printf("Total financiado para projetos em atraso: R$ %.2f\n", totalFinanciadoAtraso);
}

int main() {
    cadastrarProjetos();
    listarProjetosCurtoPrazo();
    listarProjetosEmAtraso();
    return 0;
}