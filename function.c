#include "shell.h"

/**
 *  _puts - print string
 *
 * @str: pointer to string
 *
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _atoi - converts string to an integer
 *
 * @nptr: string to be converted
 *
 * Return: converted integer
 */

int _atoi(char *nptr)
{
	int i = 0;
	int n = 0;

	if (nptr[i] == '+')
		i++;

	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (-1);

		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n);
}
