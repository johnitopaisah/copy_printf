#include "main.h"

/**
 * get_size - Function that calculates the size to bast the argument
 * @format: The formatted string in which to print the arguments
 * @i: The list of arguments to be printed
 *
 * Return: Return the precision
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
