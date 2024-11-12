#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define CLIENT_TO_SERVER_FIFO "./client_to_server_fifo"
#define SERVER_TO_CLIENT_FIFO "./server_to_client_fifo"

int main() {
    int read_fd, write_fd;
    char buffer[1024];

    // FIFO 파일 생성 (클라이언트 -> 서버, 서버 -> 클라이언트)
    if (mkfifo(CLIENT_TO_SERVER_FIFO, 0666) == -1) {
        perror("mkfifo client_to_server_fifo");
        exit(1);
    }

    if (mkfifo(SERVER_TO_CLIENT_FIFO, 0666) == -1) {
        perror("mkfifo server_to_client_fifo");
        exit(1);
    }

    printf("Server is ready for communication...\n");

    // 클라이언트 -> 서버 FIFO 열기 (읽기 전용)
     if ((read_fd = open(CLIENT_TO_SERVER_FIFO, O_RDONLY)) == -1) {
        perror("open client_to_server_fifo");
        exit(1);
    }

    // 서버 -> 클라이언트 FIFO 열기 (쓰기 전용)
   if ((write_fd = open(SERVER_TO_CLIENT_FIFO, O_WRONLY)) == -1) {
        perror("open server_to_client_fifo");
        exit(1);
    }

    while (1) {
        // 클라이언트로부터 메시지 읽기
        ssize_t bytes_read = read(read_fd, buffer, sizeof(buffer) - 1);
        if (bytes_read == -1) {
            perror("read from client_to_server_fifo");
            exit(1);
        }
        if (bytes_read == 0) {
            // 클라이언트가 종료한 경우
            printf("Client has disconnected.\n");
            break;
        }

        buffer[bytes_read] = '\0';
        printf("Received message from client: %s\n", buffer);

        // 서버의 응답을 클라이언트로 전송
        printf("Enter message to client: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (write(write_fd, buffer, strlen(buffer) + 1) == -1)
         {
            perror("write to server_to_client_fifo");
            exit(1);
        }
    }

    // FIFO 파일 닫기
    close(read_fd);
    close(write_fd);

    // FIFO 파일 삭제
    unlink(CLIENT_TO_SERVER_FIFO);
    unlink(SERVER_TO_CLIENT_FIFO);

    return 0;
}