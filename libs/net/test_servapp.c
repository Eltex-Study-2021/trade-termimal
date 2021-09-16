#include "net.h"

int
main(int argc, char **argv) {

	net_t main;
	item_t item;
	memset(&item, 0, sizeof(item));

	socket_create(&main);
	socket_bind(&main);
	socket_listen(&main);
	//now we can send/recv item
	socket_accept(&main);

	socket_recv(&main, &item);
	//socket_send(&main, &item)
	net_print_item(&item);

	return 0;
}