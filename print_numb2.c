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
char *convert(long int num, int base, int flags, spec_para *params)
{
	static char *tab;
	static char tab2[50];
	char sign = 0;
	char *ptr;
	unsigned long a = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		a = -num;
		sign = '-';
	}

	tab = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &tab2[49];
	*ptr = '\0';

	do	{
		*--ptr = tab[a % base];
		a /= base;
	} while (a != 0)

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
int print_unsigned(va_list pointer, spec_para *params)
{
	unsigned long exo;

	if ((*params).l_modifier)
		exo = (unsigned long)va_arg(pointer, unsigned long);
	else if ((*params).h_modifier)
		exo = (unsigned short int)va_arg(pointer, unsigned int);
	else
		exo = (unsigned int)va_arg(pointer, unsigned int);

	(*params).unsign = 1;
	return (print_num(convert(exo, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 * @pointer: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list pointer, spec_para *params)
{
	unsigned long int i = va_arg(pointer, unsigned long int);
	char *str_add;

	if (!i)
		return (_puts("(nil)"));

	str_add = convert(i, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str_add = 'x';
	*--str_add = '0';

	return (print_num(str_add, params));
}
