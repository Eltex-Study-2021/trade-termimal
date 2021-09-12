#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#include "list.h"

node_t * init_node(void * data)
{
	node_t * p = (node_t*)malloc(sizeof(node_t));
	if(!p)
	{
		perror("malloc");
		return NULL;
	}
	p->next = NULL;
	p->data = data;
	return p;
}

node_t * add_first(node_t * head, void * data)
{
	node_t * p = init_node(data);
        if(!p) return NULL;
	p->data = data;
	p->next = head;
	return p;
}

void add_last(node_t * head, void * data)
{
	node_t * tmp = init_node(data);
	tmp->data = data;
	tmp->next = NULL;
	node_t * p = head;
	while(p->next)
	{
		p = p->next;
	}
	p->next = tmp;
}


void print_list(node_t * head)
{
	node_t * cur;
	for (cur = head; cur; cur = cur->next)
	{
		printf("%s ", cur->data);
	}
}

void clear_list(node_t * head) 
{
	while (head)
	{
		node_t * p = head;
		head = head->next;
		free(p);
	}
}

void search_list(node_t * head, void * data)
{
	node_t * tmp = head;
	while(tmp->next)
	{
		if(strcmp(tmp->data, data) == 0)
		{
			printf("Found element: %s\n", tmp->data);
			break;
		}
		tmp = tmp->next;
	}
}

int del_element(node_t * head, void * data)
{
	node_t * tmp = head;
	node_t * p = NULL;

	if(!head) return NULL;

	while(tmp && tmp->data != data)
	{
		p = tmp;
		tmp = tmp->next;
	}
	if(tmp == head)
	{
		free(head);
		return tmp->next;
	}
	if(!tmp) return head;

	p->next = tmp->next;
	free(tmp);
	return head;
}
