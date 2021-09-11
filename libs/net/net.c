#include "net.h"

int socket_create()
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
	return fd;
}

int socket_bind(net_t *net)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	net->addrlen = sizeof(struct sockaddr_in);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(ADDR);

	if(-1 == bind(net->fd,
		         (const struct sockaddr *)&addr, 
		         net->addrlen))
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Socket binded\n");
	}

	memcpy(&net->addr, &addr, net->addrlen);
	return 0;
}

ssize_t socket_send(net_t *net, item_t *item)
{
	//func send one item
	ssize_t numRead = 0;
	numRead = send(net->fd, item, sizeof(*item), 0);
	if(numRead != sizeof(*item))
	{
		perror("send");
		exit(EXIT_FAILURE);
	}

	return numRead;
}

ssize_t socket_recv(net_t *net, item_t *item)
{
	ssize_t numRead = 0;
	numRead = recv(net->fd, item, sizeof(*item), MSG_DONTWAIT);
	if(numRead == -1)
	{
		perror("recv");
		exit(EXIT_FAILURE);
	}
	//item_t * i = (item_t *) buff;
	//*item = *i;
	return numRead;
}

int socket_connect(net_t *net)
{
	if(-1 == connect(net->fd,
		            (const struct sockaddr *) &net->addr,
		            net->addrlen))
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int socket_listen(net_t *net)
{
	int ready_listen = listen(net->fd, 4);
	if(ready_listen == -1)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int socket_accept(net_t *net)
{
	int fd = accept(net->fd, (struct sockaddr *)&net->addr, &net->addrlen);
	if(fd == -1)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	return fd;
}

void init_item(item_t *item)
{
	item->id = 1;
	item->name = calloc(30, sizeof(char));
	item->desc = calloc(100, sizeof(char));
	printf("Enter name: \n");
	fgets(item->name, 30, stdin);
	printf("Enter description: \n");
	fgets(item->desc, 100, stdin);
	item->price = 100;
	item->count = 10;
}
