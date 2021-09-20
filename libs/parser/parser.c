#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list/list.h>
#include <cJSON/cJSON.h>
#include "parser.h"

cJSON *parse_file(const char *filename)
{
        FILE *file = fopen(filename, "r");
        if (!file)
        {
                printf("file not found\n");
                return NULL;
        }

        fseek(file, 0L, SEEK_END);
        size_t buffer_len = ftell(file);
        fseek(file, 0L, SEEK_SET);

        char *buffer = malloc(buffer_len + 1);
        if (!buffer)
        {
                printf("buffer empty\n");
                fclose(file);
                return NULL;
        }
        int rc = fread(buffer, 1, buffer_len, file);
        if (rc != buffer_len)
        {
                printf("error buffer\n");
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

int items_parse(node_t ** head, cJSON * cjson_parse)
{
        cJSON * cjson_items = NULL;
        cJSON * cjson_items_item = NULL;
        cjson_items = cJSON_GetObjectItem(cjson_parse, "items");

        if (!cjson_items)
        {
                printf("items not found\n");
                return 0;
        }

        printf("items:\n");

        cJSON_ArrayForEach(cjson_items_item, cjson_items)
        {
                item_t * item = malloc(sizeof(item_t));
                if (!item)
                {
                        printf("Malloc error\n");
                        return -1;
                }

                if (item_parse(item, cjson_items_item))
                {
                        printf("item parse fail\n");
                        return -1;
                }
                node_t * n = create_node(item);
                insert_node_first(head, n);
                free(item);
        }
        return 0;
}

int config_parse(server_t * server)
{
        cJSON* cjson_parse = parse_file("conf.json");
        if (!cjson_parse)
        {
                printf("Parse fail\n");
                return -1;
        }

        cJSON * port_json = cJSON_GetObjectItem(cjson_parse, "port");
        if (!port_json)
        {
                printf("port not found\n");
                return -1;
        }
        server->port = port_json->valueint;
        printf("port:%d\n", server->port);

        if (items_parse(&server->items, cjson_parse) != 0)
        {
                printf("items parse fail\n");
                cJSON_Delete(cjson_parse);
                return -1;
        }
        cJSON_Delete(cjson_parse);

        return 0;
}

int config_parse_client(client_t * client)
{
        cJSON* cjson_parse = parse_file("conf.json");
        if (!cjson_parse)
        {
                printf("Parse fail\n");
                return -1;
        }

        cJSON * address_json = cJSON_GetObjectItem(cjson_parse, "address");
        if (!address_json)
        {
                printf("adress not found\n");
                return -1;
        }
        client->addr = address_json->valuestring;
        printf("address:%s\n", client->addr);

        cJSON * port_json = cJSON_GetObjectItem(cjson_parse, "port");
        if (!port_json)
        {
                printf("port not found\n");
                return -1;
        }
        client->port = port_json->valueint;
        printf("port:%d\n", client->port);

        if (items_parse(&client->items, cjson_parse) != 0)
        {
                printf("items parse fail\n");
                cJSON_Delete(cjson_parse);
                return -1;
        }
        cJSON_Delete(cjson_parse);

        return 0;
}
