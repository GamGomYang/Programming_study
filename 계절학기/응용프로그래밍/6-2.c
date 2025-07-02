#include <stdio.h>
int main(void) {
    int i = 100;
    int *p = &i;
    int **q = &p;
    int ***k = &q;
    *p = 200;
    printf(" %d\n", i);
    **q = 300;
    printf(" %d\n", i);
    ***k = 1000;
    printf(" %d\n", i);
    return 0;
}