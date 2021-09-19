#include "client.h"
#include <stdio.h>

int main()
{
	printf("client\n");

	client_t * client = NULL;

	client_create(&client);
	client_init(client);
	client_loop(client);
	client_destroy(client);

	return 0;
}
