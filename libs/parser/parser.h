#pragma once

#include "cJSON/cJSON.h"
#include <stdint.h>
#include "server/server.h"
#include "list/list.h"

typedef struct 
{
        uint16_t id;
        char name[32];
        char desc[128];
        uint32_t price;
        uint32_t count;
} item_t;

int config_parse(server_t * server);
