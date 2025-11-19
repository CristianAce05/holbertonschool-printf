#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct to map format specifier to function
 * @symbol: The format specifier (e.g. 'c', 's', 'd')
 * @func: Pointer to the function that handles printing
 */
typedef struct specifier
{
	char symbol;
	int (*func)(va_list);
} spec_t;

/* main printf function */
int _printf(const char *format, ...);

/* handlers for each specifier */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_pointer(va_list args);

/* helper functions */
int _putchar(char c);
int print_number(long n);
int print_unsigned_number(unsigned long n);
int print_hex(unsigned long n, int uppercase);
int print_octal_number(unsigned long n);

#endif /* MAIN_H */

