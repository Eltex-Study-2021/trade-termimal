#include <stdio.h>
#include "list.h"

int main()
{
	node_t * HEAD = NULL;
	HEAD = add_first(HEAD, "3");
	HEAD = add_first(HEAD, "2");
	HEAD = add_first(HEAD, "1");

	print_list(HEAD);
	puts("\n");
	add_last(HEAD, "4");
	add_last(HEAD, "5");
	
	print_list(HEAD);
	puts("\n");

	search_list(HEAD, "2");
	del_element(HEAD, "3");

	puts("\n");
	print_list(HEAD);
	
	clear_list(HEAD);

	return 0;
}
