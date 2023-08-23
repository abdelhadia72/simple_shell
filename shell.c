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
	char **args = NULL;
	size_t size = 0;

	(void)ac;
	(void)av;

	if (isatty(STDIN_FILENO))
	{
		_puts("$ ");
	}

	while (1)
	{
		ssize_t chars_read = getline(&buffer, &size, stdin);

		if (chars_read == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				free(buffer);
			}
			exit(SUCCESS);
		}

		buffer[chars_read - 1] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(SUCCESS);
		}

		if (!space_check(buffer))
		{
			args = spliter(buffer);

			if (args[0] != NULL)
			{
				if (strcmp(args[0], "cd") == 0)
				{
					change_dir(args);
				}
				else
				{
					runcmd(args);
				}
			}

			for (int i = 0; args && args[i]; i++)
			{
				free(args[i]);
			}
			free(args);
		}

		if (isatty(STDIN_FILENO))
		{
			_puts("$ ");
		}
	}

	free(buffer);
	return 0;
}