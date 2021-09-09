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
	// sockets
	int fd;
	struct sockaddr_in addr;
	socklen_t addrlen;
}	main_t;

int socket_create(main_t *);
int socket_bind(main_t *);
ssize_t socket_send(main_t *, item_t *);
void fill_item(item_t *);
