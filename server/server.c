#include "server.h"
#include <stdlib.h>

// #include "parser.h"
// #include "cli.h"
// #include "net.h"

int server_create(server_t ** server)
{
    *server = calloc(1, sizeof(server_t));

    return 0;
}

int server_init(server_t * server)
{
    // config_parse(server)
    // init_net(server)
    // init_cli(server)
    return 0;
}

int server_loop(server_t * server)
{
    while (server->need_stop)
    {
    // select()

    // do smth
    }

    return 0;
}

int server_destroy(server_t * server)
{
    free(server);
    return 0;
}

int net_init_server(servet_t * server)
{
	server->net->fd = server_create();
	socket_bind(server->net);
	/*
	set non block
    save fd LN (listen)
    add fd_set in select
	*/
}
