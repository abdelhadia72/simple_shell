#include "shell.h"
#include <ctype.h>

/**
 * rm_spaces - Remove leading and trailing spaces from a string.
 * @str: The string to process.
 *
 * Return: A pointer to the processed string.
 *
 * Description: This function removes leading and trailing spaces from
 * the input string @str. If @str is all spaces, the result will be an
 * empty string. The original memory is modified in place.
 */

char *rm_spaces(char *str)
{
	size_t i;
	size_t len;
	size_t start;
	size_t end;

	if (str == NULL)
		return NULL;

	len = strlen(str);
	start = 0;
	end = len - 1;

	while (isspace((unsigned char)str[start]))
	{
		start++;
	}

	if (start == len)
	{
		str[0] = '\0';
		return str;
	}

	while (end > start && isspace((unsigned char)str[end]))
	{
		end--;
	}

	for (i = start; i <= end; i++)
	{
		str[i - start] = str[i];
	}

	str[end - start + 1] = '\0';

	return str;
}
