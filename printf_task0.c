#include"main.h"

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * ...: number of args
 * Return: character
*/

int _printf(const char *format, ...)
{
	unsigned int i, string_counter = 0, counter = 0;

	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
		_putchar(format[i]);
		}
		else if (format[i + 1] == 'c')
	{
		_putchar(va_arg(args, int));
		i++;
	}
		else if (format[i + 1] == 's')
		{
			string_counter = puts_string(va_arg(args, char *));
			i++;
			counter = (string_counter - 1);
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
		}
		counter += 1;
	}
	va_end(args);
	return (counter);
}
