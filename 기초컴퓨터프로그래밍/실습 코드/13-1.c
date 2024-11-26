#include <stdio.h>

int main() {
    int i = 10;
    char c = 69;
    float f = 12.3;

    printf(" i addr = %p\n", &i);
    printf("c addr = %p\n", &c);
    printf("f addr = %p\n", &f);

    return 0;
}