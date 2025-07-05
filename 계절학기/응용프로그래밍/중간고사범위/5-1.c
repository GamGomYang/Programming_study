#include <math.h>
#include <stdio.h>

struct distance {
    int x;
    int y;
};

int main(void) {
    struct distance d1;
    struct distance d2;

    printf("점의 좌표를 입력하세요 : ");
    scanf("%d %d", &d1.x, &d1.y);

    printf("점의 좌표를 입력하세요 : ");
    scanf("%d %d", &d2.x, &d2.y);
    double xdiff = (d1.x - d2.x) * (d1.x - d2.x);
    double ydiff = (d1.y - d2.y) * (d1.y - d2.y);
    double dist = sqrt(xdiff + ydiff);

    printf("거리는 %f", dist);
}