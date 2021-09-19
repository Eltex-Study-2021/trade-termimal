#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

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

int main(void)
{
    struct sigaction sa;

    printf("PID: %d\n", getpid());

    sa.sa_handler = &signal_handle;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("Error: cannot handle SIGINT");
    }

    if (sigaction(SIGTERM, &sa, NULL) == -1)
    {
        perror("Error: cannot handle SIGTERM");
    }

    while(1) 
    {
        sleep(3);
    }
    return 0;
}
