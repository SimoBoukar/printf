#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *count_string = str;

	while (*str)
	_putchar(*str++);

	return (str - count_string);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char tmp[OUTPUT_BUF_SIZE];

	(c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE) ? (write(1, tmp, i), i = 0) : 0;

	(c != BUF_FLUSH) ? tmp[i++] = c : 0;

	return (1);
}
