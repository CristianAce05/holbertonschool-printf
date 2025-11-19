#include "main.h"
/**
 *_putchar - write the c character
 *@c: The character to print
 *
 *Return: 1 or -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1)); /**printea al output el 'c'*/
}
