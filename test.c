#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "libs/cJSON/cJSON.h"

cJSON *parse_file(const char *filename)
{
        cJSON *parsed = NULL;
        FILE *file = NULL;
        file = fopen(filename, "r");
        if (file == NULL)
        {
                printf("file not found");
        }

        fseek(file, 0L, SEEK_END);
        size_t buffer_len = ftell(file);
        fseek(file, 0L, SEEK_SET);

        char *buffer = malloc(buffer_len + 1);
        fread(buffer, 1, buffer_len, file);
        buffer[buffer_len] = '\0';

        fclose(file);

        parsed = cJSON_Parse(buffer);

        if(parsed == NULL)
        {
                printf("parse fail\n");
        }

        free(buffer);

        return parsed;
}

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
        char * adress;
        int port;
        //list;
        int need_stop;
        int listen_socket;

} server_t;

int item_free(item_t * item)
{
        free(item->name);
        free(item->desc);
        return 0;
}

int item_parse(item_t * item, cJSON * cjson_items_item)
{           
        item->id =  cJSON_GetObjectItem(cjson_items_item, "id") -> valueint;
        printf("id:%d\n", item->id);

        item->name = (char*)malloc(strlen(cJSON_GetObjectItem(cjson_items_item, "name") -> valuestring) * sizeof(char));
        strcpy(item->name, cJSON_GetObjectItem(cjson_items_item, "name") -> valuestring);
        printf("name:%s\n", item->name);
        
        item->desc = (char*)malloc(strlen(cJSON_GetObjectItem(cjson_items_item, "desc") -> valuestring) * sizeof(char));
        strcpy(item->desc, cJSON_GetObjectItem(cjson_items_item, "desc") -> valuestring);
        printf("desc:%s\n", item->desc);
        
        item_free(item);

        item->price = cJSON_GetObjectItem(cjson_items_item, "price") -> valueint;
        printf("price:%d\n", item->price);

        item->price = cJSON_GetObjectItem(cjson_items_item, "count") -> valueint;
        printf("count:%d\n", item->price);
        printf("\n");
        return 0;
}

int items_parse(server_t * server, cJSON * cjson_parse)
{
        cJSON * cjson_items = NULL;
        cJSON * cjson_items_item = NULL;
        cjson_items = cJSON_GetObjectItem(cjson_parse, "items");
        printf("items:\n");

        item_t * item = malloc(sizeof(* item));
        cJSON_ArrayForEach(cjson_items_item, cjson_items)
        {
                item_parse(item, cjson_items_item);
        }
        free(item);
        //Взаимодействие с лист
        return 0;       
};

int config_parse(server_t * server)
{
        cJSON* cjson_parse = NULL;
        cJSON* cjson_address = NULL;
        cJSON* cjson_port = NULL;
        cjson_parse = parse_file("conf.json");

        cjson_address = cJSON_GetObjectItem(cjson_parse, "address");
        cjson_port = cJSON_GetObjectItem(cjson_parse, "port");

        printf("address:%s\n", cjson_address->valuestring);
        printf("port:%d\n", cjson_port->valueint);
        items_parse(server, cjson_parse);
        cJSON_Delete(cjson_parse);
        
        return 0;      
};

int main(void)
{
        server_t * server;
        config_parse(server);
        return 0;
}
