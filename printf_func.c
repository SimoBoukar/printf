#include "main.h"

/**
 * print_char - prints character
 * @pointer: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list pointer, spec_para *params)
{
	 char ch = ' ';
	unsigned int pad = 1, count = 0, character = va_arg(pointer, int);

	if ((*params).minus_flag)
	{
		count += _putchar(character);
	}

	for (; pad < (*params).width; pad++)
	{
		count += _putchar(character);
	}

	if (!(*params).minus_flag)
	{
		count += _putchar(character);
	}

	return (count);
}

/**
 * print_int - prints integer
 * @pointer: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list pointer, spec_para *params)
{
	long count_int;

	if ((*params).l_modifier)
		count_int = va_arg(ap, long);
	else if ((*params).h_modifier)
		count_int = (short int)va_arg(pointer, int);
	else
		count_int = (int)va_arg(ap, int);
	return (print_number(convert(count_int, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @pointer: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list pointer, spec_para *params)
{
	char *strng = va_arg(pointer, char *), pad_char = ' ';
	unsigned int pad = 0, count = 0, a = 0, b;

	(void)params;
	if (!strng)
	{
		strng = NULL_STRING;
	}

	b = pad = _strlen(strng);
	if ((*params).precision < pad)
		b = pad = (*params).precision;

	if ((*params).minus_flag)
	{
		if ((*params).precision != UINT_MAX)
			for (a = 0; a < pad; a++)
				count += _putchar(*strng++);
		else
			count += _puts(strng);
	}
	while (b++ < (*params).width)
		count += _putchar(pad_char);
	if (!(*params).minus_flag)
	{
		if ((*params).precision != UINT_MAX)
			for (a = 0; a < pad; a++)
				count += _putchar(*strng++);
		else
			count += _puts(strng);
	}
	return (count);
}

/**
 * print_percent - prints string
 * @pointer: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list pointer, spec_para *params)
{
	(void)pointer;
	(void)params;

	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @pointer: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list pointer, spec_para *params)
{
	char *strng = va_arg(pointer, char *);
	char *S;
	int count = 0;

	if ((int)(!strng))
		return (_puts(NULL_STRING));
	for (; *strng; strng++)
	{
		if ((*strng > 0 && *strng < 32) || *strng >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			S = convert(*strng, 16, 0, params);
			if (!S[1])
				count += _putchar('0');
			count += _puts(S);
		}
		else
		{
			count += _putchar(*strng);
		}
	}
	return (count);
}
