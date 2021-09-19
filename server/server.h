#pragma once
#include <net/net.h>
#include <list/list.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/ioctl.h>

typedef struct
{
        char * addr;
        uint16_t port;
        struct node * items;
        // fd stdin
        fd_set inputs;
        int need_stop;
        int listen_socket;
        node_t node;
        net_t net;
} server_t;

int server_create(server_t ** server);
int server_init(server_t * server);
int server_loop(server_t * server);
int server_destroy(server_t * server);
int net_init_server(server_t * server);
