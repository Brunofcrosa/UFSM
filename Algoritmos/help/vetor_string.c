#include <stdio.h>
#include <string.h>


void extrairIniciais(char nomeCompleto[], char iniciais[]) {
    int i = 0; 
    int j = 0; 


    if (nomeCompleto[0] != '\0' && nomeCompleto[0] != ' ' && nomeCompleto[0] != '\t' &&
        nomeCompleto[0] != '\n' && nomeCompleto[0] != '\r' &&
        nomeCompleto[0] != '\f' && nomeCompleto[0] != '\v') {
        iniciais[j++] = nomeCompleto[0];
        iniciais[j++] = '.';
        iniciais[j++] = ' ';
    }

    for (i = 1; nomeCompleto[i] != '\0'; i++) {
 
        int charAtualEhEspaco = (nomeCompleto[i] == ' ' || nomeCompleto[i] == '\t' ||
                                 nomeCompleto[i] == '\n' || nomeCompleto[i] == '\r' ||
                                 nomeCompleto[i] == '\f' || nomeCompleto[i] == '\v');

        int proximoCharNaoEhEspacoOuNulo = (nomeCompleto[i + 1] != '\0' &&
                                            nomeCompleto[i + 1] != ' ' && nomeCompleto[i + 1] != '\t' &&
                                            nomeCompleto[i + 1] != '\n' && nomeCompleto[i + 1] != '\r' &&
                                            nomeCompleto[i + 1] != '\f' && nomeCompleto[i + 1] != '\v');

        if (charAtualEhEspaco && proximoCharNaoEhEspacoOuNulo) {
            iniciais[j++] = nomeCompleto[i + 1];
            iniciais[j++] = '.';
            iniciais[j++] = ' ';
        }
    }

    
    if (j > 0 && iniciais[j-1] == ' ') {
        j--; 
    }
    iniciais[j] = '\0'; 
}

int main() {
    char nomeCompleto[256]; 
    char iniciais[20 * 3 + 1]; 

    printf("Por favor, digite seu nome completo: ");
    fgets(nomeCompleto, sizeof(nomeCompleto), stdin);

    nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0';

    extrairIniciais(nomeCompleto, iniciais);

    printf("As iniciais do nome são: %s\n", iniciais);

    return 0;
}