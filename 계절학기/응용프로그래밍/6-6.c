#include <stdio.h>

#define COLS 3

double get_row_avg(int m[][COLS], int r) {
    int *p, *endp;
    double sum = 0.0;
    p = &m[r][0];
    endp = &m[r][COLS];
    while (p < endp)
        sum += *p++;
    sum /= COLS;
    return sum;
}

double get_total_avg(int m[][COLS]) {
    int *p, *endp;
    double sum = 0.0;
    p = &m[0][0];
    endp = &m[3][0];
    while (p < endp)
        sum += *p++;
    sum /= (COLS * 3);
    return sum;
}

int main(void) {
    int m[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};

    printf("m = %p\n", m);
    printf("m[0] = %p\n", m[0]);
    printf("m[1] = %p\n", m[1]);
    printf("m[2] = %p\n", m[2]);
    printf("&m[0][0] = %p\n", &m[0][0]);
    printf("&m[1][0] = %p\n", &m[1][0]);
    printf("&m[2][0] = %p\n", &m[2][0]);

    for (int i = 0; i < 3; i++) {
        printf("행 %d의 평균: %.2f\n", i, get_row_avg(m, i));
    }

    printf("전체 평균: %.2f\n", get_total_avg(m));

    return 0;
}
