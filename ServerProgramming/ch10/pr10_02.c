#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    pid_t pid;
    char buffer[128];

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();
    switch (pid) {
    case -1:
        perror("fork");
        return 1;
    case 0:  
        close(pipe_fd[0]);  
        char message[] = "Hello from child!";
        write(pipe_fd[1], message, strlen(message) + 1);
        close(pipe_fd[1]); 
        break;
    default:  
        close(pipe_fd[1]);  
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Received message: %s\n", buffer);
        close(pipe_fd[0]);  
        break;
    }

    return 0;
}
