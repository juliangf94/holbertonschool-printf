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
<<<<<<< HEAD
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
	count += _print_hex_long(addr);
	return (count);
}


/**
 * _print_hex_long - Prints
 * @n: 
 *
 * Return:
 */
int _print_hex_long(unsigned long int n)
{
	unsigned long int temp = n;
	int count;
	char hex_chars[] = "0123456789abcdef";

	if (temp / 16)
		count += _print_hex_long(temp / 16);
		return (count + 1);
	 _putchar(hex_chars[temp % 16]);
	return (0);
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
