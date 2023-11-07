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


	LL_node *new_node = malloc(sizeof(*new_node));
	new_node->data = object_to_add;
	new_node->left = NULL;
	new_node->right = NULL;


	if (list->start == NULL)
	{
		list->start = new_node;
		list->end = new_node;
	}
	else
	{
		list->start->left = new_node;
		new_node->right = list->start;

		list->start = new_node;
	}

	list->size++;


	return true;
}


bool ll_add_end(LinkedList *list, void *object_to_add)
{
	if (list == NULL)
	{
		return false;
	}


	LL_node *new_node = malloc(sizeof(*new_node));
	new_node->data = object_to_add;
	new_node->left = NULL;
	new_node->right = NULL;


	if (list->start == NULL)
	{
		list->start = new_node;
		list->end = new_node;
	}
	else
	{
		list->end->right = new_node;
		new_node->left = list->end;

		list->end = new_node;
	}

	list->size++;


	return true;
}


bool ll_clear(LinkedList *list)
{
	if (list == NULL)
	{
		return false;
	}


	while (list->size > 0)
	{
		ll_remove_end(list);
	}


	return true;
}


bool ll_remove_beginning(LinkedList *list)
{
	if (list == NULL)
	{
		return false;
	}


	LL_node *purgatory = list->start;


	if (list->start->right == NULL)
	{
		list->start = NULL;
		list->end = NULL;
	}
	else
	{
		list->start = list->start->right;
	}

	list->size--;


	free(purgatory->data);
	free(purgatory);

	return true;
}


bool ll_remove_end(LinkedList *list)
{
	if (list == NULL)
	{
		return false;
	}


	LL_node *purgatory = list->end;


	if (list->end->left == NULL)
	{
		list->start = NULL;
		list->end = NULL;
	}
	else
	{
		list->end = list->end->left;
	}

	list->size--;


	free(purgatory->data);
	free(purgatory);

	return true;
}
