#include <stdio.h>
#include <stdlib.h> //malloc, free e exit
#include <time.h> // srand/time (embaralhamento)
#include <string.h> // strcpy, strcat e strlen 
#include <windows.h>  // Sleep

typedef struct Carta {
    int cor; // 0: Vermelho, 1: Azul, 2: Verde
    int tipo; // 0: Numero, 1: +2
    int valor; // 0 a 5 para cartas de Numero; -1 para cartas de +2
    struct Carta* proximo; // Ponteiro para o prox da lista
} Carta;

typedef struct {
    Carta* monte;      // pilha de compra (Monte)
    Carta* descarte;   // pilha de descarte
    Carta* maoJogador1; // lista de cartas do Jogador 1
    Carta* maoJogador2; // lista de cartas do Jogador 2
    int jogadorAtual;  // Se é jogador 1 ou 2
} Jogo;

int contarCartas(Carta* topo) { // conta o numero de cartas em qualquer lista (mao, monte, descarte).
    int contador = 0;
    Carta* atual = topo;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

void cartaParaString(Carta* carta, char* buffer) { // Converte os atributos numericos em uma string.
    if (carta == NULL) { 
        strcpy(buffer, "[VAZIO]");
        return;
    }

    char corStr[15];  //Armazenar o nome da cor da carta
    if (carta->cor == 0) strcpy(corStr, "Vermelho");
    else if (carta->cor == 1) strcpy(corStr, "Azul");
    else if (carta->cor == 2) strcpy(corStr, "Verde");
    else strcpy(corStr, "INVALIDO");
    char tipoStr[15]; //Armazenar o tipo da carta.
    char valorStr[5] = "";
    
    if (carta->tipo == 0) {
        strcpy(tipoStr, "Numero");
        if (carta->valor >= 0 && carta->valor <= 9) { // verifica se ta no intervalo.
            valorStr[0] = ' '; // espaço para separação visual.
            valorStr[1] = (char)('0' + carta->valor); // converte para ASCII
            valorStr[2] = '\0';
        } else {
            strcpy(valorStr, "INVALIDO");
        }
    } else if (carta->tipo == 1) { // representa +2
        strcpy(tipoStr, "+2");
    } else {
        strcpy(tipoStr, "INVALIDO");
    }

	strcpy(buffer, corStr);
	strcat(buffer, ", ");
	strcat(buffer, tipoStr);
	strcat(buffer, valorStr);
}

void imprimirEspacos(int numEspacos) { // alinhamento do console
    for (int k = 0; k < numEspacos; k++) {
        printf(" ");
    }
}

void exibirMesa(Jogo* jogo) {
    int largura_coluna_j1 = 24; 

    Carta* cartaAtualJ1 = jogo->maoJogador1;
    Carta* cartaAtualJ2 = jogo->maoJogador2;
    
    int totalCartasJ1 = contarCartas(cartaAtualJ1);
    int totalCartasJ2 = contarCartas(cartaAtualJ2);
    
    int maxLinhas = (totalCartasJ1 > totalCartasJ2) ? totalCartasJ1 : totalCartasJ2;
    char descricaoCarta[50];  
    printf("Topo do descarte: ");
    cartaParaString(jogo->descarte, descricaoCarta);
    printf("%s\n", descricaoCarta);
    printf("Cartas no monte: %d\n", contarCartas(jogo->monte));
    printf("--------------------------------------------------\n");
    printf("Mao do Jogador 1 (Total: %d) | Mao do Jogador 2 (Total: %d)\n", totalCartasJ1, totalCartasJ2);
    printf("--------------------------------------------------\n");

    for (int i = 0; i < maxLinhas; i++) {
        
        //Jogador 1
        printf("%3d: ", i); 
        int larguraUtilizadaJ1 = 4;
        if (i < totalCartasJ1) {
            cartaParaString(cartaAtualJ1, descricaoCarta);
            printf("%s", descricaoCarta);
            larguraUtilizadaJ1 += strlen(descricaoCarta);
            cartaAtualJ1 = cartaAtualJ1->proximo;
            
        } 
        int espacosParaPreencher = largura_coluna_j1 - larguraUtilizadaJ1; //Cálculo e Alinhamento do Espaço
        if (espacosParaPreencher > 0) {
            imprimirEspacos(espacosParaPreencher);
        }
        printf(" | ");
        
        //Jogador 2
        if (i < totalCartasJ2) {
            cartaParaString(cartaAtualJ2, descricaoCarta); // Imprime a carta J2 e quebra a linha.
            printf("%s\n", descricaoCarta); 
            cartaAtualJ2 = cartaAtualJ2->proximo;
        } else {
            printf("\n"); // Se J2 não tem carta, quebra a linha.
        }
    }
    printf("--------------------------------------------------\n");
}

Carta* criarCarta(int cor, int tipo, int valor) { //aloca memoria para uma nova carta (nó da lista).
    Carta* novaCarta = (Carta*) malloc(sizeof(Carta));
    if (novaCarta == NULL) { 
		return NULL; 
	}
    novaCarta->cor = cor;
    novaCarta->tipo = tipo;
    novaCarta->valor = valor;
    novaCarta->proximo = NULL;
    return novaCarta;
}

Carta* inserirInicio(Carta* topoAtual, Carta* novaCarta) { // Funcao para inserir no topo da lista
    if (novaCarta == NULL) {
    	return topoAtual;	
	}
    novaCarta->proximo = topoAtual;     // o novo elemento aponta para o antigo topo.
    return novaCarta;    // o novo elemento se torna o novo topo.
}

Carta* removerInicio(Carta** topo) { // funcao para remover o elemento do topo.
    if (topo == NULL || *topo == NULL) {
    	return NULL;	
	}
    Carta* removida = *topo;
    *topo = (*topo)->proximo;
    removida->proximo = NULL;
    return removida;
}

Carta* removerCartaPorIndice(Carta** topo, int indice) { // remove elemento por indice (jogar carta da mao).
    if (topo == NULL || *topo == NULL || indice < 0) {
    	return NULL;
	}
    if (indice == 0) {
        return removerInicio(topo);
    }
    Carta* atual = *topo;
    Carta* anterior = NULL;
    
    for (int i = 0; atual != NULL && i < indice; i++) { // Percorre a lista
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
    	return NULL; 
	}
    anterior->proximo = atual->proximo;     //liga o anterior ao proximo.
    atual->proximo = NULL; //desvincula o nó (atual) da lista
    return atual;
}

void embaralhar(Carta** topo) { // converte a lista em um vetor de ponteiros, embaralha o vetor e refaz a lista.
    int totalCartas = contarCartas(*topo); 
    if (totalCartas <= 1) return;
    
    Carta** vetorDeCartas = (Carta**) malloc(totalCartas * sizeof(Carta*));     // aloca um vetor temporario de ponteiros para as cartas.
    if(vetorDeCartas == NULL) exit(1);
    
    Carta* atual = *topo;
    for (int i = 0; i < totalCartas; i++) {
        vetorDeCartas[i] = atual;
        atual = atual->proximo;
    }
    
    // Embaralhamento
    srand(time(NULL));
    for (int i = totalCartas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta* temp = vetorDeCartas[i];
        vetorDeCartas[i] = vetorDeCartas[j];
        vetorDeCartas[j] = temp;
    }
    
    // Reconstroi a lista encadeada a partir do vetor embaralhado.
    *topo = NULL;
    for (int i = 0; i < totalCartas; i++) {
        vetorDeCartas[i]->proximo = *topo;
        *topo = vetorDeCartas[i];
    }
    free(vetorDeCartas); // Libera o array de ponteiros, mas nao as cartas.
}

void reabastecerMonte(Jogo* jogo) { // move as cartas do descarte pro monte e embaralha(tirando o topo).
    printf("O monte ficou sem cartas, pegando cartas da pilha de descarte e embaralhando...\n");
    Carta* novoTopoDescarte = removerInicio(&jogo->descarte);
    if (jogo->descarte == NULL) {
        // se o descarte estiver vazio, realoca a carta.
        jogo->descarte = inserirInicio(jogo->descarte, novoTopoDescarte);
        return;
    }
    jogo->monte = jogo->descarte; // o monte recebe o resto do descarte.
    jogo->descarte = novoTopoDescarte;      // o descarte volta a ter a carta de cima.
    embaralhar(&jogo->monte);     // embaralha o novo monte.
}


int jogadaValida(Carta* carta, Carta* topoDescarte) { // Valida a carta pra jogar no descarte.A jogada eh valida se cor ou tipo/valor combinar.
    if (carta == NULL || topoDescarte == NULL) {
    	return 0;
	} 
    if (carta->cor == topoDescarte->cor) {
    	return 1;
	}
    if (carta->tipo == topoDescarte->tipo) {
        return (carta->tipo == 0) ? (carta->valor == topoDescarte->valor) : 1;
    }
    return 0;
}

int encontrarIndiceJogadaValida(Carta* mao, Carta* topoDescarte) { //encontra a primeira jogada valida na mao.
    Carta* atual = mao;
    int indice = 0;
    while(atual != NULL) {
        if(jogadaValida(atual, topoDescarte)) {
            return indice;
        }
        atual = atual->proximo;
        indice++;
    }
    return -1; // Nenhuma jogada foi encontrada.
}

int encontrarIndiceCartaMaisDois(Carta* mao) { //encontra a primeira carta +2 na mao (usada pra tocar de volta).
    Carta* atual = mao;
    int indice = 0;
    while(atual != NULL) {
        if(atual->tipo == 1) {
            return indice;
        }
        atual = atual->proximo;
        indice++;
    }
    return -1;
}

void proximoJogador(Jogo* jogo) { //alterna entre jogadores
    jogo->jogadorAtual = (jogo->jogadorAtual == 1) ? 2 : 1;
}

void processarMaisDois(Jogo* jogo, int* cartasAcumuladas) { // Logica de empilhamento +2, acumula ate o jogador nao tiver a carta +2.
    proximoJogador(jogo);

    printf("Efeito: +2 acumulado! \n");
    printf("Vez do Jogador %d: jogue um +2 ou compre %d cartas.\n", jogo->jogadorAtual, *cartasAcumuladas);

    int indiceMaisDois;
    Carta* maoDoOponente;

    if (jogo->jogadorAtual == 1) {
        maoDoOponente = jogo->maoJogador1;
    } else {
        maoDoOponente = jogo->maoJogador2;
    }
    indiceMaisDois = encontrarIndiceCartaMaisDois(maoDoOponente);

    if (indiceMaisDois == -1) {
        // Se nao tem +2, compra carta acumulada.
        printf("Jogador %d nao tem um +2. Comprando %d cartas.\n", jogo->jogadorAtual, *cartasAcumuladas);
        for (int i = 0; i < *cartasAcumuladas; i++) {
            if (jogo->monte == NULL) { // se o monte estiver vazio, reabastece.
                reabastecerMonte(jogo);
            }
            if (jogo->monte == NULL) {
                printf("Nao tem cartas suficientes para comprar! Jogo empatado.\n");
                *cartasAcumuladas = -1; // fim do jogo por faltar carta.
                break;
            }
            
            Carta* cartaComprada = removerInicio(&jogo->monte);
            if (jogo->jogadorAtual == 1) {
                jogo->maoJogador1 = inserirInicio(jogo->maoJogador1, cartaComprada);
            } else {
                jogo->maoJogador2 = inserirInicio(jogo->maoJogador2, cartaComprada);
            }
        }
        return;
    } else {
        // Se tem +2, ele joga e acumula.
        Carta* cartaMaisDois;
        if (jogo->jogadorAtual == 1) {
            cartaMaisDois = removerCartaPorIndice(&jogo->maoJogador1, indiceMaisDois);
        } else {
            cartaMaisDois = removerCartaPorIndice(&jogo->maoJogador2, indiceMaisDois);
        }

        char buffer[50];
        cartaParaString(cartaMaisDois, buffer);
        printf("Jogador %d joga tambem um %s!\n", jogo->jogadorAtual, buffer);

        jogo->descarte = inserirInicio(jogo->descarte, cartaMaisDois);
        *cartasAcumuladas += 2;
        processarMaisDois(jogo, cartasAcumuladas);
    }
}


void iniciarSimulacao(Jogo* jogo) { // loop de turnos.
    int jogoAtivo = 1;
    
    Sleep(2000); 

    while (jogoAtivo) {
    	system("cls");
        printf("Vez do Jogador %d\n", jogo->jogadorAtual);
        Carta** maoAtual = (jogo->jogadorAtual == 1) ? &jogo->maoJogador1 : &jogo->maoJogador2; //Ponteiro para o topo da mao do jogador atual.
        exibirMesa(jogo);
        int indiceJogada = encontrarIndiceJogadaValida(*maoAtual, jogo->descarte); //tenta encontrar a primeira jogada valida.
        
        if (indiceJogada != -1) { // Jogada valida foi encontrada: remove, joga e verifica.
            Carta* cartaJogada = removerCartaPorIndice(maoAtual, indiceJogada);
            char buffer[50];
            cartaParaString(cartaJogada, buffer);
            printf("Jogador %d jogou a carta %s.\n", jogo->jogadorAtual, buffer);
            jogo->descarte = inserirInicio(jogo->descarte, cartaJogada);
            if (contarCartas(*maoAtual) == 0) {
                printf("\n*** JOGADOR %d VENCEU! ***\n", jogo->jogadorAtual);
                jogoAtivo = 0;
                Sleep(5000);
                continue;
            }

            if (cartaJogada->tipo == 1) { // se for um +2
                int cartasADesenhar = 2;
                processarMaisDois(jogo, &cartasADesenhar);
                if(cartasADesenhar == -1) jogoAtivo = 0;
            }
        } else { // nenhuma jogada valida: o jogador precisa comprar.
            printf("Jogador %d nao tem carta pra largar, foi obrigado a comprar uma carta.\n", jogo->jogadorAtual);
             if (jogo->monte == NULL) {
                reabastecerMonte(jogo);
            }
            if (jogo->monte == NULL) {
               printf("Nao ha cartas suficientes para comprar! Jogo empatado.\n");
               jogoAtivo = 0;
               continue;
            }
            Carta* cartaComprada = removerInicio(&jogo->monte);
            char buffer[50];
            cartaParaString(cartaComprada, buffer);
            printf("Carta comprada: %s.\n", buffer);
            *maoAtual = inserirInicio(*maoAtual, cartaComprada);
        }
        
        proximoJogador(jogo); // Passa a vez
        Sleep(2500); 
    }
}

Carta* criarBaralho() { // Funcao que cria o baralho inicial (2x cartas de Numero 0-5 e 2x cartas +2 por cor).
    Carta* baralho = NULL;
    for (int c = 0; c <= 2; c++) { // cria as cartas (0-5)
        for (int v = 0; v <= 5; v++) {
            baralho = inserirInicio(baralho, criarCarta(c, 0, v));
        }
    }
    for (int c = 0; c <= 2; c++) {     // cria as cartas (+2)
        baralho = inserirInicio(baralho, criarCarta(c, 1, -1));
        baralho = inserirInicio(baralho, criarCarta(c, 1, -1));
    }
    return baralho;
}

Jogo* iniciarJogo() { // configuracao inicial do jogo.
    printf("Bem vindo ao jogo do UNO...\n");
    Jogo* jogo = (Jogo*) malloc(sizeof(Jogo));
    if(jogo == NULL) exit(1);

    jogo->monte = criarBaralho();
    embaralhar(&jogo->monte);
    jogo->maoJogador1 = NULL;
    jogo->maoJogador2 = NULL;
    
    for(int i = 0; i < 5; i++) { // 5 cartas para cada jogador (remove do monte e insere na mao).
        jogo->maoJogador1 = inserirInicio(jogo->maoJogador1, removerInicio(&jogo->monte));
        jogo->maoJogador2 = inserirInicio(jogo->maoJogador2, removerInicio(&jogo->monte));
    }
    
    // vira a primeira carta do descarte.
    jogo->descarte = NULL;
    jogo->descarte = inserirInicio(jogo->descarte, removerInicio(&jogo->monte));
    
    while (jogo->descarte->tipo != 0) {     // Garante que a primeira carta nao seja uma carta (+2).
        jogo->monte = inserirInicio(jogo->monte, removerInicio(&jogo->descarte));
        embaralhar(&jogo->monte);
        jogo->descarte = inserirInicio(jogo->descarte, removerInicio(&jogo->monte));
    }
    
    jogo->jogadorAtual = 1;
    return jogo;
}

//Liberacao de Memoria

void liberarLista(Carta* topo) {
    if(topo == NULL) return;
    liberarLista(topo->proximo);
    free(topo); 
}

void liberarJogo(Jogo* jogo) {
    if(jogo == NULL) return;
    liberarLista(jogo->monte);
    liberarLista(jogo->descarte);
    liberarLista(jogo->maoJogador1);
    liberarLista(jogo->maoJogador2);
    free(jogo);
}

int main() {
    Jogo* jogo = iniciarJogo();
    if (jogo != NULL) {
        iniciarSimulacao(jogo);
        liberarJogo(jogo);
    }
    printf("\n--- Fim ---\n");
    return 0;
} 