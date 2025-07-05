// 셀렉션 소트

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAX 1000

void generate_random(int array[]) {
    for (int n = 0; n < SIZE; n++) {
        array[n] = (rand() % MAX) + 1;
    }
}

void selection_sort(int array[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

void fprint_array(FILE *file, char *str, int array[]) {
    fprintf(file, "%s", str);
    for (int n = 0; n < SIZE; n++) {
        fprintf(file, "%5d", array[n]);
    }
    fprintf(file, "\n");
}

int main(void) {
    int data[SIZE];
    srand(time(NULL));
    FILE *file = fopen("sorted.txt", "w");

    for (int n = 0; n < 3; n++) {
        generate_random(data);
        fprint_array(stdout, "원본: ", data);
        fprint_array(file, "원본: ", data);
        selection_sort(data);
        fprint_array(stdout, "정렬: ", data);
        fprint_array(file, "정렬: ", data);
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}
