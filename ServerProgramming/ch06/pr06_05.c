#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }

    char ch;
    int position = 0;

  
    while (fread(&ch, 1, 1, file) == 1) {
        printf("%c", ch); 
        if (fseek(file, 1, SEEK_CUR) != 0) {
            break; 
        }
    }

    printf("\n");  
    fclose(file);  
    return 0;
}
