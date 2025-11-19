#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct fmt - Struct for format specifiers
 * @spec: The format specifier character
 * @func: The function associated with the specifier
 */
typedef struct fmt
{
	char spec;
	int (*func)(va_list);
} fmt_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif
