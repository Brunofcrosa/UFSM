#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* next;
    struct Node* prev;
} Node;


Node* criarLista(int n) {
	int i = 0;
    if (n <= 0) {
        return NULL;
    }

    Node* cabeca = (Node*)malloc(sizeof(Node));
    cabeca->id = 1;
    cabeca->next = cabeca;
    cabeca->prev = cabeca;

    Node* atual = cabeca;
    for (i = 2; i <= n; i++) {
        Node* novoNode = (Node*)malloc(sizeof(Node));
        if (novoNode == NULL) {
            Node* temp = cabeca->next;
            while (temp != cabeca) {
                Node* nextTemp = temp->next;
                free(temp);
                temp = nextTemp;
            }
            free(cabeca);
            return NULL;
        }
        novoNode->id = i;
        novoNode->prev = atual;
        atual->next = novoNode;
        atual = novoNode;
    }
    atual->next = cabeca;
    cabeca->prev = atual;
    
    return cabeca;
}

Node* eliminarNode(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    Node* proximoNode = node->next;
    node->prev->next = proximoNode;
    proximoNode->prev = node->prev;
    printf("Pessoa com codigo %d morreu.\n", node->id);
    free(node);
    return proximoNode;
}


void executarPessoa(Node* cabeca, int k) {
	int sentido = 1;
	if (cabeca == NULL) {
		return;
	}
	Node* atual = cabeca;
	while (atual->next != atual) {
        for (int i = 1; i < k; i++) {
        	if(sentido == 1) {
        		atual = atual->next;
			}
            else {
            	atual = atual->prev;
			}
        }
        atual = eliminarNode(atual);
        sentido = (sentido == 1) ? 2 : 1;
        k++;
    }
	printf("\nQuem sobreviveu foi a pessoa de codigo: %d.\n", atual->id);
    free(atual);
}

int main() {
	srand(time(NULL));
	int n = 0;
	while(n <= 0 || n >= 20) {
		n = rand() % 100;
	}
    int k = 0;
    while(k > n || k > 10 || k == 0) {
		k = rand() % 100;
	}
    Node* criarLista(int n);
	Node* eliminar(Node* node);
	void executarPessoa(Node* cabeca, int k);
    printf("Pessoas em circulo: %d e contagem: %d\n\n", n, k);
    
    Node* lista = criarLista(n);
    if (lista == NULL) {
        printf("Falha ao criar a lista.\n");
        return 1;
    }
	
    executarPessoa(lista, k);
    
    return 0;
}