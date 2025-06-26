#include <stdio.h>
#define NMAX 5

int main() {
    int ip[NMAX] = {0};
    int n = 0;
    int xdata = 0, i;

    printf("1~4번 중 한 후보의 번호를 입력하시오 : ");
    while (scanf("%d", &xdata) == 1) {
        n++;
        if (xdata >= 1 && xdata <= 4) {
            ip[xdata]++;
        } else {
            ip[0]++;
        }
        printf("1~4번 중 한 후보의 번호를 입력하시오 : ");
    }

    printf("\n득표수\n");
    for (i = 1; i < NMAX; i++) {
        printf("%d번 : %d 표\n", i, ip[i]);
    }
    printf("무효표 : %d표 \n", ip[0]);
    printf("총투표수 : %d표 \n", n);

    return 0;
}
