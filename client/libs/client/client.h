#pragma once
<<<<<<< HEAD

#include <net/net.h>
#include <list/list.h>
#include <parser/parser.h>
#include <cli/cli.h>
#include <cJSON/cJSON.h>

#include <sys/time.h>
#include <sys/select.h>
#include <stdint.h>
/**/
=======
#include "../libs/net/net.h"
#include "../libs/list/list.h"
//#include "../libs/cli/cli.h"
#include <sys/time.h>
#include <sys/select.h>
#include <stdint.h>

>>>>>>> 6e36da8fb584d58eaa743e5c622a9fd4ea6c4932
typedef struct
{
        char * addr;
        uint16_t port;
        int need_stop;
        int listen_socket;
        node_t * items;
        fd_set inputs;
        node_t * node;
        net_t net;
} client_t;

int client_create(client_t ** client);
int client_init(client_t * client);
int client_loop(client_t * client);
int client_destroy(client_t * client);
int net_init_client(client_t * client);
