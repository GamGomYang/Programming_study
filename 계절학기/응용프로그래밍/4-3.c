#include <ctype.h>
#include <stdio.h>

void main(void) {
    char buffer[256], *pch;
    int alphabet[26] = {0};

    FILE *fp = fopen("malloc.txt", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }

    while (fgets(buffer, 255, fp) != NULL) {
        pch = buffer;
        while (*pch != '\0') {
            if (isupper(*pch))
                alphabet[*pch - 'A']++;
            else if (islower(*pch))
                alphabet[*pch - 'a']++;
            pch++;
        }
    }

    fclose(fp);

    for (int n = 0; n < 26; n++) {
        printf("%c : %d\n", 65 + n, alphabet[n]);
    }
}