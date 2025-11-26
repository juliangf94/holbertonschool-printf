#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct specifier - Associates a type string with a print function.
 * @type: Type identifier (e.g., "d", "i", "%").
 * @fonction: Function pointer used to print the corresponding type.
 */
typedef struct specifier
{
	char type;
	int (*fonction)(va_list ap);
} specifier_t;

int _putchar(char c);

int _printf(const char *format, ...);
int select_type(char type, va_list ap);
/** */
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);
int print_int(va_list ap);
int print_int_helper(int int_to_print);

#endif
