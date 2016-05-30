//
// Created by Timothy Friberg Holmsten on 29/05/16.
//

#include <sys/socket.h>
#include <memory.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include "headers/masterserver.h"


void master_server() {

    int sockfd, clientfd;
    struct sockaddr_in self;
    struct sockaddr_storage client_addr;
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(self.sin_zero, NULL, sizeof(self.sin_zero));
    self.sin_family = AF_INET;
    self.sin_port = htons(PORT);
    self.sin_addr.s_addr = inet_addr("127.0.0.1"); //INADDR_ANYf

    bind(sockfd, (struct sockaddr*)&self, sizeof(self));

    listen(sockfd, 5);

    int running = 1;

    while (running)
    {
        addr_size = sizeof(client_addr);

        clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &addr_size);

        if (clientfd != -1)
        {
            printf("Client connected!\n");
        }

        sleep(1);

        close(clientfd);
    }
}
