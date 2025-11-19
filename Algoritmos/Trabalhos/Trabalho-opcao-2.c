#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contarPontoEVirgula(char str[]) {
    int cont = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ';') cont++;
    }
    return cont;
}

int ehNumerico(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int validarValor(char valor[]) {
    int i, ponto = 0, decimais = 0;
    int len = strlen(valor);

    if (valor[0] == '.' || valor[len - 1] == '.') return 0;

    for (i = 0; valor[i]; i++) {
        if (valor[i] == '.') {
            ponto++;
            if (ponto > 1) return 0;
        } else if (!isdigit(valor[i])) {
            return 0;
        }
        if (ponto == 1 && valor[i] != '.') decimais++;
    }

    if (ponto == 1 && decimais > 2) return 0;

    return 1;
}

int validarData(char data[]) {
    if (strlen(data) != 10) return 0;
    if (data[2] != '-' || data[5] != '-') return 0;

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(data[i])) return 0;
    }

    return 1;
}

int compararValores(char valor1[], char valor2[]) {
    int len1 = strlen(valor1);
    int len2 = strlen(valor2);

    // Comparar tamanhos
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    // Mesmo tamanho, comparar caractere por caractere
    for (int i = 0; i < len1; i++) {
        if (valor1[i] > valor2[i]) return 1;
        if (valor1[i] < valor2[i]) return -1;
    }
    return 0;
}

void toUpperCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char entrada[81];
    char id[6], tipo[10], valor[20], data[11];
    char valorLimite[20];

    while (1) {
        printf("Digite o registro da transação:\n");
        fgets(entrada, 81, stdin);
        entrada[strcspn(entrada, "\n")] = '\0'; // remove \n

        if (contarPontoEVirgula(entrada) != 3) {
            printf("Erro: Formato inválido. Deve conter exatamente 3 ';'.\n\n");
            continue;
        }

        // Separar campos
        char campos[4][81];
        int i = 0;
        char *parte = strtok(entrada, ";");
        while (parte != NULL && i < 4) {
            strcpy(campos[i], parte);
            i++;
            parte = strtok(NULL, ";");
        }

        if (i != 4 || strlen(campos[0]) != 5 || !ehNumerico(campos[0])) {
            printf("Erro: ID inválido. Deve conter exatamente 5 dígitos numéricos.\n\n");
            continue;
        }

        char tipoCopia[10];
        strcpy(tipoCopia, campos[1]);
        toUpperCase(tipoCopia);
        if (strcmp(tipoCopia, "CREDITO") != 0 && strcmp(tipoCopia, "DEBITO") != 0) {
            printf("Erro: Tipo de operação inválido. Use CREDITO ou DEBITO.\n\n");
            continue;
        }

        if (!validarValor(campos[2])) {
            printf("Erro: Valor inválido. Deve ser decimal com até 2 casas decimais.\n\n");
            continue;
        }

        if (!validarData(campos[3])) {
            printf("Erro: Data inválida. Formato correto: DD-MM-AAAA.\n\n");
            continue;
        }

        // Dados válidos - extrair e padronizar
        strcpy(id, campos[0]);
        strcpy(tipo, tipoCopia);
        strcpy(valor, campos[2]);
        strcpy(data, campos[3]);

        break;
    }

    // Exibir componentes extraídos
    printf("\n--- Dados Extraídos ---\n");
    printf("ID da Conta: %s\n", id);
    printf("Tipo de Operação: %s\n", tipo);
    printf("Valor: %s\n", valor);
    printf("Data: %s\n", data);

    // Análise de valores
    printf("\nDigite o Valor Limite (ex: 1000.00): ");
    fgets(valorLimite, 20, stdin);
    valorLimite[strcspn(valorLimite, "\n")] = '\0'; // remover \n

    int cmp = compararValores(valor, valorLimite);
    if (cmp > 0) {
        printf("Valor da transação EXCEDEU o limite de R$ %s\n", valorLimite);
    } else {
        printf("Valor da transação DENTRO do limite de R$ %s\n", valorLimite);
    }

    // Verificação de critério de crédito
    if (strcmp(tipo, "CREDITO") == 0 && strncmp(data + 6, "2025", 4) == 0) {
        printf("Transação atende aos critérios para análise de crédito do ano atual.\n");
    } else {
        printf("Transação não atende aos critérios para análise de crédito do ano atual.\n");
    }

    return 0;
}
