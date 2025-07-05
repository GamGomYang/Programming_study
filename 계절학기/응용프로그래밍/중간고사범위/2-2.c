#include <stdio.h>

float find_max(float x, float y, float z) {
    return (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
}

float find_min(float x, float y, float z) {
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

int main(void) {
    float num[3];
    float max, min, difference;

    printf("세개의 수를 입력하세요 \n");

    printf("첫 번째 수: ");
    scanf("%f", &num[0]);
    printf("두 번째 수: ");
    scanf("%f", &num[1]);
    printf("세 번째 수: ");
    scanf("%f", &num[2]);

    max = find_max(num[0], num[1], num[2]);
    min = find_min(num[0], num[1], num[2]);

    difference = max - min;

    printf("\n 큰수와 작은 수의 차이 = %2.1f", difference);

    float mid = find_mid(num[0], num[1], num[2]);
    printf("\n 중간값 = %2.1f", mid);
}

float find_mid(float x, float y, float z) {
    if ((x >= y && x <= z) || (x <= y && x >= z)) {
        return x;
    } else if ((y >= x && y <= z) || (y <= x && y >= z)) {
        return y;
    } else {
        return z;
    }
}
