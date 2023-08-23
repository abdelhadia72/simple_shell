#include "shell.h"

char *_getenv(char *name)
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
