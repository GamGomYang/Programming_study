#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp1 = fopen("sample.txt", "r");
    FILE *fp2 = fopen("result.txt", "w");
    char curr_ch = 0, prev_ch = 0;
    int count = 0;

    while (1) {
        int i = fread(&curr_ch, sizeof(char), 1, fp1);
        if (feof(fp1)) {
            fprintf(fp2, "%d%c", count, prev_ch);
            break;
        }
        if (prev_ch != curr_ch && prev_ch != 0) {
            fprintf(fp2, "%d%c", count, prev_ch);
            count = 1;
        } else {
            count++;
        }
        prev_ch = curr_ch;
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}