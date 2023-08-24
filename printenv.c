#include "shell.h"

/**
 * printenv - Print environment variables.
 *
 * Print all environment variables to standard output.
 */

void printenv(void)
{
	char *env_var;
	char newline = '\n';
	size_t env_var_len;
	ssize_t bytes_written;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		env_var = *env;
		env_var_len = strlen(env_var);
		bytes_written = write(STDOUT_FILENO, env_var, env_var_len);

		if (bytes_written == -1)
		{
			perror("Error writing environment variable");
			exit(1);
		}

		bytes_written = write(STDOUT_FILENO, &newline, 1);

		if (bytes_written == -1)
		{
			perror("Error writing newline");
			exit(1);
		}
	}
}
