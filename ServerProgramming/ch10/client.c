#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define CLIENT_TO_SERVER_FIFO "./client_to_server_fifo"
#define SERVER_TO_CLIENT_FIFO "./server_to_client_fifo"

int main() {
    int read_fd, write_fd;
    char buffer[1024];

    // FIFO 파일이 존재하는지 확인
    if (access(CLIENT_TO_SERVER_FIFO, F_OK) == -1) {
        perror("client_to_server_fifo not found");
        exit(1);
    }

    if (access(SERVER_TO_CLIENT_FIFO, F_OK) == -1) {
        perror("server_to_client_fifo not found");
        exit(1);
    }

    printf("Client is ready for communication...\n");

    // 클라이언트 -> 서버 FIFO 열기 (쓰기 전용)
    if ((write_fd = open(CLIENT_TO_SERVER_FIFO, O_WRONLY)) == -1) {
        perror("open client_to_server_fifo");
        exit(1);
    }

    // 서버 -> 클라이언트 FIFO 열기 (읽기 전용)
    if ((read_fd = open(SERVER_TO_CLIENT_FIFO, O_RDONLY)) == -1) {
        perror("open server_to_client_fifo");
        exit(1);
    }

    while (1) {
        // 클라이언트로부터 서버로 메시지 보내기
        printf("Enter message to server: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // 줄바꿈 문자 제거

        if (write(write_fd, buffer, strlen(buffer) + 1) == -1) {
            perror("write to client_to_server_fifo");
            exit(1);
        }

        // 서버의 응답 받기
        ssize_t bytes_read = read(read_fd, buffer, sizeof(buffer) - 1);
        if (bytes_read == -1) {
            perror("read from server_to_client_fifo");
            exit(1);
        }
        if (bytes_read == 0) {
            // 서버가 종료한 경우
            printf("Server has disconnected.\n");
            break;
        }

        buffer[bytes_read] = '\0';  // Null-terminate the string
        printf("Received from server: %s\n", buffer);
    }

    // FIFO 파일 닫기
    close(read_fd);
    close(write_fd);

    return 0;
}