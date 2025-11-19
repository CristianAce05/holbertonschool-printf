#include "main.h"

/**
 * _printf - simplified printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, count = 0;
	fmt_t specifiers[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'d', print_int},
		{'i', print_int}, {'\0', NULL}};

	if (!format)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			for (j = 0; specifiers[j].spec; j++)
				if (format[i] == specifiers[j].spec)
				{
					count += specifiers[j].func(args);
					break;
				}
			if (!specifiers[j].spec)
				count += _putchar('%'), count += _putchar(format[i]);
		}
		else
			count += _putchar(format[i]);
	}
	va_end(args);
	return (count);
}
