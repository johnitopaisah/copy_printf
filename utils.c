#include "main.h"

/**
 * is_digit - Function that virifies if na char is a digit
 * @c: The character to evaluate
 *
 * Return: Return 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
