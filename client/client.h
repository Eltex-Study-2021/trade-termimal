#pragma once
typedef struct
{
        // list items
        char * addr;
        uint16_t port;
        int need_stop;
        int listen_socket;
        node_t * items;
        fd_set inputs;
        node_t node;
        net_t net;
} client_t;
