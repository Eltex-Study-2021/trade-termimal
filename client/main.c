#include "client.h"
#include <stdio.h>
#include <signal.h>

void signal_handle(int signal)
{
    switch(signal)
    {
            case SIGINT:
                    printf("SIGINT\n");
                    exit(0);
                    break;
            case SIGTERM:
                    printf("SIGTERM\n");
                    exit(0);
                    break;
            default:
                    fprintf(stderr, "Caught wrong signal: %d\n", signal);
                    return;
    }
}

int main()
{
        struct sigaction sa;

        //printf("PID: %d\n", getpid());

        sa.sa_handler = &signal_handle;
        sa.sa_flags = SA_RESTART;
        sigfillset(&sa.sa_mask);
        printf("client\n");

        client_t * client = NULL;

        client_create(&client);
        client_init(client);
        client_loop(client);
        client_destroy(client);

        return 0;
}
