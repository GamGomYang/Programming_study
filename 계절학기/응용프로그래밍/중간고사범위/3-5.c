#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;
    char *array;
    int a, o;
    int index;
    int to, last;

    printf("2보다 큰 수를 입력하시오 : ");
    scanf("%d", &number);

    if (number > 2) {
        array = (char *)calloc(number + 1, sizeof(char));

        if (array != NULL) {
            printf("%d개의 배열을 할당하였습니다.\n", number + 1);
            to = sqrt(number);
            last = number / 2;

            for (a = 2; a <= last; a++) {
                index = a;

                for (o = a * 2; o <= number; o += index) {
                    if (index <= number) {
                        array[index] = 1;
                    } else {
                        break;
                    }
                }
            }

            for (o = 2; o <= number; o++) {
                if (array[o] == 0)
                    printf("%2d ", o);
            }

            free(array);
        }
    }

    return 0;
}
