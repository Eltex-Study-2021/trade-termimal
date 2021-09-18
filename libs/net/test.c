#include "net.h"

int
main(int argc, char **argv) {

	net_t main[3];
	item_t item;
	init_item(&item);

	for(int i = 0; i < 1; i++) {
		socket_create(&main[i]);
		socket_bind(&main[i]);
		socket_send(&main[i], &item);
        socket_recv(&main[i], &item);
	}
	printf("id:%2d\n", item.id);
	printf("name:%2s\n", item.name);

	exit(EXIT_FAILURE);
}
