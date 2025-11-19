#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int disco;
    struct No* proximo;
} No;

typedef struct Pilha {
    No* topo;
    int tamanho;
} Pilha;

Pilha* criar_pilha() {
    Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));
    if (novaPilha == NULL) {
        printf("Erro.\n");
        exit(1);
    }
    novaPilha->topo = NULL;
    novaPilha->tamanho = 0;
    return novaPilha;
}

void empilhar(Pilha* p, int disco) {
    if (p == NULL) {
        return;
    }
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro.\n");
        exit(1);
    }
    novoNo->disco = disco;
    novoNo->proximo = p->topo;
    p->topo = novoNo;
    p->tamanho++;
}

int desempilhar(Pilha* p) {
    if (p == NULL || p->topo == NULL) {
        return -1;
    }
    No* temp = p->topo;
    int discoRemovido = temp->disco;
    p->topo = temp->proximo;
    free(temp);
    p->tamanho--;
    return discoRemovido;
}

int obter_topo(Pilha* p) {
    if (p == NULL || p->topo == NULL) {
        return -1;
    }
    return p->topo->disco;
}

void liberar_pilha(Pilha* p) {
    if (p == NULL) {
        return;
    }
    No* atual = p->topo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(p);
}

void obter_discos_da_pilha(Pilha* p, int totalDiscos, int discosArray[], int* contar) {
    No* atual = p->topo;
    *contar = 0;
    while (atual != NULL) {
        discosArray[(*contar)++] = atual->disco;
        atual = atual->proximo;
    }
}

void exibir_jogo(Pilha* a, Pilha* b, Pilha* c, int discos) {
    int i, j;
    int discosA[discos], discosB[discos], discosC[discos];
    int contarA, contarB, contarC;
    int larguraHaste = discos + 2;

    obter_discos_da_pilha(a, discos, discosA, &contarA);
    obter_discos_da_pilha(b, discos, discosB, &contarB);
    obter_discos_da_pilha(c, discos, discosC, &contarC);

    printf("------------------------------------------------------------------\n");
    for (i = discos - 1; i >= 0; i--) {
        printf("Haste A:");
        if (i < contarA) {
            int discoA = discosA[contarA - 1 - i];
            int espacos = (larguraHaste - discoA) / 2;
            for (j = 0; j < espacos; j++) {
                printf(" ");
            }
            for (j = 0; j < discoA; j++) {
                printf("-");
            }
            for (j = 0; j < (larguraHaste - discoA) - espacos; j++) {
                printf(" ");
            }
        } else {
            for (j = 0; j < larguraHaste; j++) {
                printf(" ");
            }
        }
        
        printf("\tHaste B:");
        if (i < contarB) {
            int discoB = discosB[contarB - 1 - i];
            int espacos = (larguraHaste - discoB) / 2;
            for (j = 0; j < espacos; j++) {
                printf(" ");
            }
            for (j = 0; j < discoB; j++) {
                printf("-");
            }
            for (j = 0; j < (larguraHaste - discoB) - espacos; j++) {
                printf(" ");
            }
        } else {
            for (j = 0; j < larguraHaste; j++) {
                printf(" ");
            }
        }
        
        printf("\tHaste C:");
        if (i < contarC) {
            int discoC = discosC[contarC - 1 - i];
            int espacos = (larguraHaste - discoC) / 2;
            for (j = 0; j < espacos; j++) {
                printf(" ");
            }
            for (j = 0; j < discoC; j++) {
                printf("-");
            }
            for (j = 0; j < (larguraHaste - discoC) - espacos; j++) {
                printf(" ");
            }
        } else {
            for (j = 0; j < larguraHaste; j++) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("------------------------------------------------------------------\n");
}

int mover_disco(Pilha* origem, Pilha* destino) {
    int discoOrigem = obter_topo(origem);
    int discoDestino = obter_topo(destino);

    if (discoOrigem == -1) {
        printf("Erro: A haste ta vazia.\n");
        return 0;
    }

    if (discoDestino != -1 && discoOrigem > discoDestino) {
        printf("Erro: Nao eh possivel colocar um disco maior em cima de um menor.\n");
        return 0;
    }
    
    int disco = desempilhar(origem);
    empilhar(destino, disco);
    printf("Disco movido com sucesso!\n");
    return 1;
}

int main() {
    int n, opcao;
    printf("Insira o numero de discos: ");
    scanf("%d", &n);
    if (n <= 1) {
        printf("Precisa ter mais de um disco.\n");
        return 1;
    }
    
    
    Pilha* hasteA = criar_pilha();
    Pilha* hasteB = criar_pilha();
    Pilha* hasteC = criar_pilha();
    
    for (int i = n; i >= 1; i--) {
        empilhar(hasteA, i);
    }
    
    system("cls");
    exibir_jogo(hasteA, hasteB, hasteC, n);
    
    while (!(hasteC->tamanho == n && obter_topo(hasteC) == 1)) {
        printf("\nOpcoes: \n");
        printf("1. Mover Haste A para B\n");
        printf("2. Mover Haste A para C\n");
        printf("3. Mover Haste B para A\n");
        printf("4. Mover Haste B para C\n");
        printf("5. Mover Haste C para A\n");
        printf("6. Mover Haste C para B\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        system("cls");

        switch (opcao) {
            case 1:
                mover_disco(hasteA, hasteB);
                break;
            case 2:
                mover_disco(hasteA, hasteC);
                break;
            case 3:
                mover_disco(hasteB, hasteA);
                break;
            case 4:
                mover_disco(hasteB, hasteC);
                break;
            case 5:
                mover_disco(hasteC, hasteA);
                break;
            case 6:
                mover_disco(hasteC, hasteB);
                break;
            case 7:
                printf("Tchau!\n");
                liberar_pilha(hasteA);
                liberar_pilha(hasteB);
                liberar_pilha(hasteC);
                return 0;
            default:
                printf("Opcao invalida.\n");
                break;
        }
        
        exibir_jogo(hasteA, hasteB, hasteC, n);
    }

    printf("Parabens!\n");
    liberar_pilha(hasteA);
    liberar_pilha(hasteB);
    liberar_pilha(hasteC);

    return 0;
}