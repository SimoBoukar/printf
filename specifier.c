#include "main.h"

/**
 * get_specifier - finds the format function
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list pointer, spec_para * params)
{
	speci_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == *(specifiers[i].specifier))
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @pointer: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list pointer, spec_para *params)
{
	int (*f)(va_list, spec_para *) = get_specifier(s);

	if (f)
		return (f(pointer, params));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, spec_para *params)
{
	int count = 0;

	if (*s == '+')
	{
		count = (*params).plus_flag = 1;
	}
	else if (*s == ' ')
	{
		count = (*params).space_flag = 1;
	}
	else if (*s == '#')
	{
		count = (*params).hashtag_flag = 1;
	}
	else if (*s == '-')
	{
		count = (*params).minus_flag = 1;
	}
	else if (*s == '0')
	{
		count = (*params).zero_flag = 1;
	}

	return (count);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, spec_para *params)
{
	int count = 0;

	switch (*s)
	{
	case 'h':
		count = (*params).h_modifier = 1;
		break;
	case 'l':
		count = (*params).l_modifier = 1;
		break;
	}
	return (count);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @pointer: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, spec_para *params, va_list pointer)
{
	int i = 0;

	if (*s == '*')
	{
		i = va_arg(pointer, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	(*params).width = i;
	return (s);
}

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @pointer: the argument pointer
 * Return: new pointer
 */

char *get_precision(char *p, spec_para *params, va_list pointer)
{
	int i = 0;

	if (*p != '.')
		return (p);
	p++;

	if (*p == '*')
	{
		i = va_arg(pointer, int);
		p++;
	}
	else
	{
	while (_isdigit(*p))

	i = i * 10 + (*p++ - '0');
	}
	(*params).precision = i;
	return (p);
}
