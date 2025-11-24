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
	int i;
	char *string = va_arg(ap, char*);

	if (string != NULL)
		for (i = 0; string[i] != '\0'; i++)
		{
			_putchar(string[i]);
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
