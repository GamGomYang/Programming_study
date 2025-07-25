#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(void) {

//     int a = 50;
//     int *b = &a;

//     *b = *b + 20;

//     // b = 70; a =70;

//     printf("%d %d \n", a, *b);

//     char *s;
//     s = "gilbut";
//     for (int i = 0; i < 6; i += 2) {
//         printf("%c", s[i]);
//         printf("%c", *(s + i));
// **        printf("%s", s + i); // s + i 부터 전체 문자열 읽어오기
//         // g g gilbut
//         // l l lbut
//         // u u ut
//     }
// }
// struct jsu {
//     char nae[12];
//     int os, db, hab, hhab;
// };

// int main() {
//     struct jsu st[3] = {{"데이터", 95, 98}, {"데이터2", 84, 91}, {"데이터3", 86, 75}};
//     struct jsu *p;
//     p = &st[0];
//     (p + 1)->hab = (p + 1)->os + (p + 2)->db;
//     // 84+75 = 159
//     (p + 1)->hhab = (p + 1)->hab + p->os + p->db;
//     // 159 + 95 +98 = 254 + 98 = 342
//     printf("%d", (p + 1)->hab + (p + 1)->hhab);
//     // 342 + 159 = 501
// }
// int factorial(int n);

// main() {

//     int (*pf)(int);
//     pf = factorial;
//     printf("%d", pf(3));
// }
// int fatorial(int n) {
//     if (n <= 1) {
//         return 1;
//     }

//     else {
//         return n * factorial(n - 1);
//     }
// }

// void recall(int *x) {
//     if (*x == 10000) {
//         return 1;
//     }
//     recall(*x + 1);
// }
// int main(void) {
//     int a = 0;
//     recall(&a);
//     printf("%d", a);
//     return 0;
// }
