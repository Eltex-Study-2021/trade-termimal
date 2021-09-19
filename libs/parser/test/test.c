#include "parser.h"
 
int main(void)
{
        server_t server;
        memset(&server, 0, sizeof(server));
        if (config_parse(&server))
        {
                return -1;
        }
        client_t client;
        memset(&client, 0, sizeof(client));
        if (config_parse_client(&client))
        {
                return -1;
        }
        return 0;
}
