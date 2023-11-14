#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int y = 0;

	while (*s++)
		y++;
	return (y);
}

/**
 * print_num - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_num(char *str, spec_para *params)
{
	unsigned int i = _strlen(str);
	int numb = (!(*params).unsign && *str == '-');

	if (!(*params).precision && *str == '0' && !str[1])
		str = "";

	if (numb)
	{
		str++;
		i--;
	}

	if ((*params).precision != UINT_MAX)
	{
		while (i < (*params).precision)
		{
			*--str = '0';
			i++;
		}
	}

	if (numb)
	{
		*--str = '-';
	}

	if (!(*params).minus_flag)
	{
		return (print_number_right_shift(str, params));
	}
	else
	{
		return (print_number_left_shift(str, params));
	}
}
/**
 * print_num_right_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_num_right_shift(char *str, params_t *params)
{
	unsigned int x = 0, numb, numb2, y = _strlen(str);
	char line_ch = ' ';

	if (params->zero_flag && !params->minus_flag)
		line_ch = '0';

	numb = numb2 = (!params->unsign && *str == '-');

	if (numb && x < params->width && line_ch == '0' && !params->minus_flag)
		str++;
	else
		numb = 0;

	if ((params->plus_flag && !numb2) ||
		(!params->plus_flag && params->space_flag && !numb2))
		y++;

	if (numb && line_ch == '0')
		x += _putchar('-');

	if (params->plus_flag && !numb2 && line_ch == '0' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !numb2 &&
			 !params->unsign && params->zero_flag)
		x += _putchar(' ');

	while (y++ < params->width)
		x += _putchar(line_ch);

	if (numb && line_ch == ' ')
		x += _putchar('-');

	if (params->plus_flag && !numb2 && line_ch == ' ' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !numb2 &&
			 !params->unsign && !params->zero_flag)
		x += _putchar(' ');

	x += _puts(str);
	return (x);
}
/**
 * print_num_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_num_left_shift(char *str, params_t *params)
{
	unsigned int x = 0, numb, numb2, y = _strlen(str);
	char line_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		line_char = '0';

	numb = numb2 = (!params->unsign && *str == '-');

	if (numb && x < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		numb = 0;

	if (params->plus_flag && !numb2 && !params->unsign)
		x += _putchar('+'), y++;
	else if (params->space_flag && !numb2 && !params->unsign)
		x += _putchar(' '), y++;

	x += _puts(str);

	while (y++ < params->width)
		x += _putchar(line_char);

	return (x);
}
