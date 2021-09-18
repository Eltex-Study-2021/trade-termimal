#include "net/net.h"

typedef struct
{
    // list items
    // fd stdin
    int need_stop;
    int listen_socket;
	net_t net;
#pragma once 

#include <stdint.h>

typedef struct
{
        char * add;
        uint16_t port;
        struct node * items;
        // list items
        // sockets
        // fd stdin
        int need_stop;
        int listen_socket;
} server_t;

int server_create(server_t ** server);
int server_init(server_t * server);
int server_loop(server_t * server);
int server_destroy(server_t * server);
