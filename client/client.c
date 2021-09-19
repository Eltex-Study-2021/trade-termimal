#include "client.h"
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

int client_create(client_t ** client)
{
    *client = calloc(1, sizeof(client_t));

    return 0;
}

int client_init(client_t * client)
{
    //config_parse(client);
    net_init_client(client);
    //loop_cli(client);
    return 0;
}


int client_loop(client_t * client)
{
	item_t item;
	socket_listen(&client->net);
	client->listen_socket = client->net.fd;

	client->node = create_node(&client->listen_socket);
	node_t * HEAD = NULL;
	insert_node_first(&HEAD, client->node);

	int ready = 0;
	client->need_stop = 1;

	while (client->need_stop)
	{
		FD_ZERO(&client->inputs);
		FD_SET(*(int *)client->node->data, &client->inputs);
		FD_SET(STDIN_FILENO, &client->inputs);

		for (node_t * n = HEAD; n; n = n->next)
		{
			int socket = *(int *)n->data;
			FD_SET(socket, &client->inputs);
			if (socket > client->high)
			{
				client->high = socket;
			}
		}
		ready = select(client->high + 1, &client->inputs, NULL, NULL, NULL);
		{
			if (ready == -1)
			{
				perror("select");
				return -1;
			}

			if (FD_ISSET(*(int *)client->node->data, &client->inputs))
			{
				socket_accept(&client->net);
                                printf("Accept success\n");
			}

			for (node_t * n = HEAD; n; n = n->next)
			{
				int socket = *(int *)n->data;
				if (FD_ISSET(socket, &client->inputs))
				{
					socket_recv(&client->net, &item);
                                        net_print_item(&item);
					printf("SOCKET RECIVE\n");
                                }
			}
			if(FD_ISSET(STDIN_FILENO, &client->inputs))
			{
				//cli_handler(client);
			}
		}
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
        socket_create(&client->net);
        init_client_sock(&client->net);
        socket_connect(&client->net);

        return 0;
}
