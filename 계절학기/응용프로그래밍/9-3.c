#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int ubingo[SIZE][SIZE];
int cbingo[SIZE][SIZE];
int checked[25];
int count = 0;

void initialize();
void erase_bingo(int arr[][SIZE], int number);
void print_bingo(int arr[][SIZE]);
void print_winner(int winner);
int get_number(int from);
int check_bingo(int arr[][SIZE]);

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void set_rand(int *array) {
    for (int i = 0; i < 25; i++) {
        array[i] = i + 1;
    }
    for (int i = 0; i < 25; i++) {
        int j = rand() % 25;
        swap(&array[i], &array[j]);
    }
}

void initialize() {
    srand(time(NULL));
    int numbers1[25], numbers2[25];
    set_rand(numbers1);
    set_rand(numbers2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            ubingo[i][j] = numbers1[i * SIZE + j];
            cbingo[i][j] = numbers2[i * SIZE + j];
        }
    }
}

void print_bingo(int arr[][SIZE]) {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (arr[y][x] != -1)
                printf("%5d", arr[y][x]);
            else
                printf(" XX");
        }
        printf("\n");
    }
}

int get_number(int from) {
    int number;
    if (from == 0) {
        do {
            printf("1~25 사이의 숫자를 입력하세요: ");
            scanf("%d", &number);
        } while (number < 1 || number > 25);
    } else {
        do {
            number = rand() % 25 + 1;
        } while (checked[number - 1] != 0);
    }
    checked[number - 1] = 1;
    return number;
}

void erase_bingo(int arr[][SIZE], int number) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] == number) {
                arr[i][j] = -1;
            }
        }
    }
}

int check_bingo(int arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if ((arr[i][0] == -1 && arr[i][1] == -1 && arr[i][2] == -1 && arr[i][3] == -1 && arr[i][4] == -1) ||
            (arr[0][i] == -1 && arr[1][i] == -1 && arr[2][i] == -1 && arr[3][i] == -1 && arr[4][i] == -1)) {
            return 1;
        }
    }
    if ((arr[0][0] == -1 && arr[1][1] == -1 && arr[2][2] == -1 && arr[3][3] == -1 && arr[4][4] == -1) ||
        (arr[0][4] == -1 && arr[1][3] == -1 && arr[2][2] == -1 && arr[3][1] == -1 && arr[4][0] == -1)) {
        return 1;
    }
    return 0;
}

void print_winner(int winner) {
    switch (winner) {
    case 1:
        printf("사용자가 이겼습니다.\n");
        break;
    case 2:
        printf("컴퓨터가 이겼습니다.\n");
        break;
    case 3:
        printf("비겼습니다.\n");
        break;
    default:
        printf("뭔가 이상합니다.\n");
        break;
    }
}

int main() {
    int number, uwin, cwin;

    initialize();
    do {
        printf("사용자\n");
        print_bingo(ubingo);
        number = get_number(0);
        erase_bingo(ubingo, number);
        erase_bingo(cbingo, number);

        number = get_number(1);
        erase_bingo(ubingo, number);
        erase_bingo(cbingo, number);

        uwin = check_bingo(ubingo);
        cwin = check_bingo(cbingo);
    } while ((uwin == 0) && (cwin == 0));

    printf("사용자\n");
    print_bingo(ubingo);
    printf("컴퓨터\n");
    print_bingo(cbingo);
    print_winner(cwin * 2 + uwin);

    return 0;
}