<<<<<<< HEAD
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
                    fprintf(stderr, "Caught wrong signals: %d\n", signal);
                    return;
    }
}

int main()
{
        struct sigaction sa;

        printf("PID: %d\n", getpid());

        sa.sa_handler = &signal_handle;
        sa.sa_flags = SA_RESTART;
        sigfillset(&sa.sa_mask);
        printf("client\n");

        if (sigaction(SIGINT, &sa, NULL) == -1)
        {
            perror("Error: cannot handle SIGINT");
        }

        if (sigaction(SIGTERM, &sa, NULL) == -1)
        {
            perror("Error: cannot handle SIGTERM");
        }

        client_t * client = NULL;

        client_create(&client);
        client_init(client);
        client_loop(client);
        client_destroy(client);

        return 0;
}
=======
#include "client.h"
#include <stdio.h>

int main()
{
	printf("client\n");

	client_t * client = NULL;

	client_create(&client);
	client_init(client);
	client_loop(client);
	client_destroy(client);

	return 0;
}
>>>>>>> 6e36da8fb584d58eaa743e5c622a9fd4ea6c4932