#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

cJSON *parse_file(const char *filename)
{
        FILE *file = fopen(filename, "r");
        if (!file)
        {
                printf("file not found");
                return NULL;
        }

        fseek(file, 0L, SEEK_END);
        size_t buffer_len = ftell(file);
        fseek(file, 0L, SEEK_SET);

        char *buffer = malloc(buffer_len + 1);
        if (!buffer) 
        {
                printf("buffer empty");
                fclose(file);
                return NULL;
        }
        int rc = fread(buffer, 1, buffer_len, file);
        if (rc != buffer_len)
        {
                printf("error buffer");
                return NULL;
        }
        buffer[buffer_len] = '\0';
        fclose(file);

        cJSON *parsed = cJSON_Parse(buffer);
        if (!parsed)
        {
                printf("parse fail\n");
                free(buffer);
                return NULL;
        }
        free(buffer);
        return parsed;
}

int item_parse(item_t * item, cJSON * cjson_items_item)
{           
        item->id = cJSON_GetObjectItem(cjson_items_item, "id")->valueint;
        printf("id:%d\n", item->id);

        strncpy(item->name, cJSON_GetObjectItem(cjson_items_item, "name")->valuestring, 32);
        printf("name:%s\n", item->name);
        
        strncpy(item->desc, cJSON_GetObjectItem(cjson_items_item, "desc")->valuestring, 128);
        printf("desc:%s\n", item->desc);
        
        item->price = cJSON_GetObjectItem(cjson_items_item, "price")->valueint;
        printf("price:%d\n", item->price);

        item->count = cJSON_GetObjectItem(cjson_items_item, "count")->valueint;
        printf("count:%d\n", item->count);
        printf("\n");
        return 0;
}

int items_parse(server_t * server, cJSON * cjson_parse)
{
        cJSON * cjson_items = NULL;
        cJSON * cjson_items_item = NULL;
        cjson_items = cJSON_GetObjectItem(cjson_parse, "items");
        printf("items:\n");

        cJSON_ArrayForEach(cjson_items_item, cjson_items)
        {
                item_t * item = malloc(sizeof(item_t));
                if (!item)
                {
                        printf("Malloc error");
                        return -1;
                }

                if (item_parse(item, cjson_items_item))
                {
                        printf("item parse fail");
                        return -1;
                }
                node_t * n = create_node(item);
                if (!insert_node_first(&server->items, n)) 
                {
                        printf("node fail");
                        return -1;
                }
                free(item);
        }
        return 0;       
}

int config_parse(server_t * server)
{
        cJSON* cjson_parse = parse_file("conf.json");
        if (!cjson_parse)
        {
                printf("Parse fail");
                return -1;
        }

        cJSON * address_json = cJSON_GetObjectItem(cjson_parse, "address");
        if (!address_json)
        {
                printf("adress not found");
                return -1;
        }
        server->add = address_json->valuestring;
        printf("address:%s\n", server->add);
        
        cJSON * port_json = cJSON_GetObjectItem(cjson_parse, "port");
        if (!port_json)
        {
                printf("port not found");
                return -1;
        }
        server->port = port_json->valueint;
        printf("port:%d\n", server->port);
        
        if (items_parse(server, cjson_parse) != 0)
        {
                printf("items parse fail");
                cJSON_Delete(cjson_parse);
                return -1;
        }
        cJSON_Delete(cjson_parse);
        
        return 0;      
}
