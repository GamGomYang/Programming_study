#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;
    char *array;
    int k;

    printf("정수를 입력하세요: ");
    scanf("%d", &number);
    if (number > 2) {
        array = (char *)calloc(number + 1, sizeof(char));
        if (array != NULL) {
            printf("%d개의 배열을 할당하였습니다.\n", number + 1);

            for (k = 0; k < number; k++)
                printf("%d  ", array[k]);

            free(array);
        }
    }
    return 0;
}