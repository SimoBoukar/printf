#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct printf_params - parameters struct
 * @unsign: flag if unsigned value
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 * @width: field width specified
 * @precision: field precision specified
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
*/

typedef struct printf_params
{
	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} spec_para;

/**
 * struct specifier - Struct of spec
 * @specifier: format of spec
 * @f: The function associated
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, spec_para *);
} speci_t;


int _puts(char *str);
int _putchar(int c);
int print_char(va_list pointer, spec_para *params);
int print_int(va_list pointer, spec_para *params);
int print_string(va_list pointer, spec_para *params);
int print_percent(va_list pointer, spec_para *params);
int print_S(va_list pointer, spec_para *params);
char *convert(long int num, int base, int flags, spec_para *params);
int print_unsigned(va_list pointer, spec_para *params);
int print_address(va_list pointer, spec_para *params);
int (*get_specifier(char *s))(va_list pointer, spec_para *params);
int get_print_func(char *s, va_list pointer, spec_para *params);
int get_flag(char *s, spec_para *params);
int get_modifier(char *s, spec_para *params);
char *get_width(char *s, spec_para *params, va_list pointer);
int print_hex(va_list pointer, spec_para *params);
int print_HEX(va_list pointer, spec_para *params);
int print_binary(va_list pointer, spec_para *params);
int print_octal(va_list pointer, spec_para *params);
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list pointer, spec_para *params);
int print_rot13(va_list pointer, spec_para *params);
int _isdigit(int c);
int _strlen(char *s);
int print_num(char *str, spec_para *params);
int print_num_right_shift(char *str, spec_para *params);
int print_num_left_shift(char *str, spec_para *params);
void init_params(spec_para *params, va_list pointer);
char *get_precision(char *p, spec_para *params, va_list pointer);
int _printf(const char *format, ...);

#endif
