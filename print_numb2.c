#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: parameter struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *tab;
	static char tab2[50];
	char sign = 0;
	char *ptr;
	unsigned long x = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		x = -num;
		sign = '-';
	}

	tab = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &tab2[49];
	*ptr = '\0';

	while (x != 0)
	{
		*--ptr = tab[x % base];
		x /= base;
	}

	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @pointer: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list pointer, params_t *params)
{
	unsigned long exo;

	if ((*params).l_modifier)
		exo = (unsigned long)va_arg(pointer, unsigned long);
	else if ((*params).h_modifier)
		exo = (unsigned short int)va_arg(pointer, unsigned int);
	else
		exo = (unsigned int)va_arg(pointer, unsigned int);

	(*params).unsign = 1;
	return (print_num(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 * @pointer: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list pointer, params_t *params)
{
	unsigned long int x = va_arg(pointer, unsigned long int);
	char *s;

	if (!x)
		return (_puts("(nil)"));

	s = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--s = 'x';
	*--s = '0';

	return (print_num(s, params));
}
