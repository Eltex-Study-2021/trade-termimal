#pragma once

#include "libs/cJSON/cJSON.h"
#include <stdint.h>
#include "server/list.h"

typedef struct 
{
        uint16_t id;
        char name[32];
        char desc[128];
        //char * name;
        //char * desc;
        uint32_t price;
        uint32_t count;
} item_t;

typedef struct
{
        int port;
        node_t * items;
} server_t;     

cJSON *parse_file(const char *filename);
int item_parse(item_t * item, cJSON * cjson_items_item);
int items_parse(server_t * server, cJSON * cjson_parse);
int config_parse(server_t * server);
