#ifndef MAIN_H
#define MAIN_H

/**
 * struct specifier - Associates a type string with a print function.
 * @type: Type identifier (e.g., "d", "i", "%").
 * @fonction: Function pointer used to print the corresponding type.
 */
typedef struct specifier
{
	char *type;
	void (*fonction)(va_list ap);
} specifier_t;

int _printf(const char *format, ...);

void print_char(va_list ap);
void print_string(va_list ap);
void print_percent(va_list ap);

#endif
