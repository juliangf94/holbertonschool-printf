#include "main.h"
#include <stddef.h>

/**
 * print_char - Prints a char from a va_list.
 * @ap: va_list containing the char to print.
 *
 * Return: number of charaters printed
 */
int print_char(va_list ap)
{
	_putchar(va_arg(ap, int));

	return (1);
}

/**
 * print_string - Prints a string from a va_list.
 * @ap: va_list containing the string to print.
 *
 * Description: Prints (nil) if the string is NULL.
 * Return: number of charaters printed
 */
int print_string(va_list ap)
{
	int i, j;
	char str_null = ("Null");
	char *string = va_arg(ap, char*);

	if (string != NULL)
		for (i = 0; string[i] != '\0'; i++)
		{
			_putchar(string[i]);
		}
	else
	{
		for (j = 0; str_null[j] != '\0'; j++)
			_putchar(str_null[j]);
	}

	return (i);
}

/**
 * print_percent - Prints a percent sign.
 * @ap: va_list (not used).
 *
 * Return: number of charaters printed
 */
int print_percent(va_list ap)
{
	(void)ap;
	_putchar('%');

	return (1);
}

/**
 * print_int - Prints a integer.
 * @ap: va_list (not used).
 *
 * Return: number of charaters printed
 */
int print_int(va_list ap)
{
	int number = va_arg(ap, int);
	unsigned int int_to_print;
	unsigned int count = 0;

	if (number < 0)
	{
		_putchar('-');
		count++;
		int_to_print = -number;
	}
	else
	{
		int_to_print = number;
	}
	if (number == 0)
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

/**
 * print_int_helper - Prints a integer the recursive way.
 * @int_to_print: the int to print.
 *
 * Return: number of charaters printed
 */
int print_int_helper(int int_to_print)
{
	int count;

	if (int_to_print == 0)
	{
		return (0);
	}
	else
	{
		count = print_int_helper(int_to_print / 10);
		_putchar((int_to_print % 10) + '0');
		return (count + 1);
	}
}
