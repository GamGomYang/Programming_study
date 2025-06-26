#include <stdlib.h>
#include <time.h>
#define NUM 10 // 전체 투표 수

void init_input(int sel[]);
void out_prt(int sel[]);

int main() {
    int xdata; // 무작위 투표 후보 번호
    int n;
    int ip[5] = {
        0,
    }; // 각 후보의 투표 수 저장
    init_input(ip); // 투표 시뮬레이션 수행
    out_prt(ip);    // 결과 출력
    return 0;
}

void init_input(int sel[]) {
    int xdata;
    int n;
    srand((unsigned)time(NULL)); // 난수 시드 설정
    printf("1~4번 중 한 후보의 번호를 선택합니다.\n");
    printf("후보자 | 투표 결과\n");

    for (n = 0; n < NUM; n++) {
        xdata = rand() % 5; // 0~4 중 하나의 정수 (총 5명의 후보)
        printf("%2d     %2d \n", n + 1, xdata);
        sel[xdata]++; // 해당 후보의 투표 수 증가
    }
}

void out_prt(int sel[]) {
    int n;
    for (n = 0; n < 5; n++) {
        if (n == 0)
            printf("후보표 %2d : %2d표\n", n, sel[n]);
        else
            printf("후보자 %2d : %2d표\n", n, sel[n]);
    }
}
