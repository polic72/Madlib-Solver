#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdbool.h>


//Do I really need to implement my own linked list? Yes...yes I do...
typedef struct LinkedList
{
	struct LL_node *start;
	struct LL_node *end;
	int size;
}LinkedList;


typedef struct LL_node
{
	struct LL_node *left;
	void *data;
	struct LL_node *right;
}LL_node;


LinkedList *ll_create();

bool ll_add_beginning(void *object_to_add);
bool ll_add_end(void *object_to_add);

void ll_clear();
bool ll_remove_beginning();
bool ll_remove_end();


#endif //LINKEDLIST_H
