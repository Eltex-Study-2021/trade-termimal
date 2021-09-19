#include <stdio.h>
#include "list.h"

int main(void)
{
		node_t * HEAD = NULL;
		node_t * node;
		
		node = create_node("6");
		insert_node_first(&HEAD, node);
		node = create_node("5");
		insert_node_first(&HEAD, node);
		node = create_node("4");
		insert_node_first(&HEAD, node);
		node = create_node("3");
		insert_node_first(&HEAD, node);
		node = create_node("2");
		insert_node_first(&HEAD, node);
		node = create_node("1");
		insert_node_first(&HEAD, node);
		print_list(HEAD, 's');
		puts("\n");

		search_list(HEAD, "1");
		puts("\n");

		node = create_node("2");
		remove_node(&HEAD, node);
		print_list(HEAD, 's');
		puts("\n");

		clear_list(HEAD);

		return 0;
}
