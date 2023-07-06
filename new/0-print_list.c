#include <stdio.h>
#include "main.h"

/**
 * print_list - function that prints all the elements of a list_t list.
 * @h: pointer to the head node
 *
 * Return: Return the number of nodes
 */
size_t print_list(list_t *h)
{
	size_t node = 0;
	list_t *tmp;

	tmp = h;

	while (tmp != NULL)
	{
		if (tmp->str != NULL)
			printf("[%u] %s\n", tmp->len, tmp->str);
		else
			printf("[0] (nil)\n");
		tmp = tmp->next;
		node++;
	}
	return (node);
}
