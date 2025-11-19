#include <stdio.h>
#include <string.h>
/****************2. strlen() ******************/
/*** 

int main() {
    char nome[] = "Maria";
    printf("Tamanho: %lu\n", strlen(nome));  
    return 0;
}
***/

/****************2. strcpy() ******************/

/*** 
char destino[20];
strcpy(destino, "Olá Mundo");  // Copia "Olá Mundo" para destino
***/

/****************3. strncpy() ******************/
/***
char destino[20];
strncpy(destino, "Bom dia", 4);  // Copia "Bom"
destino[4] = '\0';               // Garante terminação
***/

/****************4. strcat() ******************/
/***
char saudacao[50] = "Bom ";
strcat(saudacao, "dia!");     // Resultado: "Bom dia!"
***/

/****************5. strncat() ******************/
/***
char saudacao[50] = "Bom ";
strncat(saudacao, "dia!", 3);  // Resultado: "Bom dia"
***/

/****************6. strcmp() ******************/
/***
if (strcmp("abc", "abc") == 0) {
    printf("Strings iguais\n");
}
***/

/****************7. strncmp() ******************/
/***
if (strncmp("abc", "abcd", 3) == 0) {
    printf("Strings iguais\n");
}
***/
