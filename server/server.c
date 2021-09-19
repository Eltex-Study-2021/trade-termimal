#include "server.h"
#include <stdlib.h>

int server_create(server_t ** server)
{
	*server = calloc(1, sizeof(server_t));

	return 0;
}

int server_init(server_t * server)
{
	//config_parse(server);
	net_init_server(server);
	//init_cli(server);
}

int server_loop(server_t * server)
{
	/*struct timeval tv;
	tv.tv_sec = 10; 
	tv.tv_usec = 0;*/

	socket_listen(&server->net);/*save fd (listen) */
	server->listen_socket = server->net.fd;

	server->node = create_node(&server->listen_socket);
	node_t * HEAD = NULL;
	insert_node_first(&HEAD, server->node);
	print_list(HEAD, 'i');

	int ready = 0;
	server->need_stop = 1;

	while (server->need_stop)
	{
		FD_ZERO(&server->inputs);/*init fd_set*/
		FD_SET(*(int *)server->node->data, &server->inputs);
		FD_SET(STDIN_FILENO, &server->inputs);

		for (node_t * n = HEAD; n; n = n->next)
		{
			int socket = *(int *)n->data;
			FD_SET(socket, &server->inputs);
			if (socket > server->high)
			{
				server->high = socket;
			}
		}
		//select
		ready = select(server->high + 1, &server->inputs, NULL, NULL, NULL);
		{
			if (ready == -1)
			{
				perror("select");
				return -1;
			}

			if (FD_ISSET(*(int *)server->node->data, &server->inputs))
			{
				socket_accept(&server->net);
				printf("Accept success\n");
			}

			for (node_t * n = HEAD; n; n = n->next)
			{
				int socket = *(int *)n->data;
				if (FD_ISSET(socket, &server->inputs))
				{
					//socket_recv(&server->net, &server->item);
					printf("SOCKET RECIVE\n");
				}
			}

			if(FD_ISSET(STDIN_FILENO, &server->inputs))
			{
				printf("CLI HANDLER\n");
				//cli_handler(server);
			}
		}
	}

	return 0;
}

int server_destroy(server_t * server)
{
	free(server);
	return 0;
}

int net_init_server(server_t * server)
{
	socket_create(&server->net);
	socket_bind(&server->net);
	socket_set_non_block(&server->net);

	return 0;
}
