//
// Created by Timothy Friberg Holmsten on 30/05/16.
//

#ifndef GAMESERVERTEST_SERVER_H
#define GAMESERVERTEST_SERVER_H

#include <netinet/in.h>
#include <memory.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 4

typedef struct Server{
    int sockfd, masterfd;
    int port;
    int clients[MAX_CLIENTS];
    int nr_of_clients;
    int server_id;
    int running;
}Server;

int create_server(Server data);
void init_servers(Server *servers, int len);
int calculate_best_server(Server * servers, int len);

#endif //GAMESERVERTEST_SERVER_H
