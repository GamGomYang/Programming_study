#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd = open("table.txt", O_RDONLY);
    char buffer[256];
    ssize_t nread;
    int id, score1, score2, score3;
    char *number;

    while ((nread = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[nread] = '\0';  


        number = strtok(buffer, " \n");
        while (number != NULL) {
            id = atoi(number);  
            number = strtok(NULL, " \n");
            score1 = atoi(number);  
            number = strtok(NULL, " \n");
            score2 = atoi(number);  
            number = strtok(NULL, " \n");
            score3 = atoi(number);  

            int average = (score1 + score2 + score3) / 3;
            printf("%d %d\n", id, average);


            number = strtok(NULL, " \n");
        }
    }

    close(fd);
    return 0;
}
