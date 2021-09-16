#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <netinet/ip.h>

#define PORT	32000
#define ADDR	"127.0.0.1"
#define LISTEN_BACKLOG 10

typedef struct
{
    uint16_t id;
    char * name;
    char * desc;
    uint32_t price;
    uint32_t count;
} item_t;

typedef struct
{
	int fd;
	struct sockaddr_in addr;
	socklen_t addrlen;
}	net_t;

int socket_create();
int socket_bind(net_t *);
int socket_connect(net_t *);
int socket_listen(net_t *net);
int socket_accept(net_t *net);
ssize_t socket_send(net_t *, item_t *);
ssize_t socket_recv(net_t *, item_t *);
void net_print_item(item_t *);
void init_client_sock(net_t *);
void init_item(item_t *);