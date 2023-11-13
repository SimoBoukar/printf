#include"main.h"

/**
 * _putchar - write the character c
 * @c: the character to print
 * Return: 1 on sucess, on error, -1 is returned, and error
 * is set appropriately
 *
*/

int _putchar(char c)
{
	return ( write(1, &c, 1));
}
