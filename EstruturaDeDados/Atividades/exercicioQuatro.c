/*Implementar uma lista encadeada para gerenciar uma lista de tarefas.Cada item da lista (nó) deve ser uma tarefa com os seguintes dados:
id: um número inteiro único para a tarefa;
descricao: uma string (máximo de 100 caracteres) com a descrição da tarefa;
prioridade: alta, média ou baixa.
O programa deve:
Definir a struct para o nó da lista encadeada.
Criar uma lista encadeada vazia.
Implementar uma função adicionarTarefa que insere uma nova tarefa. Para isso, considere que as tarefas devem aparecer por ordem de prioridade. Primeiro, todas as altas. Depois, todas as médias. E, por fim, as baixas. Uma nova tarefa deve ser inserida no final do seu grupo de prioridade;
Implementar uma função exibirTarefas que percorre a lista e imprime todos os detalhes de cada tarefa no console.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    BAIXA,
    MEDIA,
    ALTA
} Prioridade;

typedef struct {
    int id;
    char descricao[101];
    Prioridade prioridade;
} Tarefa;

typedef struct No {
    Tarefa tarefa;
    struct No* proximo;
} No;

No* criarNo(int id, const char* descricao, Prioridade prioridade) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro.\n");
        exit(1);
    }
    novoNo->tarefa.id = id;
    strncpy(novoNo->tarefa.descricao, descricao, 100);
    novoNo->tarefa.descricao[100] = '\0'; 
    novoNo->tarefa.prioridade = prioridade;
    novoNo->proximo = NULL;
    return novoNo;
}

void adicionarTarefa(No** lista, int id, const char* descricao, Prioridade prioridade) {
    No* novoNo = criarNo(id, descricao, prioridade);
    if (*lista == NULL) {
        *lista = novoNo;
        return;
    }
    if (prioridade == ALTA) {
        No* atual = *lista;
        No* anterior = NULL;
        while (atual != NULL && atual->tarefa.prioridade == ALTA) {
            anterior = atual;
            atual = atual->proximo;
        }
    
        if (anterior == NULL) {
            novoNo->proximo = *lista;
            *lista = novoNo;
        } else {
            novoNo->proximo = atual;
            anterior->proximo = novoNo;
        }
        return;
    }
    if (prioridade == MEDIA) {
        No* atual = *lista;
        No* anterior = NULL;

        while (atual != NULL && atual->tarefa.prioridade == ALTA) {
            anterior = atual;
            atual = atual->proximo;
        }
        
        while (atual != NULL && atual->tarefa.prioridade == MEDIA) {
            anterior = atual;
            atual = atual->proximo;
        }
        
        if (anterior == NULL) {
            novoNo->proximo = *lista;
            *lista = novoNo;
        } else {
            novoNo->proximo = atual;
            anterior->proximo = novoNo;
        }
        return;
    }
    
    No* atual = *lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novoNo;
}

void exibirTarefas(No* lista) {
    if (lista == NULL) {
        printf("Vazio.\n");
        return;
    }
    No* atual = lista;
    const char* strPrioridade;

    while (atual != NULL) {
        switch (atual->tarefa.prioridade) {
            case ALTA:
                strPrioridade = "Alta";
                break;
            case MEDIA:
                strPrioridade = "Media";
                break;
            case BAIXA:
                strPrioridade = "Baixa";
                break;
        }
        printf("ID: %d \n Descricao: %s \n Prioridade: %s\n", atual->tarefa.id, atual->tarefa.descricao, strPrioridade);
        atual = atual->proximo;
    }
}

void liberarLista(No** lista) {
    No* atual = *lista;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
}

int main() {
    No* listaDeTarefas = NULL;
    printf("Acrescentando tarefas...\n");
    adicionarTarefa(&listaDeTarefas, 1, "Tarefa 1", MEDIA);
    adicionarTarefa(&listaDeTarefas, 2, "Tarefa 2", BAIXA);
    adicionarTarefa(&listaDeTarefas, 3, "Tarefa 3", ALTA);
    adicionarTarefa(&listaDeTarefas, 4, "Tarefa 4", MEDIA);
    adicionarTarefa(&listaDeTarefas, 5, "Tarefa 5", ALTA);
    adicionarTarefa(&listaDeTarefas, 6, "Tarefa 6", BAIXA);
    printf("\nLista de Tarefas\n");
    exibirTarefas(listaDeTarefas);
    printf("\n");
    liberarLista(&listaDeTarefas);
    
    return 0;
}
