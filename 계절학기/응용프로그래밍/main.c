#include "bingo.h"
#include <stdio.h>

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