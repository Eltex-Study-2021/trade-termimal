#pragma once
#include "../cJSON/cJSON.h"
#include "../list/list.h"
#include "../net/net.h"
#include <stdint.h>

/*
typedef struct 
{
        uint16_t id;
        char name[32];
        char desc[128];
        uint32_t price;
        uint32_t count;
} item_t;
*/
/*
typedef struct
{
        char * add;
        uint16_t port;
        struct node * items;
        // ...
        // smth
        //net_t net;
} server_t;
*/

typedef struct
{
	// fd stdin
	char * add;
	uint16_t port;
	fd_set inputs;
	int need_stop;
	int listen_socket;
	int high;
	node_t * node;
	net_t net;
} server_t;

int config_parse(server_t * server);
