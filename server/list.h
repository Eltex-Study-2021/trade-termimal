#pragma once

typedef struct node
{
	struct node * next;
	void * data;
} node_t;

node_t * create_node(void * data);
int insert_node_first(node_t ** head, node_t * node);
int insert_node_last(node_t ** head, node_t * node);
int print_list(node_t * head);
int clear_list(node_t * head);
node_t * search_list(node_t * head, void * data);
int remove_node(node_t ** head, node_t * node);
