#pragma once

#include "libs/cJSON/cJSON.h"
#include <stdint.h>

typedef struct 
{
        uint16_t id;
        char * name;
        char * desc;
        uint32_t price;
        uint32_t count;
} item_t;

typedef struct
{
        int port;
} server_t;     

cJSON *parse_file(const char *filename);
int item_free(item_t * item);
int item_parse(item_t * item, cJSON * cjson_items_item);
int items_parse(server_t * server, cJSON * cjson_parse);
int config_parse(server_t * server);
