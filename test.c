#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "libs/cJSON/cJSON.h"

cJSON *read_json( const char *filename )
{
    FILE *f = NULL;
    f = fopen(filename, "r");

    if (f == NULL)
    {
        printf("file don't open");
        return NULL;
    }
    
    fseek(f, 0L, SEEK_END);
    size_t buffer_len = ftell(f);
    fseek(f, 0L, SEEK_SET);

    char *buffer = malloc(buffer_len + 1);
    fread(buffer, 1, buffer_len, f);
    buffer[buffer_len] = '\0';
   
    fclose(f);

    cJSON *root = NULL;
    root = cJSON_Parse(buffer);

    if(root == NULL)
    {
        printf("parse fail\n");
    }

    free(buffer);
   
    return root;
}

struct item_t
{
    uint16_t id;
    char * name;
    char * desc;
    uint32_t price;
    uint32_t count;
};

int item_free(struct item_t * items)
{
    free(items->name);
    free(items->desc);
    return 0;
}


int main(void)
{

    struct item_t items[6]; 
    

    cJSON* cjson_test = NULL;
    cJSON* cjson_address = NULL;
    cJSON* cjson_port = NULL;
    cJSON* cjson_items = NULL;
    
    cJSON* cjson_items_id = NULL;
    cJSON* cjson_items_id_item = NULL;
    cJSON* cjson_items_name = NULL;
    cJSON* cjson_items_desc = NULL;
    cJSON* cjson_items_price = NULL;
    cJSON* cjson_items_count = NULL;
    int    items_array_size = 0, i = 0;
    cJSON* cjson_items_item = NULL;

   
    // * Анализировать все данные JSO * /
    cjson_test = read_json("conf.json");
    //cjson_test = cJSON_Parse(load_json("conf.json"));
   
    cjson_address = cJSON_GetObjectItem(cjson_test, "address");
    cjson_port = cJSON_GetObjectItem(cjson_test, "port");

     
    printf("address:%s\n", cjson_address->valuestring);
    printf("port:%d\n", cjson_port->valueint);

   
    cjson_items = cJSON_GetObjectItem(cjson_test, "items");
    items_array_size = cJSON_GetArraySize(cjson_items);
    printf("items:\n");
    for(i = 0; i < items_array_size; i++) 
    {
        cjson_items_item = cJSON_GetArrayItem(cjson_items, i);
        cjson_items_id = cJSON_GetObjectItem(cjson_items_item, "id");
        cjson_items_name = cJSON_GetObjectItem(cjson_items_item, "name");
        cjson_items_desc = cJSON_GetObjectItem(cjson_items_item, "desc");
        cjson_items_price = cJSON_GetObjectItem(cjson_items_item, "price");
        cjson_items_count = cJSON_GetObjectItem(cjson_items_item, "count");
        
        items[i].id = cjson_items_id -> valueint;
        printf("id:%d\n", items[i].id);
       
        items[i].name = (char*)malloc(strlen(cjson_items_name -> valuestring) * sizeof(char));
        strcpy(items[i].name, cjson_items_name -> valuestring);
        printf("name:%s\n", items[i].name);
        
        items[i].desc = (char*)malloc(strlen(cjson_items_desc -> valuestring) * sizeof(char));
        strcpy(items[i].desc, cjson_items_name -> valuestring);
        printf("desc:%s\n", items[i].desc);
        
        item_free(&items[i]);

        items[i].price = cjson_items_price -> valueint;
        printf("price:%d\n", items[i].price);
        
        items[i].price = cjson_items_count -> valueint;
        printf("count:%d\n", items[i].price);
        printf("\n");
    }
    cJSON_Delete(cjson_test);
    return 0;
}

