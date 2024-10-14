#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    int check = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '@') {
            printf("My precious!\n");
            check = 1;
        }
    }
    if (!check) {
        printf("Where is my precious?\n");
    }
    fclose(file);
    return 0;
}
