#pragma once

//#include <cJSON/cJSON.h>
//#include <stdint.h>
//#include <list/list.h>
#include <server/server.h>
#include <client/client.h>

/*typedef struct 
{
        uint16_t id;
        char name[32];
        char desc[128];
        uint32_t price;
        uint32_t count;
} item_t;*/
/*
typedef struct
{
        char * add;
        uint16_t port;
        struct node * items;
        // ...
        // smth
        //net_t net;
} server_t;*/

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

int config_parse(server_t * server);
int config_parse_client(client_t * client);
