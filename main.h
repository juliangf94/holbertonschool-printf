#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct specifier - Associates a type string with a print function.
 * @type: Type identifier (e.g., "d", "i", "%").
 * @function: Function pointer used to print the corresponding type.
 */
typedef struct specifier
{
	char type;
	int (*function)(va_list args);
} specifier_t;

int _putchar(char c);

int _printf(const char *format, ...);
int select_type(char type, va_list args);
/** print_helper.c */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_int_helper(unsigned int int_to_print);
/** print_helper_2.c */
int print_unsigned_int(va_list args);

#endif
