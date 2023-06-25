#include "main.h"

/************************* WRITE HANDLERS FUNCTIONS *************************/

/* This Handle Write Characters */
/**
 * handle_write_char - Function to prints a string
 * @c: character types
 * @buffer: The buffer array to handle print
 * @flags: To calcute the active flags
 * @width: The width specification
 * @precision: The precision specification
 * @size: The size specification
 *
 * Return: Return the number of characters printed
 */
int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size)
{
	/* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - print a string
 * @is_negative: Lists of argument
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get the width
 * @precision: precision specifier
 * @size: Size specifier
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;
	
	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags,
				width, precision, length, padd, extra_ch));
}

/************************ WRITE NUM *************************/
/**
 * write_num - Function that write number using buffer
 * @ind: The index at which the number starts on the buffer
 * @buffer: The buffer
 * @flags: To Caculate the active flags
 * @width: The width specifier
 * @prec: Precision specifier
 * @length: The number of length
 * @padd: Padding character
 * @extra_c: Extra character
 *
 * Return: The number of printed character
 */

