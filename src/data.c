#include <stddef.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "define.h"

char *buffer_concat(char *buffer, char tmp_buffer[BUFFER_SIZE], int tmp_buffer_size)
{
    char *new_buffer;
    int buffer_size = buffer == NULL ? 0 : strlen(buffer);
    int total_size = buffer_size + tmp_buffer_size;
    int cursor = 0;

    if (tmp_buffer_size == 0)
        return (buffer);
    new_buffer = malloc(sizeof(char) * (total_size + 1));
    new_buffer[total_size] = '\0';
    for (int i = 0; i < buffer_size; i++, cursor++)
        new_buffer[cursor] = buffer[i];
    if (buffer != NULL)
        free(buffer);
    for (int i = 0; i < tmp_buffer_size; i++, cursor++)
        new_buffer[cursor] = tmp_buffer[i];
    return (new_buffer);
}

char *receive_data(int sockfd, struct sockaddr_in *address)
{
    char *result_buffer;
    char buffer[BUFFER_SIZE] = {0};
    static int addrlen = sizeof(address);
    int temp_socket = accept(sockfd, (struct sockaddr *) address, (socklen_t *) &addrlen);
    int size;

    if (temp_socket == -1) {
        perror("Temporary socket accept failed.");
        exit(EXIT_FAILURE);
    }
    do {
        size = read(temp_socket, buffer, BUFFER_SIZE);
        result_buffer = buffer_concat(result_buffer, buffer, size);
    } while (size == BUFFER_SIZE);
    return (result_buffer);
}