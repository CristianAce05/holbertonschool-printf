#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a char
 * @args: argument list
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_percent - prints a percent sign
 * @args: unused
 * Return: 1
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

/**
 * print_int - prints integers (%d and %i)
 * @args: argument list
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += print_int_helper(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * print_int_helper - recursive integer printer
 * @num: positive number
 * Return: number of digits printed
 */
int print_int_helper(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += print_int_helper(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}
