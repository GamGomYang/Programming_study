#include <arpa/inet.h>
#include <netdb.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int port;
    struct servent *service;

    printf("Input port number : ");
    scanf("%d", &port);

    uint16_t network_port = htons(port);

    service = getservbyport(network_port, "tcp");
    if (service) {

        printf("Name=%s, Port=%d\n", service->s_name, ntohs(network_port));
    } else {
        printf("Service not found for port=%d\n", port);
    }

    return 0;
}
