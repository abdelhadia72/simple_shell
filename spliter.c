#include "shell.h"

/**
 * spliter - Split a string into an array of tokens.
 * @buffer: The string to split.
 *
 * Return: An array of tokens, or NULL on failure.
 *
 * Description: This function takes a string @buffer and splits it into
 * tokens using the characters " \n\t" as delimiters. It returns an array
 * of tokens. Memory is allocated for the array and tokens, so it should be
 * freed after use to avoid memory leaks.
 */

char **spliter(char *buffer)
{
	char *copy_buffer = NULL;
	char *token = NULL;
	char *sp = " \n\t";
	size_t n_char = 0;
	char **argv = NULL;
	int i = 0;

	copy_buffer = strdup(buffer);
	token = _strtok(copy_buffer, sp);
	while (token != NULL)
	{
		n_char++;
		token = _strtok(NULL, sp);
	}
	n_char++;

	argv = (char **)malloc(sizeof(char *) * n_char);

	/* /! free before redup */
	free(copy_buffer);
	copy_buffer = strdup(buffer);
	token = _strtok(copy_buffer, sp);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(_strlen(token) + 1);
		_strcpy(argv[i], token);

		token = _strtok(NULL, sp);
	}
	argv[i] = NULL;

	free(copy_buffer);

	return (argv);
}
