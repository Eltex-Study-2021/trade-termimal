#include <stdio.h>

int need_stop;

int init()
{
    // parse_config();
    // init_net();

    return 0;
}

int loop()
{
    while (!need_stop)
    {
        // poll
    }
    return 0;
}

int finalize()
{
    // clear sockets
    // free mem
}

int main(int argc, char ** argv)
{
    init();

    loop();

    finalize();

    return 0;
}
