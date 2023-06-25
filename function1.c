#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of characters
 * @buff_ind: Index at which to add next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/******************** PRINT CHARACTERS ********************/
/**
 * print_char - Function that prints characters
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags: To calculate the active flags
 * @width: The width specification
 * @precision: The precision specification
 * @size: The size specification
 *
 * Return: Return the number of chars printed
 */
int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/******************** PRINT A STRING ********************/
/**
 * print_string - Function that prints strings
 * @types: The list of arguments
 * @buffer: Buffer of array to be handle
 * @flags: To calculates the active flags
 * @width: The width specification
 * @precision: The precision specification
 * @size: The size specification
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
