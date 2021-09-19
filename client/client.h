#include "../libs/net/net.h"
#include "../libs/list/list.h"
#include <sys/time.h>
#include <sys/select.h>
#include <sys/ioctl.h>

typedef struct
{
	// list items
		char * addr;
		uint16_t port;
		int need_stop;
		int listen_socket;
	node_t * items;
	fd_set inputs;
		node_t node;
	net_t net;
} client_t;

int client_create(client_t ** client);
int server_init(client_t * client);
int server_loop(client_t * client);
int server_destroy(client_t * client);
int net_init_server(client_t * client);
