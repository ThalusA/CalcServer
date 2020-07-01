#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

int main()
{
    struct sockaddr_in address;
    char *data = NULL;
    int sockfd = init_socket();

    bind_socket(sockfd, &address);
    serve_socket(sockfd);
    while (1) {
        printf("Waiting incoming data...\n");
        data = receive_data(sockfd, &address);
        printf("Received data : '%s'\n", data);
        free(data);
    }
    return (0);
}