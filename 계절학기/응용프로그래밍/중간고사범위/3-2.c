#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROLLS 100

void roll_dice(int counts[]);
void print_results(int counts[]);

int main() {
    int counts[6] = {0};
    roll_dice(counts);
    print_results(counts);
    return 0;
}

void roll_dice(int counts[]) {
    int roll;
    srand((unsigned)time(NULL));

    for (int i = 0; i < NUM_ROLLS; i++) {
        roll = rand() % 6;
        counts[roll]++;

        printf("%d     %d\n", i + 1, roll);
    }
}

void print_results(int counts[]) {
    for (int i = 0; i < 6; i++) {
        printf("주사위면 %d : %d회\n", i + 1, counts[i]);
    }
}