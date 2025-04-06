#include<stdio.h>
#include<string.h>
int main(){

    // not null terminated
    char c[8];
    c[0] = 'J';
    c[1] = 'o';
    c[2] = 'h';
    c[3] = 'n';
    printf("c: %s|---end", c); // Undefined behavior, as c is not null terminated, prints extra characters
    // Prints "John" followed by garbage values until a null terminator is found
    printf("\n");
    for (int i = 0; i < 8; i++){
        printf("[%d]-%c-", i, c[i]); // Prints the characters in c
    }
    printf("\n");
    
    
    // null terminated (even if lenfth of d is greater than 5 the print will stop at the null terminator)
    char d[30];
    d[0] = 'J';
    d[1] = 'o';
    d[2] = 'h';
    d[3] = 'n';
    d[4] = '\0'; // null terminator
    printf("d: %s|---end", d); // Prints "John---end"
    printf("\n");
    for (int i = 0; i < 30; i++){
        printf("[%d]-%c-", i, d[i]); // Prints the characters in d
    }
    printf("\n");
    printf("Length of c: %d, size of c:%d\n", strlen(c), sizeof(c));
    printf("Length of c: %d, size of d:%d\n", strlen(d), sizeof(d));
    
    char e[] = "John";
    printf("%s|---end", e); // Prints "John---end"
    printf("\n");
    for (int i = 0; i < 30; i++){
        printf("[%d]-%c-", i, e[i]); // Prints the characters in e
    }
    printf("\n");
    printf("Length of e: %d, size of e:%d\n", strlen(e), sizeof(e));
}