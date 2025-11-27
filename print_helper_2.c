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
		count += print_int_helper(int_to_print, 10, "");
	}

	return (count);
}


/**
 * print_address - Prints the address of a pointer in a
 * hexadecimal format
 * @ap: va_list containing the address
 *
 * Return: the address in a hexadecimal format
 */
int print_address(va_list ap)
{
	void *ptr = va_arg(ap, void *);
	unsigned long int addr = (unsigned long int) ptr;
	int count = 0;

	count += _putchar('0');
	count += _putchar('x');
	count += print_int_helper(addr, 16, "abcdef");
	return (count);
}
