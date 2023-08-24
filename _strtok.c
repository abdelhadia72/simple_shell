#include "shell.h"

/**
 * _strtok - Breaks a string into tokens.
 * @str: String to tokenize.
 * @delim: Delimiter characters.
 *
 * Return: A pointer to the next token, or NULL if no more tokens.
 */

char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start;
	char *token_end;

	if (str != NULL)
	{
		next_token = str;
	}

	if (next_token == NULL)
	{
		return (NULL);
	}

	token_start = next_token;
	token_end = strpbrk(token_start, delim);

	if (token_end != NULL)
	{
		*token_end = '\0';
		next_token = token_end + 1;
	}
	else
	{
		next_token = NULL;
	}

	return (token_start);
}
