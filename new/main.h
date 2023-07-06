#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/**
 * struct list_t - singly linked list
 * @str: string
 * @len: length of the string
 *
 * Desc: singly linked list
 */
struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
};

typedef struct list_s list_t;

size_t print_list(list_t *h);
size_t list_len(list_t *h);
#endif /* MAIN_H */
