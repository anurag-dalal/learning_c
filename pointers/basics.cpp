#include <stdio.h>
int main(){
    int a = 1025;
    int *p;
    p = &a;
    printf("size of integer is %ld bytes\n", sizeof(int)); 
    printf("Address = %d, value = %d\n", p, *p);
    printf("Address = %d, value = %d\n", p+1, *(p+1));
    // the p+1 address is 4 bytes away from p, thus prints garbage value
    char *p0;
    // typecasting
    p0 = (char*)p;
    printf("size of char is %ld bytes\n", sizeof(char));
    printf("Address = %d, value = %d\n", p0, *p0);
    // 1025 = 00000000 00000000 00000100 00000001
    // the first byte is 00000001 the rightmost byte
    printf("Address = %d, value = %d\n", p0+1, *(p0+1));
    // 1025 = 00000000 00000000 00000100 00000001
    // the second byte is 00000100 which is 4
} 
