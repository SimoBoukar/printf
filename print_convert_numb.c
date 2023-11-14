#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @pointer: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list pointer, spec_para *params)
{
	unsigned long hexa;
	int i = 0;
	char *str;

	if ((*params).l_modifier)
		hexa = (unsigned long)va_arg(pointer, unsigned long);
	else if ((*params).h_modifier)
		hexa = (unsigned short int)va_arg(pointer, unsigned int);
	else
		hexa = (unsigned int)va_arg(pointer, unsigned int);

	str = convert(hexa, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);

	if ((*params).hashtag_flag && hexa)
	{
		*--str = 'x';
		*--str = '0';
	}

	(*params).unsign = 1;
	return (i += print_num(str, params));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @pointer: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list pointer, spec_para *params)
{
	unsigned long HEXA;
	int x = 0;
	char *str;

	if ((*params).l_modifier)
		HEXA = (unsigned long)va_arg(pointer, unsigned long);
	else if (params->h_modifier)
		HEXA = (unsigned short int)va_arg(pointer, unsigned int);
	else
		HEXA = (unsigned int)va_arg(pointer, unsigned int);

	str = convert(HEXA, 16, CONVERT_UNSIGNED, params);

	if ((*params).hashtag_flag && HEXA)
	{
		*--str = 'X';
		*--str = '0';
	}

	params->unsign = 1;
	return (x += print_num(str, params));
}

/**
 * print_binary - prints unsigned binary number
 * @pointer: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list pointer, spec_para *params)
{
	unsigned int n = va_arg(pointer, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int y = 0;

	if ((*params).hashtag_flag && n)
		*--str = '0';

	(*params).unsign = 1;
	return (y += print_num(str, params));
}

/**
 * print_octal - prints unsigned octal numbers
 * @pointer: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list pointer, spec_para *params)
{
	unsigned long octa;
	char *str;
	int z = 0;

	if ((*params).l_modifier)
		octa = (unsigned long)va_arg(pointer, unsigned long);
	else if (params->h_modifier)
		octa = (unsigned short int)va_arg(pointer, unsigned int);
	else
		octa = (unsigned int)va_arg(pointer, unsigned int);

	str = convert(octa, 8, CONVERT_UNSIGNED, params);

	if ((*params).hashtag_flag && octa)
		*--str = '0';

	(*params).unsign = 1;
	return (z += print_num(str, params));
}

