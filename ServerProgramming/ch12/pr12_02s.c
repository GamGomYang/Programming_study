#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define PORTNUM 9001

char msg[5][50] = {"Hello!", "Good!", "Are you ok?", "Hahahahah", "Not bad."};

int main() {
    char buf[256];
    struct sockaddr_in sin, cli;
    struct in_addr in;
    int sd, ns, ind, clientlen = sizeof(cli);

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = INADDR_ANY;

    if (bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("bind");
        exit(1);
    }
    if (listen(sd, 5)) {
        perror("listen");
        exit(1);
    }

    printf("* Wait Client!\n");
    if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
        perror("accept");
        exit(1);
    }

    printf("* Client connected!!\n");
    while (1) {
        if (recv(ns, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            exit(1);
        }
        printf("** Client message : %s\n", buf);

        if (buf[0] != 'q') {
            srand((unsigned int)time(NULL));
            ind = (int)rand() % 5;
            sprintf(buf, "%s", msg[ind]);
        } else
            sprintf(buf, "Bye!!");
        if (send(ns, buf, strlen(buf) + 1, 0) == -1) {
            perror("send");
            exit(1);
        }
        if (!strcmp(buf, "Bye!!"))
            break;
    }
    close(ns);
    close(sd);
    printf("** End of Communication!!\n");
}
