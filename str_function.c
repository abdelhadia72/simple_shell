#include "shell.h"

/* calclute the lenght of string */

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/* copie str to another */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';

	return (dest);
}
