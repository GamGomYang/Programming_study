#include <stdio.h>
#define STUDENTS 10

int main(void) {

    int scores[STUDENTS];
    int sum = 0;
    int i, average;
    for (i = 0; i < STUDENTS; i++) {
        printf("학생들의 성적을 입력하세요");
        scanf("%d", &scores[i]);
    }

    for (i = 0; i < STUDENTS; i++) {
        sum += scores[i];
    }

    average = sum / STUDENTS;

    printf("성적평균 = %d\n", average);

    return 0;
}