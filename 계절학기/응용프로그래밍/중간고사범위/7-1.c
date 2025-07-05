#include <stdio.h>

int main(void) {
    FILE *fp = NULL;
    FILE *fp2 = NULL;
    char buffer[100];

    fp = fopen("sample.txt", "r");
    fp2 = fopen("csample.txt", "w");

    if (fp == NULL) {
        perror("file open error");
        return 1;
    } else {
        printf("파일 읽기 성공\n");
    }

    while (fgets(buffer, 100, fp)) {
        fputs(buffer, fp2);
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
