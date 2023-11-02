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

bool ll_add_beginning(LinkedList *list, void **object_to_add);
bool ll_add_end(LinkedList *list, void **object_to_add);

bool ll_clear(LinkedList *list);
bool ll_remove_beginning(LinkedList *list);
bool ll_remove_end(LinkedList *list);


#endif //LINKEDLIST_H
