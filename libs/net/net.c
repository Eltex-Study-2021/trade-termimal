#include "net.h"

int socket_create(net_t *net)
{
	//net->cfd = 0; //server accept()
	net->fd = socket(AF_INET, SOCK_STREAM, 0);
	if (net->fd == -1)
	{
		perror("socket");
		return -1;
	}
	return 0;
}

int socket_bind(net_t *net)
{
	struct sockaddr_in addr;
	int opt = 1;
	memset(&addr, 0, sizeof(addr));
	net->addrlen = sizeof(struct sockaddr_in);

	// Forcefully attaching socket to the port 8080
	if (setsockopt(net->fd, SOL_SOCKET, 
		           SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		return -1;
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(ADDR);

	if (-1 == bind(net->fd,
		         (const struct sockaddr *)&addr, 
		         net->addrlen))
	{
		perror("bind");
		return -1;
	}
	memcpy(&net->addr, &addr, net->addrlen);

	return 0;
}

ssize_t socket_send(net_t *net, item_t *item)
{
	ssize_t numRead = 0;
		//func send one item
		numRead = send(net->fd, item, sizeof(*item), 0);
		if (numRead != sizeof(*item))
		{
			perror("send");
			return -1;
		}
		return numRead;
}

ssize_t socket_recv(net_t *net, item_t *item) //char **, int *
{
	ssize_t numRead = 0;
	char *buff = calloc(1, sizeof(*item));
	numRead = recv(net->fd, buff, sizeof(*item), 0);
	if (numRead == -1)
	{
		perror("recv");
		return -1;
	}
	item_t *tmp = (item_t *) buff;
	*item = *tmp;
	free(buff);
	return numRead; //return 0;
}

int socket_connect(net_t *net)
{
	if (-1 == connect(net->fd,
		            (const struct sockaddr *) &net->addr,
		            sizeof(struct sockaddr_in)))
	{
		perror("connect");
		return -1;
	}
	return 0;
}

int socket_listen(net_t *net)
{
	//func marks the socket as it used to accept connection
	if (listen(net->fd, LISTEN_BACKLOG) == -1)
	{
		perror("listen");
		return -1;
	}
	return 0;
}

int socket_accept(net_t *net)
{
	net->fd = accept(net->fd, (struct sockaddr *)&net->addr, &net->addrlen);
	if (net->fd == -1)
	{
		perror("accept");
		return -1;
	}
	return 0;
}

void init_item(item_t *item)
{
	item->id = 1;
	printf("Enter a name:");
	fgets(item->name, 32, stdin);
	printf("Enter a description:");
	fgets(item->desc, 128, stdin);
	item->price = 100;
	item->count = 10;
}

void net_print_item(item_t *item)
{
	printf("id: %d\n", item->id);
	printf("name: %s\n", item->name);
	printf("description: %s\n", item->desc);
	printf("price: %u\n", item->price);
	printf("count: %u\n", item->count);
	printf("\n");
}

void init_client_sock(net_t * net)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	net->addrlen = sizeof(struct sockaddr_in);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(ADDR);

	memcpy(&net->addr, &addr, net->addrlen);
}
