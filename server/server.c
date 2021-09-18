#include "server.h"
#include <stdlib.h>

// #include "parser.h"
// // #include "cli.h"
// // #include "net.h"

node_t * node;
node_t * HEAD = NULL;

int server_create(server_t ** server)
{
        *server = calloc(1, sizeof(server_t));

        return 0;
}

int server_init(server_t * server)
{
        //config_parse(server);
        net_init_server(server);
        //init_cli(server);
}

int server_loop(server_t * server)
{
        struct timeval tv;
        tv.tv_sec = 10; 
        tv.tv_usec = 0;
        int retval = 0;

        while (server->need_stop)
        {
                //select
                retval = select(FD_SETSIZE, &server->inputs, NULL, NULL, &tv);
                if (retval == -1)
                {
                        perror("select");
                }
                else if (retval)
                {
                        socket_accept(&server->net);
                        if(FD_ISSET(0, &server->inputs))
                        {
                                printf("ALL GOODD\n");
                        }
                }
                //do
        }
        return 0;
}

int server_destroy(server_t * server)
{
                free(server);
                        return 0;
}

int net_init_server(server_t * server)
{       
        int ready = 0;
        socket_create(&server->net);
        socket_bind(&server->net);
        socket_set_non_block(&server->net);
        socket_listen(&server->net);/*save fd (listen) */

        server->listen_socket = server->net.fd;
        node = create_node(&server->listen_socket);
        insert_node_first(&HEAD, node);
        print_list(HEAD, 'i');

        FD_ZERO(&server->inputs);/*init fd_set*/
        FD_SET(server->listen_socket, &server->inputs);
        ready = select(FD_SETSIZE, &server->inputs, NULL, NULL, NULL);

        if (ready == -1)
        {
                perror("select");
                return -1;
        }

        if (FD_ISSET(server->listen_socket, &server->inputs))
        {
                printf("Accept success\n");
                socket_accept(&server->net);
                socket_recv(&server->net, &server);
        }
        /*
        save fd (listen)
        add fd_set in select
        */

        return 0;
}
