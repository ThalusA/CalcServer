#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include "define.h"

int init_socket(void)
{
    int opt = 1;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == 0) {
        perror("Socket creation failed.");
        exit (EXIT_FAILURE);
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set socket options failed.");
        exit(EXIT_FAILURE);
    }
    return (sockfd);
}

void bind_socket(int sockfd, struct sockaddr_in *address)
{
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *) address, sizeof(*address)) == -1) {
        perror("Socket binding failed.");
        exit(EXIT_FAILURE);
    }
}

void serve_socket(int sockfd)
{
    if (listen(sockfd, MAX_CLIENT) < 0) {
        perror("Socket listening failed.");
        exit(EXIT_FAILURE);
    }
}