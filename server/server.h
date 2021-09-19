#pragma once
#include "../libs/net/net.h"
#include "../libs/list/list.h"
#include "../libs/cli/cli.h"
#include "../parser/parser.h"
#include <sys/time.h>
#include <sys/select.h>
#include <sys/ioctl.h>

int server_create(server_t ** server);
int server_init(server_t * server);
int server_loop(server_t * server);
int server_destroy(server_t * server);
int net_init_server(server_t * server);
