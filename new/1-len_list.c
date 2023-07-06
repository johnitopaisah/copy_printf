#include "main.h"

/**
 * list_len - function that returns the number of elements  in a linked list
 * @h: pointer to the head node
 *
 * Return: Return the number of nodes
 */

size_t list_len(list_t *h)
{
	size_t nodes = 0;
	list_t *tmp;

	tmp = h;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		nodes++;
	}
	return (nodes);
}
