#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - Function that add node at the beginning of a linked list
 * @head: Pointer to pointer to head node
 * @str: string to be added to the node data part
 *
 * Return: Return the address of the new element, or NULL if failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	
		
}
