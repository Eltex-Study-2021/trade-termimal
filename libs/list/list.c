#include "list.h"

node_t * create_node(void * data)
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

int insert_node_first(node_t ** head, node_t * node)
{
	node->next = *head;
	*head = node;
}

int insert_node_last(node_t ** head, node_t * node)
{
	if(!*head)
		return insert_node_first(head, node);
	node_t * last = *head;

	for (; last->next; last = last->next);
	last->next = node;
}

int print_list(node_t * head, char type)
{
	node_t * cur = head;
	while(cur != NULL)
	{
		switch(type)
		{
			case 'i': printf("%u\n", *(int*)cur->data);
			case 's': printf("%s\n", (char *)cur->data);
		}
		//printf("%s\n", (char *)cur->data);
		cur = cur->next;
	}
}

int clear_list(node_t * head)
{
	while (head)
	{
		node_t * p = head;
		head = head->next;
		free(p);
	}
}

node_t * search_list(node_t * head, void * data)
{
	node_t * tmp = head;
	while(tmp != NULL)
	{
		if(strcmp(tmp->data, data) == 0)
		{
			printf("Found element: %s\n", (char *)tmp->data);
			break;
		}
		tmp = tmp->next;
	}
}

int remove_node(node_t ** head, node_t * node)
{
	if(strcmp(node->data, (*head)->data) == 0)
	{
		node_t * tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return 0;
	}
	node_t * cur = (*head)->next;
	node_t * prev = *head;
	while(cur != NULL && prev != NULL)
	{
		if(strcmp(node->data, cur->data) == 0)
		{
			node_t * tmp = cur;
			prev->next = cur->next;
			free(tmp);
			return 0;
		}
		prev = cur;
		cur = cur->next;
	}
}
