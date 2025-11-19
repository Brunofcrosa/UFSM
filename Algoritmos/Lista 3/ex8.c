#include <stdio.h>

void fibonacci() {
    int t1 = 0;
    int t2 = 1;
    int proximoTermo;

    printf("--- Serie Fibonacci (ate o 15o termo) ---\n");
    printf("%d, %d", t1, t2); 

    for (int i = 3; i <= 15; i++) {
        proximoTermo = t1 + t2;
        printf(", %d", proximoTermo);
        t1 = t2;
        t2 = proximoTermo;
    }
    printf("\n----------------------------------------\n\n");
}

int main() {
    fibonacci();
    return 0;
}