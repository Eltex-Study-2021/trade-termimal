#include "server.h"
#include <stdio.h>

int main()
{
    printf("server\n");

    server_t * server = NULL;

    server_create(&server);
    server_init(server);
    //server_loop(server);
    //server_destroy(server);

    return 0;
}
