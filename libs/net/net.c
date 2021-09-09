#include "net.h"

int socket_create(main_t *main) {
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	} else {
		printf("Socket created\n");
	}
	main->fd = fd;
	return 0;
}

int socket_bind(main_t *main) {
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	int offset = rand()%20;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT + offset);
	addr.sin_addr.s_addr = inet_addr(ADDR);

	if(-1 == bind(main->fd, (const struct sockaddr *)&addr, sizeof(addr))) {
						printf("an error: %s\n", strerror(errno));
						exit(EXIT_FAILURE);
					} else {
						printf("Socket binded\n");
					}
	memcpy(&main->addr, &addr, sizeof(addr));
	return 0;
}

ssize_t socket_send(main_t *main, item_t *item) { //func must recv list
	ssize_t numRead = 0;
	size_t buff_len = sizeof(*item);
	char *buff = calloc(buff_len, sizeof(char));
	memmove(buff, &item->id, sizeof(item->id));
	memmove(buff + sizeof(uint16_t), &item->name, sizeof(item->name));

	numRead = send(main->fd, buff, buff_len, 0);
	if(numRead == -1) {
		perror("send");
		exit(EXIT_FAILURE);
	} else {
		printf("send bytes %lu\n", numRead);
	}
	return numRead;
}

ssize_t socket_recv() {


    return 0;
}

void fill_item(item_t *item) {
	item->id = 1;
	item->name = "Milk";
	item->desc = "Liquid from cow, very healthy";
	item->price = 100;
	item->count = 10;
}
