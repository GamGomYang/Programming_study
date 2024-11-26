#include <stdio.h>

int main() {

    int i = 3000;
    int *p = NULL;

    p = &i;

    printf("p = %p\n\n", p);
    printf("&i = %p\n\n", &i);

    printf("i = %d\n", i);
    printf("*p = %d\n", *p);

    return 0;
}