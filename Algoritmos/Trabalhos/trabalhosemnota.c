/**
Cadastro de Partidas:
No programa principal (main), declare um array de 3 elementos do tipo Partida;
Exemplos: FLA x RMA; FLA x PSG; RMA x PSG.
Preencha os dados para cada uma das 3 partidas do array, solicitando ao usuário que digite as informações do teclado para cada campo.

**/
#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[50];
	char sigla[3];
} Clube;

typedef struct {
	int idPartida;
	Clube clubeCasa;
	Clube clubeVisitante;
	int golsCasa;
	int golsVisitante;
} Partida;

void definirSigla(Partida p[]) {
    int i, j, g;

    for(i = 0; i < 3; i++) {
        g = 0;
        int novaPalavra = 1;
        for(j = 0; p[i].clubeCasa.nome[j] != '\0' && g < 3; j++) {
            if(p[i].clubeCasa.nome[j] != ' ' && novaPalavra) {
                p[i].clubeCasa.sigla[g++] = p[i].clubeCasa.nome[j];
                novaPalavra = 0;
            } else if(p[i].clubeCasa.nome[j] == ' ') {
                novaPalavra = 1;
            }
        }
        p[i].clubeCasa.sigla[g] = '\0';
        puts(p[i].clubeCasa.sigla);
    }

    for(i = 0; i < 3; i++) {
        g = 0;
        int novaPalavra = 1;
        for(j = 0; p[i].clubeVisitante.nome[j] != '\0' && g < 3; j++) {
            if(p[i].clubeVisitante.nome[j] != ' ' && novaPalavra) {
                p[i].clubeVisitante.sigla[g++] = p[i].clubeVisitante.nome[j];
                novaPalavra = 0;
            } else if(p[i].clubeVisitante.nome[j] == ' ') {
                novaPalavra = 1;
            }
        }
        p[i].clubeVisitante.sigla[g] = '\0';
        puts(p[i].clubeVisitante.sigla);
    }
}
	
void buscarClubes(Partida p[]) {
	char siglaBuscar[50];
	printf("Insira o que quer buscar: ");
	fflush(stdin);
	gets(siglaBuscar);
	int i;
	for(i=0; i < 3; i++) {
		if(strcmp(p[i].clubeCasa.sigla, siglaBuscar) == 0 || strcmp(p[i].clubeVisitante.sigla, siglaBuscar) == 0) {
			printf("Time da casa: ");
            puts(p[i].clubeCasa.nome);
            printf("Time visitante: ");
            puts(p[i].clubeVisitante.nome);
            printf("Quantidade de gols do time da casa: %d\n", p[i].golsCasa);
            printf("Quantidade de gols do visitante: %d\n", p[i].golsVisitante);
            printf("Id da partida: %d\n\n", p[i].idPartida);
		}
		else {
			printf("Nao encontrado!");
			break;
		}
	}
}

int main() {
	Partida p[3];
	int i;
	for(i=0; i < 3; i++) {
		printf("Insira o nome do time da casa: ");
		fflush(stdin);
		gets(p[i].clubeCasa.nome);
		printf("Insira o nome do time visitante: ");
		fflush(stdin);
		gets(p[i].clubeVisitante.nome);
		printf("Insira a quantidade de gols do time da casa: ");
		scanf("%d",&p[i].golsCasa);
		printf("Insira a quantidade de gols do visitante: ");
		scanf("%d",&p[i].golsVisitante);
		p[i].idPartida = 100+i;
	}
	definirSigla(p);
	buscarClubes(p);
	return 0;
	

}
