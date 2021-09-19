#include "parser.h"
 
int main(void)
{
        server_t server;
        if (config_parse(&server))
        {
                return -1;
        }
        client_t client;
        if (config_parse(&client))
        {
                return -1;
        }
        return 0;
}
