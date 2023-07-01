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
