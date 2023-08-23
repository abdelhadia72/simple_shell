#include "shell.h"

char *which(char *cmd)
{
	char *path = NULL;
	char *token = NULL;
	char *cp_cmd = NULL;
	char *sp = ":";
	char *holder = NULL;

	if (!cmd)
		return NULL;

	path = getenv("PATH");
	if (!path)
	{
		return NULL;
	}

	cp_cmd = strdup(cmd);
	token = _strtok(path, sp);

	while (token)
	{
		holder = (char *)malloc(_strlen(token) + _strlen(cmd) + 2);
		_strcpy(holder, token);
		_strcat(holder, "/");
		_strcat(holder, cmd);
		if (access(holder, X_OK) == 0)
		{

			free(cp_cmd);
			return (holder);
		}

		free(holder);
		token = _strtok(NULL, sp);
	}

	free(cp_cmd);
	/* perror("which"); */
	return (NULL);
}
