#include <sys/select.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cli.h"
#include <net/net.h>
#include <parser/parser.h>

item_t * item_search_id(node_t * head, int id)
{
	for(node_t * n = head; n; n = n->next)
        {
                item_t * i = n->data;
		if(i->id == id) return i;
        }
	return NULL;
}

int init_cli(server_t * server)
{
	FD_ZERO(&server->inputs);
	FD_SET(0, &server->inputs);
}

int show_handler_cli(server_t * server)
{
	puts("____________________________________________________________________");
	puts("|    |                      |                 |          |         |");
	puts("| ID |         Name         |   Description   | Quantity |  Price  |");
	puts("|____|______________________|_________________|__________|_________|");
	

        for(node_t * n = server->items; n; n = n->next)
	{
            item_t * i = n->data;
	    printf("|%*d|%*s|%*s|%*d|%*d|\n", CLI_W_ID, i->id, CLI_W_NAME, i->name, CLI_W_DESC, i->desc, CLI_W_QUA, i->count, CLI_W_PRICE, i->price);
	    puts("|____|______________________|_________________|__________|_________|");
	}
	return 0;
}

int add_handler_cli(server_t * server)
{
	int id;
	int count;
	int price;
	char name[32];
	char desc[64];

	puts("\nEnter product ID: ");
	scanf("%d", &id);

	item_t * i = item_search_id(server->items, id);
	if(!i)
	{
		fprintf(stderr, "Item by ID %d not found\n", id);
		i = calloc(1, sizeof(item_t));
		if(!i)
		{
			fprintf(stderr, "calloc failed\n");
			return -1;
		}

		node_t * n = create_node(i);
		if(insert_node_first(&server->items, n))
		{
			fprintf(stderr, "insert node first failed\n");
			free(i);
			i = NULL;
			return -1;
		}
		i->id = id;
		puts("\nEnter product count: ");
		scanf("%d", &count);
		puts("\nEnter product price: ");
		scanf("%d", &price);
		puts("\nEnter product name: ");
		scanf("%s", name);
		puts("\nEnter product description: ");
		gets(desc);
	
		i->count = count;
		i->price = price;
		strlcpy(i->name, name, sizeof(i->name));
		strlcpy(i->desc, desc, sizeof(i->desc));

		/*sending*/

		return 0;
	}

	/*sending*/

	i->count += count;
	return 0;
}

int sell_handler_cli(server_t * server)
{
	int id;
	int count;
	int result;

	puts("\nEnter product ID: ");
	scanf("%d", &id);
	puts("\nEnter count: ");
	scanf("%d", &count);
	
	item_t * i = item_search_id(&server->items, id);
	if(!i)
	{
		fprintf(stderr, "ID %d product not found\n", id);
		return -1;
	}

	if(i->count < count)
	{
		fprintf(stderr, "out of stock\n");
		return -1;
	}
	result = count * i->price;
	printf("\nYour purchase: %d x %s - %d | =%d\n", count, i->name, i->price, result);
	i->count -= count;

	/*sending*/

	return 0;
}

int cli_handler(server_t * server)
{
	struct timeval tv;
	tv.tv_sec = 10; 
	tv.tv_usec = 0;

	select(FD_SETSIZE, &server->inputs, NULL,NULL, &tv);
	{
		int nread;
		char buffer[16];
		if(FD_ISSET(0, &server->inputs))
		{
			ioctl(0, FIONREAD, &nread);
			nread = read(0, buffer, nread);
			buffer[nread] = 0;
			if(!strncmp("1", buffer, 1))
				return show_handler_cli(server);
			if(!strncmp("2", buffer, 1))
				return add_handler_cli(server);
		}
	}
}

int loop_cli(server_t * server)
{
	if(init_cli(server))
	{
		printf("init_cli");
		return -1;
	}

	puts("1. Assortment\n2. Add\n");
	cli_handler(server);
}
