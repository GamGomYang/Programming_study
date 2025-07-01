#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 1000

struct WORDCOUNT {
    char *str;
    int count;
};

struct WORDCOUNT *words;
int nwords;

void initialize() {
    words = (struct WORDCOUNT *)malloc(sizeof(struct WORDCOUNT) * MAXWORD);
    memset(words, 0, sizeof(struct WORDCOUNT) * MAXWORD);
    nwords = 0;
}

void deallocate() {
    for (int n = 0; n < nwords; n++) {
        if (words[n].str != NULL) {
            free(words[n].str);
        }
    }
    free(words);
}

void convert_lower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int linear_search(char *key, int *found) {
    *found = 0;
    for (int n = 0; n < nwords; n++) {
        int compare = strcmp(key, words[n].str);
        if (compare == 0) {
            *found = 1;
            return n;
        }
        if (compare < 0) {
            break;
        }
    }
    return nwords;
}

void move_downward(int index) {
    if (nwords < MAXWORD - 1) {
        for (int n = nwords; n >= index; n--) {
            words[n + 1] = words[n];
        }
    }
}

void insert_data(int index, char *str) {
    if (nwords < MAXWORD - 1) {
        int size = strlen(str) + 1;
        words[index].str = (char *)malloc(size);
        strcpy(words[index].str, str);
        words[index].count = 1;
        nwords++;
    }
}

void read_file(const char *filename) {
    char buffer[256];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char *token = strtok(buffer, " ,.!?\t\n");
        while (token != NULL) {
            convert_lower(token);
            int found, index = linear_search(token, &found);
            if (found) {
                words[index].count++;
            } else {
                move_downward(index);
                insert_data(index, token);
            }
            token = strtok(NULL, " ,.!?\t\n");
        }
    }
    fclose(fp);
}

void print_words() {
    for (int n = 0; n < nwords; n++) {
        printf("%3d. %-18s: %d\n", n + 1, words[n].str, words[n].count);
    }
}

int main() {
    initialize();
    read_file("programming.txt");
    print_words();
    deallocate();
    return 0;
}