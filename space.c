#include "shell.h"

/**
 * space_check - Check if a string is composed of whitespace characters.
 *
 * @buffer: The input string to be checked.
 *
 * Return: Always returns 0.
 */

int space_check(char *buffer)
{
	while (*buffer)
	{
		if (*buffer != ' ' && *buffer != '\n' && *buffer != '\t')
		{
			return (0);
		}
		buffer++;
	}
	return (1);
}
