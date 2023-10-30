#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"


LinkedList *ll_create()
{
	LinkedList *list = malloc(sizeof(*list));

	list->start = NULL;
	list->end = NULL;
	list->size = 0;


	return list;
}


bool ll_add_beginning(LinkedList *list, void *object_to_add)
{
	if (list == NULL)
	{
		return false;
	}


	if (list->start == NULL)
	{
		list->start = malloc(sizeof(*list->start));
	}


	return false;
}


bool ll_add_end(LinkedList *list, void *object_to_add)
{
	return false;
}


void ll_clear(LinkedList *list)
{
	//
}


bool ll_remove_beginning(LinkedList *list)
{
	return false;
}


bool ll_remove_end(LinkedList *list)
{
	return false;
}
