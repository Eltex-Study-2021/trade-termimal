#pragma once

#include "libs/cJSON/cJSON.h"
#include <stdint.h>
#include "server/list.h"

typedef struct 
{
        uint16_t id;
        char name[32];
        char desc[128];
        uint32_t price;
        uint32_t count;
} item_t;

typedef struct
{
        char * add;
        uint16_t port;
        struct node * items;
        // ...
        // smth
        //net_t net;
} server_t;

int config_parse(server_t * server);
