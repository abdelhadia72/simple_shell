#include "shell.h"

/**
 * change_dir - Change current directory.
 * @args: Array of arguments.
 *
 * Change directory based on args[1]. Handles ~, --, -.
 */

void change_dir(char **args)
{
	char oldpwd[265];
	int i;

	if (!args[1] || strcmp(args[1], "~") == 0 || strcmp(args[1], "--") == 0)
	{
		const char *home_path = getenv("HOME");

		if (home_path)
		{
			if (chdir(home_path) == -1)
				perror("cd");
		}
		else
			_puts("cd: could not determine home directory");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		const char *old_path = getenv("OLDPWD");

		if (old_path && chdir(old_path) == -1)
			perror("cd");
	}
	else
	{
		if (getcwd(oldpwd, sizeof(oldpwd)) == NULL)
			perror("getcwd");
		else
			setenv("OLDPWD", oldpwd, 1);
		if (chdir(args[1]) == -1)
			perror("cd");
	}

	for (i = 0; args[i]; ++i)
	{
		free(args[i]);
	}
	free(args);
}
