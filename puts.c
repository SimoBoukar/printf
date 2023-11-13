#include"main.h"

/**
 * puts - print string
 * @c: string to print
 * Return: num of bytes
*/

int puts_string(char *c)
{
	int counter = 0;

	if(c)
	{
		for (counter = 0; c[counter] != '\0'; counter++)
		{
			_putchar(c[counter]);
		}
	}
	return (counter);
}
