#include <stdio.h>


void realizarPesquisa() { [cite: 10]
    float salario, somaSalarios = 0.0, maiorSalario = 0.0;
    int numeroFilhos, somaFilhos = 0, totalPessoas = 0, pessoasSalarioBaixo = 0;
    char continuar;

    printf("Iniciando pesquisa de habitantes.\n");
    printf("Digite 'n' ou 'N' para parar a entrada de dados.\n");

    do {
        printf("\nDados da pessoa %d:\n", totalPessoas + 1);
        printf("Salario (ou N para parar): ");

        if (scanf(" %c", &continuar) == 1 && (continuar == 'n' || continuar == 'N')) {
            break; 
        }

        ungetc(continuar, stdin); 
        if (scanf("%f", &salario) != 1) {
            printf("Entrada invalida. Por favor, digite um numero ou 'n' para parar.\n");

            while (getchar() != '\n');
            continue; 
        }

        if (salario < 0) { 
            printf("Salario negativo inserido. Encerrando entrada de dados.\n");
            break;
        }

        printf("Numero de filhos: ");
        if (scanf("%d", &numeroFilhos) != 1) {
            printf("Entrada invalida para numero de filhos. Por favor, digite um numero inteiro.\n");
            while (getchar() != '\n');
            continue;
        }

        somaSalarios += salario;
        somaFilhos += numeroFilhos;
        totalPessoas++;

        if (salario > maiorSalario) {
            maiorSalario = salario;
        }

        if (salario <= 350.00) {
            pessoasSalarioBaixo++;
        }

    } while (1); 

    if (totalPessoas > 0) {
        printf("\n--- Resultados da Pesquisa ---\n");
        printf("Media de salario da populacao: R$ %.2f\n", somaSalarios / totalPessoas); [cite: 10]
        printf("Media do numero de filhos: %.2f\n", (float)somaFilhos / totalPessoas); [cite: 10]
        printf("Maior salario: R$ %.2f\n", maiorSalario); [cite: 10]
        printf("Percentual de pessoas com salario ate R$350,00: %.2f%%\n",
               (float)pessoasSalarioBaixo / totalPessoas * 100.0); [cite: 10]
    } else {
        printf("Nenhum dado de pessoa foi inserido.\n");
    }
}

int main() {
    realizarPesquisa();
    return 0;
}