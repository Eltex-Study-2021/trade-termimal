#include "libs/net"

typedef struct
{
    // list items
    // fd stdin
    int need_stop;
    int listen_socket;
	net_t net;
} server_t;

int server_create(server_t ** server);
int server_init(server_t * server);
int server_loop(server_t * server);
int server_destroy(server_t * server);
