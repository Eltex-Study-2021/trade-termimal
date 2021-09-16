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
	net_print_item(&item);
	//socket_recv(&main, &item);
	
	return 0;
}
