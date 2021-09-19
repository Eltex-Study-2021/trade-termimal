#include "client.h"
#include <stdlib.h>

// #include "parser.h"
// #include "cli.h"
// #include "net.h"


int client_create(client_t ** client)
{
	*client = calloc(1, sizeof(client_t));

	return 0;
}

int client_init(client_t * client)
{
	//config_parse(client);
	//net_init_server(client);
	//init_cli(client);
}

int client_loop(client_t * client)
{
	while (client->need_stop)
	{
		// select()
		// do smth
	}

	return 0;
}

int client_destroy(client_t * client)
{
	free(client);
	return 0;
}

int net_init_client(client_t * client)
{	
	client_create(&client);
	//socket_bind(client->net);
	/*
	set non block
	save fd LN (listen)
	add fd_set in select
	*/

	return 0;
}
