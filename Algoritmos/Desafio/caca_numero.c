/** Trabalho 1: caça ao número
Implemente um jogo em que o jogador deve descobrir as posições de valores especiais escondidos em uma matriz 5x5. O programa gera aleatoriamente 5 posições secretas, marcadas com o valor 9, mas que o jogador não vê. O jogador tem 10 tentativas para acertar o maior número possível de posições corretas.
Regras do Jogo:
A matriz começa com todos os valores como 0 (oculta).
O programa insere cinco valores 9 em posições aleatórias da matriz.

O jogador, em cada rodada:
Informa as coordenadas da tentativa (linha e coluna).
Se acertar uma posição com 9, ganha 1 ponto.
Se errar, a posição é marcada como -1.                                                
O jogo termina após 10 tentativas ou quando o jogador encontra todas as posições com 9.                                      
"No comments in the code, just the code itself, without using pointers, using struct and as simple as possible,
as if for a beginner and in Portuguese."
O que exibir ao final:
Matriz final com acertos (9), erros (-1) e posições não reveladas (0);
Número de acertos do jogador;
Uma função que calcule a eficiência: (acertos / tentativas) * 100%
Casos omissos ao enunciado devem ser tratados pelo aluno e fazem parte da avaliação.
**/

// incluir bibliotecas necessárias
#include <stdio.h>    // para ler dados e imprimir na tela
#include <stdlib.h>   // para funcionar o srand
#include <time.h>     // para numeros aleatorios a cada execução
#include <windows.h>  // para funcionar o console com acentuações

// Função para começar a matriz com todos os valores como 0.
void inicializarMatriz(int matriz[5][5]) {     
    for (int i = 0; i < 5; i++) {          			// um for para percorrer o i matriz[i][j]
        for (int j = 0; j < 5; j++) {      			// um for para percorrer o j matriz[i][j]
            matriz[i][j] = 0;               	    // setar os elementos da matriz como 0;
        }
    }
}

// Função para inserir cinco valores 9 em posições aleatórias utilizando srand.
void esconderValoresEspeciais(int matriz[5][5]) {
    int quantidadeEscondida = 0;       				// inicializar como 0 para contar os elementos sem bugs;
    srand(time(NULL));      						// randomizar;

    while (quantidadeEscondida < 5) { 
        int linha = rand() % 5;       				// dividir um numero aleatorio(rand) por 5 e colocar o resultado na variavel linha;
        int coluna = rand() % 5;	  				// dividir um numero aleatorio(rand) por 5 e colocar o resultado na variavel coluna;
        if (matriz[linha][coluna] == 0) {           // verificar se foi inicializado em 0;
            matriz[linha][coluna] = 9;              // seta os elementos da matriz como 9, usando o resultado linha e coluna como base;
            quantidadeEscondida++;                  // fazer o count do while, pois são 5 numeros no total;
        }
    }
}

// Função para validar a tentativa.
int validarTentativa(int matriz[5][5], int linha, int coluna) {
    if (matriz[linha][coluna] == 9) {
        printf("Acertou, ganhou um ponto!\n");   	// se a posição escolhida pelo jogador possuir o valor 9, irá mostrar na tela "Acertou".
        matriz[linha][coluna] = 1;					// irá marcar como 1, para que o programa possa verificar que o usuário já acertou essa posição.
        return 1; 									// retorna 1 para que na função principal reconheça uma tentativa válida.
    } else if (matriz[linha][coluna] == -1 || matriz[linha][coluna] == 1) {
        printf("Tentativa repetida, insira uma posição diferente!\n");   // se a posição tiver ou o -1(errado) ou o 1(correto), irá retornar que já tentou a posição.
        return -1; 									// retorna -1 para que na função principal reconheça uma tentativa inválida. 
    } else {
        printf("Errou!\n");         				// mostra na tela que o usuario errou.
        matriz[linha][coluna] = -1; 				// marca erro na posição escolhida pelo jogador.
        return 0;  									// retorna 0 para que na função principal reconheça uma tentativa válida.
    }
}

