#include <stdio.h>
#include <string.h>

void substituirPorAsteriscos(char texto[], int inicio, int fim) {
    for (int i = inicio; i < fim; i++) {
        texto[i] = '*';
    }
}

void lerComentario(char comentario[]) {
    printf("Insira um comentario:\n");
    gets(comentario);
}

void exibirResultado(char comentario[]) {
    printf("\nComentario: \n%s\n", comentario);
}

void inicializarPalavrasProibidas(char *palavras[]) {
    palavras[0] = "burro";
    palavras[1] = "feio";
    palavras[2] = "idiota";
    palavras[3] = "bobao";
    palavras[4] = "bobalhao";
    palavras[5] = "trouxa";
    palavras[6] = "pateta";
    palavras[7] = "fedorento";
    palavras[8] = "besta";
    palavras[9] = "tonto";
}

int main() {
    char comentario[201];
    char *palavrasProibidas[10];

    lerComentario(comentario);
    inicializarPalavrasProibidas(palavrasProibidas);

    int totalPalavras = 10;
    int i = 0;

    while (comentario[i] != '\0') {
        char caractereAtual = comentario[i];
        if ((caractereAtual >= 'a' && caractereAtual <= 'z') || 
            (caractereAtual >= 'A' && caractereAtual <= 'Z')) {

            int inicioDaPalavra = i;

            while (1) {
                char proximoCaractere = comentario[i];

                if (!((proximoCaractere >= 'a' && proximoCaractere <= 'z') ||
                      (proximoCaractere >= 'A' && proximoCaractere <= 'Z'))) {
                    break;
                }
                i++;
            }

            int tamanhoPalavra = i - inicioDaPalavra;
            int encontrou = 0;

            for (int p = 0; p < totalPalavras; p++) {
                char *palavraProibida = palavrasProibidas[p];
                int comprimento = 0;

                while (palavraProibida[comprimento] != '\0') {
                    comprimento++;
                }

                if (comprimento == tamanhoPalavra) {
                    int saoIguais = 1;

                    for (int j = 0; j < tamanhoPalavra; j++) {
                        char letraComentario = comentario[inicioDaPalavra + j];

                        if (letraComentario >= 'A' && letraComentario <= 'Z') {
                            letraComentario += 32;
                        }

                        char letraLista = palavraProibida[j];

                        if (letraComentario != letraLista) {
                            saoIguais = 0;
                            break;
                        }
                    }

                    if (saoIguais) {
                        encontrou = 1;
                        break;
                    }
                }
            }

            if (encontrou) {
                substituirPorAsteriscos(comentario, inicioDaPalavra, i);
            }

        } else {
            i++;
        }
    }

    exibirResultado(comentario);

    return 0;
}