#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

int div(int x, int y) {
    if (y != 0) {
        return x / y;
    } else {
        printf("0으로 나눌 수 없습니다.\n");
        return 0;
    }
}

int main(void) {
    int result;
    int (*pf)(int, int);
    int choice, x, y;

    while (1) {
        printf("=====================\n");
        printf("0. 덧셈\n");
        printf("1. 뺄셈\n");
        printf("2. 곱셈\n");
        printf("3. 나눗셈\n");
        printf("4. 종료\n");
        printf("=====================\n");
        printf("메뉴를 선택하시오: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("2개의 정수를 입력하시오: ");
        scanf("%d %d", &x, &y);

        switch (choice) {
        case 0:
            pf = add;
            break;
        case 1:
            pf = sub;
            break;
        case 2:
            pf = mul;
            break;
        case 3:
            pf = div;
            break;
        default:
            printf("잘못된 선택입니다.\n");
            continue;
        }

        result = pf(x, y);
        printf("연산 결과 = %d\n", result);
    }

    return 0;
}