// Função para exibir a matriz final.
void exibirMatrizFinal(int matriz[5][5]) {
    printf("\nMatriz final:\n");       				// print para mostrar na tela a matriz final.
    for (int i = 0; i < 5; i++) {       			// um laço de repetição(for) para percorrer o i da matriz[i][j]
        for (int j = 0; j < 5; j++) {				// um laço de repetição(for) para percorrer o j da matriz[i][j]
            if (matriz[i][j] == 9) {    			// se algum elemento tiver como valor o 9, irá:
                printf("%3d", 0); 					// Tem o numero, vai printar 0, pois o usuario não conseguiu encontrar esse numero. "Matriz final com acertos (9), erros (-1) e posições não reveladas (0);"
            } else if (matriz[i][j] == 1) {			// se algum elemento tiver como valor 0 1, irá:
                printf("%3d", 9); 					// Tem o numero, vai printar 1, pois o usuario conseguiu acertar. "Matriz final com acertos (9), erros (-1) e posições não reveladas (0);"
            } else {								// se tiver algum numero diferente daquele, vai resultar:
                printf("%3d", matriz[i][j]); 		// -1 para erro. "Matriz final com acertos (9), erros (-1) e posições não reveladas (0);"
            }
        }
        printf("\n");
    }
}

// Função para exibir os resultados finais
void exibirResultados(int acertos, int tentativas) {
    float eficiencia;                       			   				  // declarar como float, pois a eficiencia vai retornar numeros não inteiros. 
    eficiencia = ((float)acertos / tentativas) * 100.0;    				  // cálculo da eficiência: (acertos / tentativas) * 100%.
    
    printf("\nRESULTADOS:\n");                             				  // resultados para ficar mais bonito
    printf("Encontrou: %d/5\n", acertos);                  				  // print dos acertos
    printf("Precisão de acerto: %.1f%%\n", eficiencia);    				  // print da eficiencia
}

// Função principal
int main() {
    int matriz[5][5];                                     				  // declarar a matriz 5x5                        
    int acertos = 0;								      				  // declarar a variavel como 0, para evitar possiveis bugs.
    int tentativasValidas = 0;							 				  // declarar a variavel como 0, para evitar possiveis bugs.
    SetConsoleOutputCP(65001);                            				  // novamente usando nesse trabalho, para permitir no console acentuações.
    

    inicializarMatriz(matriz);                            				  // chamando a função inicializarMatriz e passando a variavel matriz como parametro. 
    esconderValoresEspeciais(matriz);					                  // chamando a função esconderValoresEspeciais e passando a variavel matriz como parametro. 

    printf("Seja Bem-vindo ao jogo Caça ao Número!\n");        	 		  // print do inicio do jogo
    printf("Você possui 10 tentativas para desvendar as 5 posições que se encontram o número escondido.\n");   // print das regras

    for (int tentativa = 1; tentativa <= 10; tentativa++) {               // um for para delimitar a quantidade de tentativas;
        int linha, coluna;												  // declarando variaveis
        printf("\nTentativa %d de 10:\n", tentativa);                     // print mostrando em qual tentativa o usuario se encontra.
        printf("Insira a linha (0 a 4): ");                               // print para o jogador escolher a posição da linha que deseja desvendar.
        scanf("%d", &linha);											  // scan da entrada do teclado para atribuir um valor a variavel linha.
        printf("Insira a coluna (0 a 4): ");                              // print para o jogador escolher a posição da coluna que deseja desvendar.
        scanf("%d", &coluna);											  // scan da entrada do teclado para atribuir um valor a variavel coluna.	

        if (linha < 0 || linha >= 5 || coluna < 0 || coluna >= 5) {       // if para validar a entrada do jogador, para que não fuja dos índices da matriz 5x5.
            printf("Posição inválida. Tente novamente.\n");               // print para mostrar que o jogador digitou errado.
            tentativa--; 								                  // usa o incrementador -- para diminuir a quantidade de tentativas, pois toda vez que roda o laço ele iria contar ++.
            continue;                                                     // continue para não executar o restante do for, para pular para o inicio do for.
        }

        int resultado = validarTentativa(matriz, linha, coluna);          // declara a variavel resultado como inteiro e seta o resultado dele a partir da função validarTentativa e usando como parametro matriz,linha,coluna;
        
        if (resultado == 1) {                                             // se o retorno do resultado for exatamente igual a 1, o jogador acertou: 
            acertos++;												      // count dos acertos.
            tentativasValidas++;										  // count das tentativas.
        } else if (resultado == 0) {                                      // se o retorno do resultado por exatamente igual a 0, o jogador não encontrou:
            tentativasValidas++;										  // count das tentativas.
        } else {														  // diferente, retornou -1, o usuário já tentou essa posição.
            tentativa--;												  // Não conta tentativa repetida
        }
        
        if (acertos == 5) {                                               // se o usuario atingir 5 acertos:    
        	break;													      // encerra o for.
		}
    }

    exibirMatrizFinal(matriz);                                            // chamando a função exibirMatrizFinal e passando a variável matriz como parametro. 
    exibirResultados(acertos, tentativasValidas);						  // chamando a função exibirResultados e passando as variáveis acertos e tentativasValidas como parametro. 
    return 0;
}