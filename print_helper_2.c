#include "main.h"
#include <stddef.h>

/**
 * print_unsigned_int - Prints a integer.
 * @args: va_list (not used).
 *
 * Return: number of charaters printed
 */
int print_unsigned_int(va_list args)
{
	unsigned int int_to_print = va_arg(args, int);
	unsigned int count = 0;

	if (int_to_print == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		count += print_int_helper(int_to_print);
	}

	return (count);
}
