#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[15];
    char sobrenome[30];
    char endereco[80];
    char telefone[9];
    char idade[4];
    char nome_compl[46];
} Colega;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int n;
    Colega colegas[50]; // Usando array estático para simplificar sem malloc/free
    
    printf("Quantos colegas da turma de algoritmos você deseja cadastrar? ");
    scanf("%d", &n);
    limparBufferEntrada();

    if (n > 50) {
        printf("Número máximo de colegas é 50. Cadastrando 50.\n");
        n = 50;
    }
    
    for (int i = 0; i < n; i++) {
        printf("\n--- Informações do Colega %d ---\n", i + 1);

        printf("Nome (max 14 caracteres): ");
        fgets(colegas[i].nome, sizeof(colegas[i].nome), stdin);
        colegas[i].nome[strcspn(colegas[i].nome, "\n")] = '\0';

        printf("Sobrenome (max 29 caracteres): ");
        fgets(colegas[i].sobrenome, sizeof(colegas[i].sobrenome), stdin);
        colegas[i].sobrenome[strcspn(colegas[i].sobrenome, "\n")] = '\0';

        printf("Endereço (max 79 caracteres): ");
        fgets(colegas[i].endereco, sizeof(colegas[i].endereco), stdin);
        colegas[i].endereco[strcspn(colegas[i].endereco, "\n")] = '\0';

        printf("Telefone (max 8 dígitos, sem formatação): ");
        fgets(colegas[i].telefone, sizeof(colegas[i].telefone), stdin);
        colegas[i].telefone[strcspn(colegas[i].telefone, "\n")] = '\0';

        printf("Idade (max 3 dígitos): ");
        fgets(colegas[i].idade, sizeof(colegas[i].idade), stdin);
        colegas[i].idade[strcspn(colegas[i].idade, "\n")] = '\0';

        strcpy(colegas[i].nome_compl, colegas[i].nome);
        strcat(colegas[i].nome_compl, " ");
        strcat(colegas[i].nome_compl, colegas[i].sobrenome);
    }

    printf("\n--- Informações dos Colegas Cadastrados ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nColega %d:\n", i + 1);
        printf("Nome Completo: %s\n", colegas[i].nome_compl);
        printf("Endereço: %s\n", colegas[i].endereco);
        printf("Telefone: %s\n", colegas[i].telefone);
        printf("Idade: %s\n", colegas[i].idade);
        printf("Tamanho do Nome Completo: %lu caracteres\n", (unsigned long)strlen(colegas[i].nome_compl));
    }

    return 0;
}