#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int count_bytes = 0;
	va_list pointer;
	char *i, *start;
	spec_para para = PARAMS_INIT;

	va_start(pointer, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = (char *)format; *i; i++)
		{
		init_params(&para, pointer);
		if (*i != '%')
		{
		count_bytes += _putchar(*i);
		continue;
		}
	start = i;
	i++;
		while (get_flag(i, &para))
		{
		i++;
		}
	i = get_width(i, &para, pointer);
	i = get_precision(i, &para, pointer);
		if (get_modifier(i, &para))
			i++;
		if (!get_specifier(i))
			count_bytes += print_from_to(start, i,
			para.l_modifier || para.h_modifier ? i - 1 : 0);
		else
			count_bytes += get_print_func(i, pointer, &para);
	}
	_putchar(BUF_FLUSH);
	va_end(pointer);
return (count_bytes);
}
