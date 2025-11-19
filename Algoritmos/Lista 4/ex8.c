#include <stdio.h>


int converterIdadeParaDias(int anos, int meses, int dias) { [cite: 15]
    int totalDias = (anos * 365) + (meses * 30) + dias; [cite: 16]
    return totalDias;
}

int main() {
    int anos, meses, dias;
    int idadeEmDias;

    printf("Digite sua idade em anos: ");
    scanf("%d", &anos);

    printf("Digite sua idade em meses (apos o ultimo aniversario): ");
    scanf("%d", &meses);

    printf("Digite sua idade em dias (apos o ultimo mes): ");
    scanf("%d", &dias);

    idadeEmDias = converterIdadeParaDias(anos, meses, dias); [cite: 15]

    printf("Sua idade expressa em dias e: %d dias\n", idadeEmDias);

    return 0;
}