#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);

    dup2(fd, STDOUT_FILENO);
    close(fd);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        printf("%s", buffer); 
    }

    return 0;
}
