#include "net.h"

int
main(int argc, char **argv) {

	net_t main;
	item_t item, *ptr;
	memset(&item, 0, sizeof(item));
	ptr = &item;
	size_t item_len = sizeof(item);

	socket_create(&main);
	socket_bind(&main);
	socket_listen(&main);
	socket_accept(&main);

	socket_recv(&main, &item);
	//socket_recv(&main, (char **)&ptr, (int *)item_len);
	printf("SERV RECV\n");
	net_print_item(ptr);

	printf("SERV SENT\n");
	init_item(&item);
	socket_send(&main, &item);
	net_print_item(ptr);

	return 0;
}