#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig) // функция-обработчик сигнала
{ 
    switch(sig)
    {
            case SIGINT:
                    printf("Process #1 catches signal SIGINT\n");
                    exit(0);
                    break;
            case SIGTERM:
                    printf("Process #1 catches signal SIGTERM\n");
                    exit(0);
                    break;
            default:
                    fprintf(stderr, "Caught wrong signal: %d\n", sig);
                    return;
    }
}

int main(int argc, char * argv[]) 
{
    struct sigaction sig_act;
    sigset_t newset;
    sigemptyset(&newset);
    sig_act.sa_handler = sig_handler;
    sigaction(SIGTERM, &sig_act, 0);
    sigaction(SIGINT, &sig_act, 0);

    printf("My pid is %i\n", getpid());
    printf("Waiting...\n");

    while(1) sleep(1);

    return EXIT_FAILURE;
}
