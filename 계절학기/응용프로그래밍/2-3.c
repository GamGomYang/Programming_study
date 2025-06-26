#include <math.h>
#include <stdio.h>

#define NUMMAX 10
void get_data();
void calc_average(int count, float *mean);
void calc_stdev(float mean, int count, float *stdev);
float num[NUMMAX];

int main(void) {
    float avg, stdev;

    get_data();
    int count = 0;
    for (int i = 0; i < NUMMAX; i++) {
        if (num[i] == -1) {
            break;
        }
        count++;
    }

    calc_average(count, &avg);
    calc_stdev(avg, count, &stdev);

    printf("평균 = %.2f \n", avg);
    printf("표준편차 = %.2f\n\n", stdev);

    return 0;
}

void get_data() {
    for (int i = 0; i < NUMMAX; i++) {
        printf("실수를 입력하세요 %dth : ", i + 1);
        scanf("%f", &num[i]);
        if (num[i] == -1) {
            break;
        }
    }
}

void calc_average(int count, float *mean) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += num[i];
    }
    *mean = sum / count;
}

void calc_stdev(float mean, int count, float *stdev) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += (num[i] - mean) * (num[i] - mean);
    }
    *stdev = sqrt(sum / count);
}
