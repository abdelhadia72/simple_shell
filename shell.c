#include "shell.h"

/**
 * main - Entry point for the custom shell program.
 *
 * @ac: Number of command-line arguments.
 * @av: Array of command-line argument strings.
 *
 * Return: Always returns 0.
 */

int main(int ac, char **av)
{
	char *buffer = NULL;
	char **args = {NULL};
	size_t size = 0;

	(void)ac;
	(void)av;

	if (isatty(0))
	{
		_puts("$ ");
	}
	while (_getline(&buffer, &size, stdin) != EOF)
	{
		buffer[_strlen(buffer) - 1] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(2);
			break;
		}
		if (!space_check(buffer))
		{
			args = spliter(buffer);
			if (strcmp(args[0], "env") == 0)
			{
				printenv();
			}
			else if (strcmp(args[0], "cd") == 0)
				change_dir(args);
			else
				runcmd(args);
		}
		else
		{
			/*printf("%s\n", buffer);*/
		}

		if (isatty(0))
			_puts("$ ");
	}

	free(buffer);
	return (0);
}
