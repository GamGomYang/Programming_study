#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd;
    char ch;
    fd = open(argv[1], O_RDONLY);


    for (int i = 0; lseek(fd, i, SEEK_SET) >= 0; i += 2) {
        if (read(fd, &ch, 1) > 0) {
            write(STDOUT_FILENO, &ch, 1);
        } else {
            break;
        }
    }
    write(STDOUT_FILENO, "\n", 1);
    close(fd);
    return 0;
}
