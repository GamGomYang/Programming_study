#include <stdio.h>
#include <string.h>

int main(void) {

    char subject[20];
    int grade;
    int year;
    char name[20];
    printf("정보를 입력하세요 \n");
    printf("학과 :");

    scanf("%s", subject);

    printf("학년 : ");
    scanf("%d", &grade);

    printf("입학년도 : ");
    scanf("%d", &year);

    printf("이름 : ");
    scanf("%s", name);

    printf("나는 %s %d학년 %d학번 %s입니다.", subject, grade, year, name);

    return 0;
}