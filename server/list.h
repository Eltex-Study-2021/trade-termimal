#pragma once

typedef struct node
{
	struct node * next;
	void * data;
} node_t;

node_t * init_node(void * data);
node_t * add_first(node_t * head, void * data);
void add_last(node_t * head, void * data);
void print_list(node_t * head);
void clear_list(node_t * head);
void search_list(node_t * head, void * data);
int del_element(node_t * head, void * data)
