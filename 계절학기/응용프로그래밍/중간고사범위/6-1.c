// #include <stdio.h>
// int main(void) {
//     int i = 100;
//     int *p = &i;
//     int **q = &p;
//     *p = 200;
//     printf(" %d\n", i);
//     **q = 300;
//     printf(" %d\n", i);
//     return 0;
// }
// #include <stdio.h>
// int main(void) {
//     char *p;
//     set_pointer(&p);
//     printf("오늘의 격언 %s\n", p);
//     return 0;
// }
// void set_pointer(char **q) {
//     *q = "All that glister is not gold";
// }
// #include <stdio.h>
// int main(void) {
//     int i, n;
//     char *fruits[] = {
//         "apple",
//         "bluberry",
//         "orange",
//         "melon"};
//     n = sizeof(fruits) / sizeof(fruits[0]);
//     for (int i = 0; i < n; i++) {
//         printf(" %s \n", fruits[i]);
//     }
//     return 0;
// }
// #include <stdio.h>
// int main(void) {
//     int a[5] = {1, 2, 3, 4, 5};
//     int (*pa)[5];
//     int i;
//     pa = &a;
//     for (int i = 0; i < 5; i++) {
//         printf("%d\n", (*pa)[i]);
//         return 0;
//     }
// }
#include <stdio.h>

int main(void) {

    int a[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {

        printf("&a[%d] = %u\n", i, &a[i]);
    }

    printf("++++++++++++++++++++++++++++\n");

    for (int i = 0; i < 5; i++) {

        printf("a + %d = %u\n", i, (a + i));
    }

    printf("a = %u\n", a);

    return 0;
}