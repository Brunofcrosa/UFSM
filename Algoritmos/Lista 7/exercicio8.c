#include <stdio.h>
#include <string.h>

int main() {
    char strA[100];
    char strB[100];
    char strC[201];
    int i = 0, j = 0, k = 0;
    int lenA, lenB;

    printf("Digite a primeira string (A): ");
    fgets(strA, sizeof(strA), stdin);
    strA[strcspn(strA, "\n")] = '\0';

    printf("Digite a segunda string (B): ");
    fgets(strB, sizeof(strB), stdin);
    strB[strcspn(strB, "\n")] = '\0';

    lenA = strlen(strA);
    lenB = strlen(strB);

    while (i < lenA && j < lenB) {
        strC[k++] = strA[i++];
        strC[k++] = strB[j++];
    }

    while (i < lenA) {
        strC[k++] = strA[i++];
    }

    while (j < lenB) {
        strC[k++] = strB[j++];
    }

    strC[k] = '\0';

    printf("String C (intercalada): %s\n", strC);

    return 0;
}