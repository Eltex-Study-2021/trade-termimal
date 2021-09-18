#include "net.h"

int
main(int argc, char **argv) {

	net_t main;
	item_t item, *ptr;
	ptr = &item;
	size_t item_len = sizeof(item);

	socket_create(&main);
	init_client_sock(&main);
	socket_connect(&main);

	printf("CLIENT SENT:\n");
	init_item(&item);
	socket_send(&main, &item);
	//socket_recv(&main, (char **)&ptr, (int *)item_len);

	printf("CLIENT RECV\n");
	socket_recv(&main, &item);
	net_print_item(ptr);

	return 0;
}
