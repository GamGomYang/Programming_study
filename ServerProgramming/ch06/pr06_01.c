#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char buffer[1024];
    int source_fd, dest_fd;
    ssize_t nread;

   
    source_fd = open(argv[1], O_RDONLY);

    dest_fd = open(argv[2], O_CREAT | O_WRONLY, 0644);

    while ((nread = read(source_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, nread);
    }

    close(source_fd);
    close(dest_fd);
    return 0;
}
