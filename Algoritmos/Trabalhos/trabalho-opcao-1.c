#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Produto {
    char nomeProdutoTemporario[50];
    char codigoProduto[50];
    char nomeFormatado[50];
    char preco[50];
} Produto;

void limparNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int validarCodigo(char *codigo) {
    int i;
    if (strlen(codigo) != 8)
        return 0;

    for (i = 0; i < 8; i++) {
        if (!isalnum(codigo[i]))
            return 0;
    }

    return 1;
}

void formatarNomeProduto(char nome[], char nomeFormatado[]) {
    int i = 0, j = 0;
    int novaPalavra = 1;

    // Remover espaços iniciais
    while (nome[i] == ' ') i++;

    while (nome[i] != '\0') {
        if (nome[i] != ' ' || (j > 0 && nomeFormatado[j-1] != ' ')) {
            if (novaPalavra && isalpha(nome[i])) {
                nomeFormatado[j++] = toupper(nome[i]);
                novaPalavra = 0;
            } else {
                nomeFormatado[j++] = tolower(nome[i]);
            }
        }

        if (nome[i] == ' ') {
            novaPalavra = 1;
        }

        i++;
    }

    // Remover espaço final, se houver
    if (j > 0 && nomeFormatado[j - 1] == ' ') {
        j--;
    }

    nomeFormatado[j] = '\0';
}

int validarPreco(char *preco) {
    int pontos = 0, casasDecimais = 0, i = 0;
    int depoisDoPonto = 0;

    while (preco[i] != '\0') {
        if (preco[i] == '.') {
            pontos++;
            depoisDoPonto = 1;
            if (pontos > 1) return 0;
        } else if (!isdigit(preco[i])) {
            return 0;
        } else if (depoisDoPonto) {
            casasDecimais++;
        }
        i++;
    }

    if (pontos == 1 && casasDecimais > 2)
        return 0;

    return i > 0; // válido se tiver pelo menos um caractere
}

Produto lerDados(Produto p) {
    char temp[50];

    // Validação do código do produto
    while (1) {
        printf("Insira o código (8 caracteres alfanuméricos): ");
        fgets(temp, sizeof(temp), stdin);
        limparNovaLinha(temp);

        if (validarCodigo(temp)) {
            strcpy(p.codigoProduto, temp);
            break;
        } else {
            printf("Código inválido. Tente novamente.\n");
        }
    }

    // Leitura e formatação do nome do produto
    printf("Insira o nome do Produto: ");
    fgets(p.nomeProdutoTemporario, sizeof(p.nomeProdutoTemporario), stdin);
    limparNovaLinha(p.nomeProdutoTemporario);
    formatarNomeProduto(p.nomeProdutoTemporario, p.nomeFormatado);

    // Validação do preço
    while (1) {
        printf("Insira o preço (máximo 2 casas decimais): ");
        fgets(temp, sizeof(temp), stdin);
        limparNovaLinha(temp);

        if (validarPreco(temp)) {
            strcpy(p.preco, temp);
            break;
        } else {
            printf("Preço inválido. Tente novamente.\n");
        }
    }

    return p;
}

int main() {
    SetConsoleOutputCP(65001);
    Produto p;

    p = lerDados(p);

    printf("\nSegue os dados validados:\n");
    printf("Código do produto: %s\n", p.codigoProduto);
    printf("Nome formatado: %s\n", p.nomeFormatado);
    printf("Preço: %s\n", p.preco);

    return 0;
}
