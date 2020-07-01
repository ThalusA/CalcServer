#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

int init_socket(void);

void bind_socket(int sockfd, struct sockaddr_in *address);

void serve_socket(int sockfd);

char *receive_data(int sockfd, struct sockaddr_in *address);

#endif /* PROTOTYPES_H_ */