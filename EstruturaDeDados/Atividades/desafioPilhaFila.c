#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char url[200];
    struct no *proximo;
} No;

typedef struct Fila {
    No *inicio;
    No *final;
} Fila;

typedef struct Pilha {
    No *topo;
} Pilha;

Pilha* criarHistorico() {
    Pilha *historico = (Pilha*)malloc(sizeof(Pilha));
    if (historico == NULL) {
        return NULL;
    }
    historico->topo = NULL;
    return historico;
}

void salvarURL(Pilha* historico, char* url) {
    if (historico == NULL) {
        return;
    }
    
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        return;
    }
    
    strncpy(novoNo->url, url, sizeof(novoNo->url) - 1);
    novoNo->url[sizeof(novoNo->url) - 1] = '\0';
    novoNo->proximo = historico->topo;
    historico->topo = novoNo;
}

char* voltarPagina(Pilha* historico) {
    if (historico == NULL || historico->topo == NULL) {
        return NULL;
    }

    No* noRemovido = historico->topo;
    char* retorno = (char*)malloc(sizeof(char) * 200);
    if (retorno == NULL) {
        return NULL;
    }
    
    strncpy(retorno, noRemovido->url, 199);
    retorno[199] = '\0';
    
    historico->topo = noRemovido->proximo;
    free(noRemovido);

    return retorno;
}

int historicoVazio(Pilha* historico) {
    return historico == NULL || historico->topo == NULL;
}

void liberarHistorico(Pilha* historico) {
    if (historico == NULL) {
        return;
    }

    No* atual = historico->topo;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    free(historico);
}

/********************************************************************
int navegarPaginas(Pilha* historicoDeNavegacao) {
	int opcao;
	
    printf("\nVoce deseja acessar qual das paginas?\n");
    printf("(1) - https://www.google.com\n(2) - https://www.youtube.com\n(3) - https://github.com\n(4) - Voltar a pagina anterior\n(5) - Sair\nOpcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            salvarURL(historicoDeNavegacao, "https://www.google.com");
            break;
        case 2:
            salvarURL(historicoDeNavegacao, "https://www.youtube.com");
            break;
        case 3:
            salvarURL(historicoDeNavegacao, "https://github.com");
            break;
        case 4:
            if (historicoVazio(historicoDeNavegacao)) {
    			printf("O historico esta vazio.\n");
			}   else {
    				char* urlVoltar = voltarPagina(historicoDeNavegacao);
    		if (urlVoltar != NULL) {
        		printf("Voltando%s\n", urlVoltar);
        		free(urlVoltar);
    		}
				}
            break;
        case 5:
            return 0; 
        default:
            printf("Opcao invalida.\n");
    }
    return 1; 
}
***************************************************************************/

void verHistorico(Pilha *historico) {
    if (historicoVazio(historico)) {
    	system("cls");
        printf("As paginas que voce for visitar irao aparecer aqui!\n");
        return;
    }
	system("cls");
    printf("\nHistorico:\n");
    No *atual = historico->topo;
    int indice = 1;
    
    while (atual != NULL) {
        printf("%d. https://%s\n", indice, atual->url);
        atual = atual->proximo;
        indice++;
    }
}
/******** FILA ********/
Fila* criarFilaDownloads() {
    Fila* downloads = (Fila*)malloc(sizeof(Fila));
    if (downloads == NULL) {
        return NULL;
    }
    downloads->inicio = NULL;
    downloads->final = NULL;
    return downloads;
}

void adicionarDownload(Fila* downloads, char* arquivo) {
    if (downloads == NULL) return;

    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) return;

    strncpy(novoNo->url, arquivo, sizeof(novoNo->url) - 1);
    novoNo->url[sizeof(novoNo->url) - 1] = '\0';
    novoNo->proximo = NULL;

    if (downloads->final == NULL) {
        downloads->inicio = novoNo;
        downloads->final = novoNo;
    } else {
        downloads->final->proximo = novoNo;
        downloads->final = novoNo;
    }
}

char* processarDownload(Fila* downloads) {
    if (downloads == NULL || downloads->inicio == NULL) {
        return NULL;
    }

    No* removido = downloads->inicio;
    char* retorno = (char*)malloc(200 * sizeof(char));
    if (retorno == NULL) return NULL;

    strncpy(retorno, removido->url, 199);
    retorno[199] = '\0';

    downloads->inicio = removido->proximo;
    if (downloads->inicio == NULL) {
        downloads->final = NULL;
    }
    free(removido);

    return retorno;
}

int filaDownloadsVazia(Fila* downloads) {
    return downloads == NULL || downloads->inicio == NULL;
}

void liberarFilaDownloads(Fila* downloads) {
    if (downloads == NULL) return;

    No* atual = downloads->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(downloads);
}
/********/

void menu(Pilha *historicoDeNavegacao, Fila *downloads) {
	int escolha;
	char novaURL[200];
	
	do {
		printf("Escolha:\n (1) - Navegar para nova URL\n (2) - Voltar Pagina\n (3) - Adicionar download\n (4) - Executar proximo download\n (5) - Ver historico\n (6) - Ver fila de downloads\n (0) - Sair\n Opcao: ");
		scanf("%d", &escolha);
		switch(escolha) {
			case 0:
				liberarHistorico(historicoDeNavegacao);
				printf("Ate a proxima.");
				break;
			case 1:
				system("cls");
        		printf("Digite a url do website: \n https://");
        		fflush(stdin);
        		gets(novaURL);
            	salvarURL(historicoDeNavegacao, novaURL);
            	break;
        	case 2:
        		if (historicoVazio(historicoDeNavegacao)) {
        			system("cls");
    				printf("O historico esta vazio.\n");
				} else {
					char* urlVoltar = voltarPagina(historicoDeNavegacao);
					if (urlVoltar != NULL) {
						system("cls");
						printf("Voltando a pagina: https://%s\n", urlVoltar);
						free(urlVoltar);
					}
				}
				break;
			case 3:
				system("cls");
    			char arquivo[200];
    			printf("Digite o nome do arquivo para download: ");
   				fflush(stdin);
    			gets(arquivo);
    			adicionarDownload(downloads, arquivo);
    			printf("Arquivo '%s' adicionado na fila de downloads.\n", arquivo);
    			break;
    		case 4: {
    			char* arquivo = processarDownload(downloads);
			    if (arquivo != NULL) {
			        system("cls");
			        printf("Baixando arquivo: %s ... Concluido!\n", arquivo);
			        free(arquivo);
			    } else {
			        system("cls");
			        printf("Nao tem downloads pendentes.\n");
			    }
			    break;	
			}
			case 5:
				verHistorico(historicoDeNavegacao);
				break;
			case 6: 
			    system("cls");
			    if (filaDownloadsVazia(downloads)) {
			        printf("A fila de downloads esta vazia.\n");
			    } else {
			        printf("Fila de downloads:\n");
			        No* atual = downloads->inicio;
			        int i = 1;
			        while (atual != NULL) {
			            printf("%d. %s\n", i, atual->url);
			            atual = atual->proximo;
			            i++;
			        }
			    }
			    break;
        	default:
        		system("cls");
            	printf("Opcao invalida.\n");
			} 
	} while(escolha != 0);	
}
int main() {
    Pilha *historicoDeNavegacao = criarHistorico();
    Fila *downloads = criarFilaDownloads();
    menu(historicoDeNavegacao, downloads);
    liberarHistorico(historicoDeNavegacao);
    liberarFilaDownloads(downloads);
    return 0;
}