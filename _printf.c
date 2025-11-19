#include "main.h"

/**
 * get_spec_func - Selects the correct printing function
 * @c: The format specifier
 *
 * Return: Pointer to function, or NULL if unknown
 */
static int (*get_spec_func(char c))(va_list)
{
	int i;
	spec_t specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'p', print_pointer},
		{'\0', NULL}
	};

	for (i = 0; specs[i].symbol != '\0'; i++)
	{
		if (specs[i].symbol == c)
			return (specs[i].func);
	}
	return (NULL);
}

/**
 * _printf - Custom printf function
 * @format: The format string containing directives
 *
 * Return: Number of characters printed,
 *         or -1 if format is NULL or an error occurs
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			func = get_spec_func(format[i]);
			if (func != NULL)
				count += func(args);
			else
			{
				/* print unknown specifier exactly like printf: "%r" → "%r" */
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
