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
 * print_octal - Prints a integer.
 * @args: va_list (not used).
 *
 * Return: number of charaters printed
 */
int print_octal(va_list args)
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
		count += print_int_helper(int_to_print, 8, "");
	}

	return (count);
}

/**
 * print_hexa_lower - Prints a integer in hexa lowercase.
 * @args: va_list.
 *
 * Return: number of charaters printed
 */
int print_hexa_lower(va_list args)
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
		count += print_int_helper(int_to_print, 16, "abcdefg");
	}

	return (count);
}

/**
 * print_hexa_upper - Prints a integer in hexa uppercase.
 * @args: va_list.
 *
 * Return: number of charaters printed
 */
int print_hexa_upper(va_list args)
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
		count += print_int_helper(int_to_print, 16, "ABCDEF");
	}

	return (count);
}
