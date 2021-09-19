#pragma once

#include <server/server.h>

/*typedef struct 
{
        uint16_t id;
        char name[32];
        char desc[128];
        uint32_t price;
        uint32_t count;
} item_t;*/

int config_parse(server_t * server);
