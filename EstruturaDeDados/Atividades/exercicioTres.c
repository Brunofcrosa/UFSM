/*Desenvolva um algoritmo para fazer o gerenciamento de Clientes (Busca e Remoção).  Cada cliente deve ter um id e um nome.
Você deve:
Definir a struct para o nó da lista de clientes.
Implementar uma função adicionarCliente que insere um novo cliente no final da lista.
Implementar uma função buscarCliente que recebe a lista e um id como parâmetro, e retorna um ponteiro para o nó do cliente encontrado. Se o cliente não for encontrado, a função deve retornar NULL.
Implementar uma função removerCliente que recebe a lista e um id como parâmetro, e remove o nó do cliente correspondente. A função deve lidar com três casos: remover o primeiro nó, remover um nó no meio e remover o último nó.
Exibir a lista completa de clientes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[51];
} Cliente;

typedef struct No {
    Cliente cliente;
    struct No* proximo;
} No;

No* criarNo(int id, const char* nome) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro.\n");
        exit(1);
    }
    
    novoNo->cliente.id = id;
    strncpy(novoNo->cliente.nome, nome, 50);
    novoNo->cliente.nome[50] = '\0';
    
    novoNo->proximo = NULL;
    
    return novoNo;
}

void adicionarCliente(No** lista, int id, const char* nome) {
    No* novoNo = criarNo(id, nome);
    
    if (*lista == NULL) {
        *lista = novoNo;
        return;
    }
    
    No* atual = *lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novoNo;
}

No* buscarCliente(No* lista, int id) {
    No* atual = lista;
    while (atual != NULL) {
        if (atual->cliente.id == id) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL; 
}

void removerCliente(No** lista, int id) {
    No* atual = *lista;
    No* anterior = NULL;
    
    while (atual != NULL && atual->cliente.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) {
        printf("ID %d nao encontrado.\n", id);
        return;
    }
    
    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    
    printf("ID %d removido.\n", atual->cliente.id);
    free(atual);
}

void exibirLista(No* lista) {
    if (lista == NULL) {
        printf("Lista Vazia.\n");
        return;
    }
    
    No* atual = lista;
    printf(" Lista de Clientes \n");
    while (atual != NULL) {
        printf("ID: %d \n Nome: %s\n", atual->cliente.id, atual->cliente.nome);
        atual = atual->proximo;
    }
    printf("\n");
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
    No* listaDeClientes = NULL;
    
    printf("Acrescentando clientes\n");
    adicionarCliente(&listaDeClientes, 1, "Cliente Um");
    adicionarCliente(&listaDeClientes, 2, "Cliente Dois");
    adicionarCliente(&listaDeClientes, 3, "Cliente Tres");
    
    exibirLista(listaDeClientes);
    
    printf("Buscando ID 2\n");
    No* clienteEncontrado = buscarCliente(listaDeClientes, 2);
    if (clienteEncontrado != NULL) {
        printf("Cliente: ID %d, Nome: %s\n\n", clienteEncontrado->cliente.id, clienteEncontrado->cliente.nome);
    } else {
        printf("Cliente nao foi encontrado\n\n");
    }
    
    printf("Removendo ID 1...\n");
    removerCliente(&listaDeClientes, 1);
    exibirLista(listaDeClientes);

    printf("Removendo ID 3...\n");
    removerCliente(&listaDeClientes, 3);
    exibirLista(listaDeClientes);

    printf("Removendo ID 2...\n");
    removerCliente(&listaDeClientes, 2);
    exibirLista(listaDeClientes);
    
    liberarLista(&listaDeClientes);
    
    return 0;
}