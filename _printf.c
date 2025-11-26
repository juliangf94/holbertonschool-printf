#include "main.h"
#include <stddef.h>

/**
 * _printf - Produces output according to a format string.
 * @format: Format string containing plain characters and format specifiers.
 *
 * Description: Handles format specifiers like c, s, %, etc., and prints
 *              corresponding arguments. Similar to standard printf.
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int sum = 0, i;

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			sum += select_type(format[i], ap) - 1;
		}
		else
		{
			_putchar(format[i]);
		}
		sum++;
	}
	va_end(ap);
	return (sum);
}

/**
 * select_type - Selects and executes the correct print function.
 * @type: Format specifier to match.
 * @ap: va_list containing the argument to print.
 *
 * Return: Value returned by the matched print function.
 */
int select_type(char type, va_list ap)
{
	int i;
	specifier_t funcs[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'d', print_int},
		{'%', print_percent},
		{'\0', NULL},
	};

	for (i = 0; funcs[i].type != '\0'; i++)
	{
		if (funcs[i].type == type)
		{
			return (funcs[i].fonction(ap));
		}
	}

	return (-1);
}
