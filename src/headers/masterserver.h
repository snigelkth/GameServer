//
// Created by Timothy Friberg Holmsten on 29/05/16.
//

#ifndef GAMESERVER_MASTERSERVER_H
#define GAMESERVER_MASTERSERVER_H

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include "structs.h"

void sigchld_handler(int s);
void init_child_handler();

void master_server();
void update_server_list(Server *server_list, int len);

void create_read_thread(Server *server_list, int len);
void *thread_read_servers(void *s);

#endif //GAMESERVER_MASTERSERVER_H
