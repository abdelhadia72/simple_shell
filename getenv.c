#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: Pointer to the value, or NULL if not found.
 *
 * Retrieves the value of the environment variable @name.
 */

char *_getenv(const char *name)
{
	int i = 0;
	ssize_t len = _strlen(name);

	for (; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
	}
	return (NULL);
}
