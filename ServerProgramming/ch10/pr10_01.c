#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("no instruction");
        return 1;
    }

    char command[100] = "man ";
    strcat(command, argv[1]);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    char buffer[256];
    int line_count = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL && line_count < 4) {
        printf("%s", buffer);
        line_count++;
    }

    pclose(fp);
    return 0;
}
