#include "main.h"
#include <stddef.h>

/**
 * print_char - Prints a char from a va_list.
 * @args: va_list containing the char to print.
 *
 * Return: number of charaters printed
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));

	return (1);
}

/**
 * print_string - Prints a string from a va_list.
 * @args: va_list containing the string to print.
 *
 * Description: Prints (nil) if the string is NULL.
 * Return: number of charaters printed
 */
int print_string(va_list args)
{
	int i;
	char *str_null = "(null)";
	char *string = va_arg(args, char*);

	if (string != NULL)
		for (i = 0; string[i] != '\0'; i++)
		{
			_putchar(string[i]);
		}
	else
	{
		for (i = 0; str_null[i] != '\0'; i++)
			_putchar(str_null[i]);
	}

	return (i);
}

/**
 * print_percent - Prints a percent sign.
 * @args: va_list (not used).
 *
 * Return: number of charaters printed
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');

	return (1);
}

/**
 * print_int - Prints a integer.
 * @args: va_list (not used).
 *
 * Return: number of charaters printed
 */
int print_int(va_list args)
{
	int number = va_arg(args, int);
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
		count += print_int_helper(int_to_print, 10, "");
	}

	return (count);
}

/**
 * print_int_helper - Prints a integer the recursive way.
 * @int_to_print: the int to print.
 * @base: the base of the number to print
 * @after_nine: character to print after 9
 * Return: number of charaters printed
 */
int print_int_helper(unsigned int int_to_print, unsigned int base,
	char *after_nine)
{
	int count;

	if (int_to_print != 0)
	{
		count = print_int_helper(int_to_print / base, base, after_nine);
		if	((int_to_print % base) < 9)
			_putchar((int_to_print % base) + '0');
		else
			_putchar(after_nine[(int_to_print % base) - 10]);
		return (count + 1);
	}
	return (0);
}
