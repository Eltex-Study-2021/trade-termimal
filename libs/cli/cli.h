#pragma once

#include <server/server.h>

/*The width of the cells is the 
 * ID, NAME, DESCRIPTION, QUANTITY and PRICE*/
#define CLI_W_ID    4
#define CLI_W_NAME  22
#define CLI_W_DESC  17
#define CLI_W_QUA   10
#define CLI_W_PRICE 9

item_t * item_search_id(node_t * head, int id);
int loop_cli(server_t * server);
int init_cli(server_t * server);

int sell_handler_cli(server_t * server);
int show_handler_cli(server_t * server);
int add_handler_cli(server_t * server);
int cli_handler(server_t * server);
