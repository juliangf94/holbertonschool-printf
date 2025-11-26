#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int len = 0; /* Contabilizar la cantidad de caracteres impresos */
	int i, j;/* Variables para el loop */
	char *str;
	va_list args;/* Declaro la lista de argumentos */

	va_start(args, format); /* Comenzamos la posicion inicial */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%') /*Encuentra %*/
		{
			i++;
			if (format[i] == 's') /*Encuentra un string*/
			{
				str = va_arg(args, char *);
				for (j = 0; str[j] != '\0'; j++)
				{
					putchar(str[j]);
					len++;
				}
			}
			else if (format[i] == 'c')
			{

			}
			else if (format[i] == 'd')
			{
			}
			else if (format[i] == '%')
			{
			}
		}
		else
		{
			putchar(format[i]);
			len++;
		}
	}
	va_end(args);
	return (len);
}
