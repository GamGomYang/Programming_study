#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble(int array[], int last) {
    int m;
    for (m = 0; m < last; m++) {
        if (array[m] > array[m + 1]) {
            swap(&array[m], &array[m + 1]);
        }
    }
}

void bubble_sort(int array[], int size) {
    int n;
    for (n = 0; n < size - 1; n++) {
        bubble(array, size - n - 1);
    }
}

void fprint_array(const char *filename, int array[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("에러");
        return;
    }
    fprintf(file, "정렬된 배열: ");
    for (int n = 0; n < size; n++) {
        fprintf(file, "%5d", array[n]);
    }
    fprintf(file, "\n");
    fclose(file);
}

int main(void) {
    int size;
    printf("배열의 크기를 입력하세요: ");
    scanf("%d", &size);
    int *data = (int *)malloc(size * sizeof(int));
    if (data == NULL) {
        perror("에러");
        return 1;
    }
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        data[i] = (rand() % 1000) + 1;
    }

    printf("원본: ");
    for (int n = 0; n < size; n++) {
        printf("%5d", data[n]);
    }
    printf("\n");

    bubble_sort(data, size);

    printf("정렬: ");
    for (int n = 0; n < size; n++) {
        printf("%5d", data[n]);
    }
    printf("\n");

    fprint_array("sorted.txt", data, size);
    printf("정렬된 배열이 sorted.txt에 저장되었습니다.\n");

    free(data);
    return 0;
}
