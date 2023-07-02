#include "main.h"

/******************** PRINT HEX NUM IN LOWER OR UPPER ********************/
/**
 * print_hexa - Function that prints a hexadecimal number in lower or upper
 * @types: The list of argument
 * @map_to: The array of value to map the number to
 * @buffer: The buffer of array to handle print
 * @flags: To calculate the active flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: Return the number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags &  F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/**************************** PRINT POINTER ******************************/
/**
 * print_pointer - Function that prints the value of a pointer variable
 * @types: The list of arguments
 * @buffer: The buffer of array to handle print
 * @flags: To calculate the active flags
 * @width: The width specifier
 * @precision: The precision specifier
 * @size: The size specifier
 *
 * Return: Return the number of characters printed
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2; /* length is equal 2 for '0x' */
	int padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
	{
		extra_c = ' ';
		length++;
	}

	ind++;

	return (write_pointer(buffer, ind, length, width,
				flags, padd, extra_c, padd_start));
}
