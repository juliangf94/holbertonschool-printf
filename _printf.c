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
	va_list args;
	int sum = 0, i;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
				sum += select_type(format[i], args) - 1;
			else
				return (-1);
		}
		else
		{
			_putchar(format[i]);
		}
		sum++;
	}
	va_end(args);
	return (sum);
}

/**
 * select_type - Selects and executes the correct print function.
 * @type: Format specifier to match.
 * @args: va_list containing the argument to print.
 *
 * Return: Value returned by the matched print function.
 */
int select_type(char type, va_list args)
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
			return (funcs[i].function(args));
		}
	}

	_putchar('%');
	_putchar(type);
	return (2);
}
