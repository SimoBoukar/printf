#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @end: stopping address
 * @sauf: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *end, char *sauf)
{
	int count_bytes = 0;

	while (start <= end)
	{
		if (start != sauf)
			count_bytes += _putchar(*start);
		start++;
	}
	return (count_bytes);
}

/**
 * print_rev - prints string in reverse
 * @pointer: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list pointer, spec_para *params)
{
	int length_str, count_bytes = 0;
	char *str = va_arg(pointer, char *);
	(void)params;

	if (str)
	{
	for (length_str = 0; *str; str++)
		length_str++;
	str--;
	for (; length_str > 0; length_str--, str--)
		count_bytes += _putchar(*str);
	}
	return (count_bytes);
}

/**
 * print_rot13 - prints string in rot13
 * @pointer: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list pointer, spec_para *params)
{
	int r, index_str;
	int count_bytes = 0;
	char tab[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *p = va_arg(pointer, char *);
	(void)params;

	r = 0;
	index_str = 0;
	while (tab[r])
	{
		if ((p[r] >= 'A' && p[r] <= 'Z')
		    || (p[r] >= 'a' && p[r] <= 'z'))
		{
			index_str = p[r] - 65;
			count_bytes += _putchar(tab[index_str]);
		}
		else
			count_bytes += _putchar(p[r]);
		r++;
	}
	return (count_bytes);
}
