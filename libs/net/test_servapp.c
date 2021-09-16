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
	printf("SERV RECV\n");
	net_print_item(&item);

	init_item(&item);
	socket_send(&main, &item);
	printf("SERV SENT\n");
	net_print_item(&item);

	return 0;
}