#include "shell.h"

/* calclute the lenght of string */

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
