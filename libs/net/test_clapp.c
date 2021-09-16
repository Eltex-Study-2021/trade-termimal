#include "net.h"

int
main(int argc, char **argv) {

	net_t main;
	item_t item;

	socket_create(&main);
	init_client_sock(&main);
	socket_connect(&main);
	//send filed item to server
	init_item(&item);
	socket_send(&main, &item);
	printf("CLIENT SENT:\n");
	net_print_item(&item);
	socket_recv(&main, &item);
	printf("CLIENT RECV\n");
	net_print_item(&item);

	return 0;
}
