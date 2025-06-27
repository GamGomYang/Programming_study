#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define MAXLENGTH 100

char *pstrarray[MAXWORD];
int nword;

void get_words();
void sort_string();
void print_words();
void deallocate();

int main() {
    get_words();
    sort_string();
    print_words();
    deallocate();
    return 0;
}

void get_words() {
    char buffer[MAXLENGTH];
    int size;
    nword = 0;
    printf("단어를 입력하세요. 최대 단어 수는 100 개 입니다.\n");
    printf("입력을 중지하려면 엔터를 입력하세요.\n\n");

    while (nword < MAXWORD) {
        printf("%d. 단어 입력: ", nword + 1);
        fgets(buffer, MAXLENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "") == 0)
            break;
        else {
            size = strlen(buffer) + 1;
            pstrarray[nword] = (char *)malloc(size);
            strcpy(pstrarray[nword], buffer);
            nword++;
        }
    }
}

void sort_string() {
    int n, m, minindex;
    char *temp;

    for (n = 0; n < nword - 1; n++) {
        minindex = n;
        for (m = n; m < nword; m++) {
            if (strcmp(pstrarray[minindex], pstrarray[m]) > 0)
                minindex = m;
        }
        temp = pstrarray[minindex];
        pstrarray[minindex] = pstrarray[n];
        pstrarray[n] = temp;
    }
}

void print_words() {
    int n;
    printf("\n정렬 후 출력: 단어 수=%d\n", nword);
    for (n = 0; n < nword; n++)
        puts(pstrarray[n]);
}

void deallocate() {
    for (int n = 0; n < nword; n++) {
        if (pstrarray[n] != NULL)
            free(pstrarray[n]);
    }
}
