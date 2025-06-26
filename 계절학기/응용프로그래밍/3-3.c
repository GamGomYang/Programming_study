// 3-3.c 소수 찾기
#include <math.h>
#include <stdio.h>

int is_prime(int n) {
    int prime = 1;
    if (n < 2)
        return 0;

    int to = (int)sqrt((double)n);
    for (int divider = 2; divider <= to; divider++) {
        if ((n % divider) == 0) {
            prime = 0;
            break;
        }
    }
    return prime;
}

int main() {
    int number;
    while (1) {
        printf("소수를 판정할 정수를 입력하세요(1 이하의 수이면 종료): ");
        scanf("%d", &number);
        printf("");
        if (number >= 2) {
            if (is_prime(number)) {
                printf("%d는 소수입니다.\n", number);
            } else {
                printf("%d는 소수가 아닙니다.\n", number);
            }
        } else {
            printf("%d에 대한 소수를 판정할 수 없습니다.\n", number);
            printf("프로그램을 종료합니다.\n");
            break;
        }
        printf("\n");
    }
    return 0;
}
