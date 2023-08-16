#include "shell.h"

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
//	_putchar('\n');
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/* make the atoi */

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
