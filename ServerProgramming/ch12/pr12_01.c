#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int port;
    printf("Enter port number: ");
    scanf("%d", &port);

    struct servent *service = getservbyport(htons(port), "tcp");
    if (service) {
        printf("Service name: %s, port= %d\n", service->s_name, port);

    } else {
        printf("No service found for port %d\n", port);
    }

        return 0;
}
