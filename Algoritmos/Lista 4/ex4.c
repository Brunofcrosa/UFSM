#include <stdio.h>


int verificarMaior(int numeroParametro) { [cite: 5]
    int valorUsuario;

    printf("Digite um valor para comparacao: ");
    scanf("%d", &valorUsuario);

    if (numeroParametro > valorUsuario) {
        return 1; [cite: 5]
    } else {
        return 0; [cite: 5]
    }
}

int main() {
    int meuNumero;
    int resultadoVerificacao;

    printf("Digite um numero para ser comparado: ");
    scanf("%d", &meuNumero);

    resultadoVerificacao = verificarMaior(meuNumero);

    if (resultadoVerificacao == 1) {
        printf("O numero %d e maior que o valor inserido pelo usuario.\n", meuNumero);
    } else {
        printf("O numero %d nao e maior que o valor inserido pelo usuario.\n", meuNumero);
    }

    return 0;
}