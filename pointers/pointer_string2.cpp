#include<stdio.h>
#include<string.h>
void print_chararr(char *s, int len){
    // Print the string
    for (int i = 0; i < len; i++){
        printf("%c", *s);
        s++;
    }
    printf("\n");
}

char* print_chararr2(char *s, int len){
    // Print the string
    for (int i = 0; i < len; i++){
        printf("%c", *s);
        s++;
    }
    printf("\n");
    return s; // return the address of the next character
}

void edit_chararr(char *s, int len){
    // Edit the string
    for (int i = 0; i < len; i++){
        *s = 'A';
        s++;
    }
}

int main(){
    // null terminated (even if lenfth of d is greater than 5 the print will stop at the null terminator)
    char d[30];
    d[0] = 'J';
    d[1] = 'o';
    d[2] = 'h';
    d[3] = 'n';
    d[4] = ' '; // null terminator
    d[5] = 'D';
    d[6] = 'o';
    d[7] = 'e';
    d[8] = '\0'; // null terminator
    char *p = d; // pointer to the first element of d
    print_chararr(p, 4); // Prints "John"
    // note the address stored in p is copid to s in the function
    // so the value of p is not changed
    print_chararr(p, 8); // Prints "John Doe"

    // now lets see what happens when we return the address of the next character
    p = print_chararr2(p, 4); // Prints "John"
    p = print_chararr2(p, 4); // Prints " Doe"


    //=================================================================================================
    char c1[6] = "Hello";
    char* c2;
    c2 = c1; // c2 points to the first element of c1
    // c2 = c2 is not valid, as c2 is a pointer to a char and c1 is an array of chars
    // c2 = c1 is valid, as c2 is a pointer to a char and c1 is an array of chars
    print_chararr(c2, 5); // Prints "Hello"
    c2[0] = 'A';
    print_chararr(c2, 5); // Prints "Aello"

    c1[0] = 'B';
    c2[1] = 'C';
    print_chararr(c1, 5); // Prints "BCllo"

    // This Is Dangerous (Undefined Behavior)
    c2[7] = 'H';
    print_chararr(c2, 15); // Prints "BCllo" followed by garbage values
    // this is why need to be careful when using pointers

    c1[8] = '9'; // this is also valid
    print_chararr(c2, 15);

    // It might seem to work: In some cases, the program might appear to run without errors, and you might see the value you assigned to c1[8]. This is because the memory location you're accessing might happen to be unused by other parts of your program.
    // It might crash: Your program might crash with a segmentation fault (a memory access violation).
    // It might corrupt data: You might overwrite data that is being used by other variables or parts of your program, leading to unexpected and difficult-to-debug errors.
    // It might exhibit strange behavior: The values of other variables might change unexpectedly, or the program might produce incorrect results.
    // C does not perform automatic bounds checking on array accesses. It's your responsibility as a programmer to ensure that you stay within the valid bounds of your arrays.

    // this is not allowed
    // c1++;

    c2++; // this is allowed
    print_chararr(c2, 5); // Prints "Cllo" (c2 now points to the second element of c1)
    print_chararr(c1, 5); // Prints "BCllo" 

    char *str = "Hello World"; // string literal
    // str[0] = 'A'; // this is not allowed, as str is a pointer to a string literal
    // str++; // this is not allowed, as str is a pointer to a string literal
    printf("%s\n", str); // Prints "Hello World"
    str = "Hello"; // this is allowed, as str is a pointer to a string literal
    printf("%s\n", str); // Prints "Hello"


    // not very safe, use with caution
    // use const char* in functions
    edit_chararr(c1, 5); // Edits the string
    print_chararr(c1, 5); // Prints "AAAAA"

    // not allowed
    // edit_chararr(str, 5); // Edits the string
    print_chararr(str, 5); // Prints "AAAAA"
}
