#include "net.h"

int socket_create(net_t *net)
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Socket created\n");
	}
	net->fd = fd;
	return 0;
}

int socket_bind(net_t *net)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	net->addrlen = sizeof(struct sockaddr_in);
	int offset = rand()%20;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT + offset);
	addr.sin_addr.s_addr = inet_addr(ADDR);

	if(-1 == bind(net->fd, (const struct sockaddr *)&addr, net->addrlen))
	{
		perror("bind");
		exit(EXIT_FAILURE);
	} else {
		printf("Socket binded\n");
	}

	memcpy(&net->addr, &addr, net->addrlen);
	return 0;
}

ssize_t socket_send(net_t *net, item_t *item)
{
	//func send one item
	ssize_t numRead = 0;
	size_t buff_len = sizeof(*item);
	char *buff = calloc(buff_len, sizeof(char));
	memcpy(buff, item, buff_len);

	numRead = send(net->fd, buff, buff_len, 0);
	if(numRead == -1)
	{
		perror("send");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("send bytes %lu\n", numRead);
	}
	return numRead;
}

ssize_t socket_recv(net_t *net, item_t *item)
{
	ssize_t numRead = 0;
	size_t buff_len = sizeof(*item);
	char *buff = calloc(buff_len, sizeof(char));

	numRead = recv(net->fd, buff, buff_len, MSG_DONTWAIT);
	if(numRead == -1)
	{
		perror("recv");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("recv bytes %lu\n", numRead);
	}
	return numRead;
}

void fill_item(item_t *item)
{
	item->id = 1;
	item->name = calloc(30, sizeof(char));
	item->desc = calloc(100, sizeof(char));
	fgets(item->name, 30, stdin);
	fgets(item->desc, 100, stdin);
	//item->name = "Water";
	//item->desc = "Liquid";
	item->price = 100;
	item->count = 10;
}
